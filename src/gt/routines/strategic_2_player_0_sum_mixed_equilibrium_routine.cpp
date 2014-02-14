/**
 * @file      gt/routines/strategic_2_player_0_sum_mixed_equilibrium_routine.cpp
 * @brief     Defines GT::Routines::Strategic2Player0SumMixedEquilibriumRoutine methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::unique_ptr;

using boost::dynamic_pointer_cast;

using Model::DataPiecePtr;
using Model::Player;
using Model::PlayerPtr;
using Model::Players;
using Model::PlayersPtr;
using Model::StrategicDataAccessor;
using Model::StrategicDataAccessorPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Strategic2Player0SumMixedEquilibriumRoutine final : public Routine {
// public:

ResultPtr Strategic2Player0SumMixedEquilibriumRoutine::findResultFor(
    const GamePtr       game,
    const ConditionsPtr
) const {
    const StrategicDataAccessorPtr data    = dynamic_pointer_cast<StrategicDataAccessor>(game->getData());
    const Players&                 players = *data->getPlayers();
    if (!data || players.size() != 2) {
        static Identifier strategicGameName("0-sum Strategic Game with 2 players");
        throw ExceptionFactory::getInstance().invalidGameType(strategicGameName);
    }

    const StrategicGamePositionsHelper positionsHelper(data->getPlayers());
    LPProblemPtr                       problemPtr = initializeProblem(players);
    LPProblem*                         problem    = problemPtr.get();

    fillUpProblem(problem, *data, positionsHelper);

    return solveProblem(problem, *data, positionsHelper);
}

Message Strategic2Player0SumMixedEquilibriumRoutine::toString() const {
    return Message("Strategic2Player0SumMixedEquilibriumRoutine");
}

// private:

LPProblemPtr Strategic2Player0SumMixedEquilibriumRoutine::initializeProblem(
    const Players& players
) const {
    const Player& player1 = *( players.begin()->second );
    const Player& player2 = *( (++players.begin())->second );

    LPProblemPtr problemPtr = createLPProblem();
    LPProblem*   problem(problemPtr.get());

    glp_set_prob_name( problem, "2 player 0-sum strategic form game" );
    glp_set_obj_dir(   problem, GLP_MAX );

    glp_add_cols(problem, player2.getStrategiesNumber());
    for (const IdentifierPtr& player2Strategy : *player2.getStrategies()) {
        int j = player2.getStrategyOrdinal(*player2Strategy) + 1;
        glp_set_col_name(problem, j, player2Strategy->c_str());
        glp_set_col_bnds(problem, j, GLP_LO, 0.0, 0.0);
        glp_set_obj_coef(problem, j, 1.0);
    }

    glp_add_rows(problem, player1.getStrategiesNumber());
    for (const IdentifierPtr& player1Strategy : *player1.getStrategies()) {
        int i = player1.getStrategyOrdinal(*player1Strategy) + 1;
        glp_set_row_name(problem, i, player1Strategy->c_str());
        glp_set_row_bnds(problem, i, GLP_UP, 0.0, 1.0);
    }

    return problemPtr;
}

void Strategic2Player0SumMixedEquilibriumRoutine::fillUpProblem(
    LPProblem*                          problem,
    const StrategicDataAccessor&        data,
    const StrategicGamePositionsHelper& positionsHelper
) const {
    const Player&     player1     = *( positionsHelper.getPlayers()->begin()->second );
    const Player&     player2     = *( (++positionsHelper.getPlayers()->begin())->second );
    const Identifier& player1Name = *( player1.getName() );
    const Identifier& player2Name = *( player2.getName() );
    const Index       upperBound  = positionsHelper.getUpperBound();

    vector<int>     player1Strategies(upperBound+1);
    vector<int>     player2Strategies(upperBound+1);
    vector<double>  payoff(upperBound+1);

    for (Index k = 0; k < upperBound; k++) {
        const PositionsPtr positions       = positionsHelper.retrievePositions(k);
        const Identifier&  player1Strategy = positions->at(player1Name);
        const Identifier&  player2Strategy = positions->at(player2Name);
        // change 0-indexing used in Model to 1-indexing used in GLPK
        const Index        player1Ordinal  = player1.getStrategyOrdinal(player1Strategy) + 1;
        const Index        player2Ordinal  = player2.getStrategyOrdinal(player2Strategy) + 1;
        const double       player1Payoff   = data[positions]->getPayoff(player1Name)->get_d();

        // GLPK uses 1 indeksing also in data arrays
        player1Strategies[k+1] = player1Ordinal;
        player2Strategies[k+1] = player2Ordinal;
        payoff[k+1]            = player1Payoff; // figure out GMP with GLPK
    }

    // vectors uses contignous memory - &x[0] "transforms" it into a C-style array
    glp_load_matrix(problem, upperBound, &player1Strategies[0], &player2Strategies[0], &payoff[0]);
}

ResultPtr Strategic2Player0SumMixedEquilibriumRoutine::solveProblem(
    LPProblem*                          problem,
    const StrategicDataAccessor&        data,
    const StrategicGamePositionsHelper& positionsHelper
) const {
    typedef map<Identifier, double> DistributionMap;

    glp_smcp parm;
    glp_init_smcp(&parm);
    parm.msg_lev = GLP_MSG_OFF;

    if (glp_simplex(problem, &parm) != 0 ||
        glp_get_prim_stat(problem) != GLP_FEAS || glp_get_dual_stat(problem) != GLP_FEAS) {
        // TODO: create MessageFactory
        return ResultFactory::getInstance().constResult(Message("Failed to calculate the solution"));
    }

    double distributionFactor = glp_get_obj_val(problem);

    const Player&     player1       = *( positionsHelper.getPlayers()->begin()->second );
    const Identifier& player1Name   = *( player1.getName() );
    DistributionMap   player1Distribution;
    for (const IdentifierPtr& strategy : *player1.getStrategies()) {
        // change 0-indexing used in Model to 1-indexing used in GLPK
        Index strategyOrdinal = player1.getStrategyOrdinal(*strategy) + 1;
        double probability    = glp_get_row_dual(problem, strategyOrdinal) / distributionFactor;

        player1Distribution.insert( DistributionMap::value_type(*strategy, probability) );
    }

    const Player&     player2     = *( (++positionsHelper.getPlayers()->begin())->second );
    const Identifier& player2Name = *( player2.getName() );
    DistributionMap   player2Distribution;
    for (const IdentifierPtr& strategy : *player2.getStrategies()) {
        // change 0-indexing used in Model to 1-indexing used in GLPK
        Index strategyOrdinal = player2.getStrategyOrdinal(*strategy) + 1;
        double probability    = glp_get_col_prim(problem, strategyOrdinal) / distributionFactor;

        player2Distribution.insert( DistributionMap::value_type(*strategy, probability) );
    }

    double player1Payoff = 0.0;
    for (const IdentifierPtr& player1Strategy : *player1.getStrategies()) {
        for (const IdentifierPtr& player2Strategy : *player2.getStrategies()) {
            Positions positions;
            positions.insert( Positions::value_type(player1Name, *player1Strategy) );
            positions.insert( Positions::value_type(player2Name, *player2Strategy) );

            player1Payoff += data[positions]->getPayoff(player1Name)->get_d() *
                             player1Distribution[*player1Strategy] *
                             player2Distribution[*player2Strategy];
        }
    }
    double player2Payoff = -player1Payoff;

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();


    ResultBuilderPtr player1DistributionResult = ResultFactory::getInstance().buildResult();
    for (const IdentifierPtr& player1Strategy : *player1.getStrategies()) {
        const MessagePtr& probability  = createMessagePtr(player1Distribution[*player1Strategy]);
        player1DistributionResult->addResult( player1Strategy, probability );
    }
    ResultBuilderPtr player2DistributionResult = ResultFactory::getInstance().buildResult();
    for (const IdentifierPtr& player2Strategy : *player2.getStrategies()) {
        const MessagePtr& probability  = createMessagePtr(player2Distribution[*player2Strategy]);
        player2DistributionResult->addResult( player2Strategy, probability );
    }

    ResultBuilderPtr mixedStrategiesResult = ResultFactory::getInstance().buildResult();
    mixedStrategiesResult->addResult(
        player1.getName(),
        createMessagePtr( player1DistributionResult->build()->getResult() )
    );
    mixedStrategiesResult->addResult(
        player2.getName(),
        createMessagePtr( player2DistributionResult->build()->getResult() )
    );
    const MessagePtr mixedStrategies = createMessagePtr(mixedStrategiesResult->build()->getResult());

    static const IdentifierPtr mixedStrategiesName = createIdentifierPtr("Mixed Strategies");
    resultBuilder->addResult( mixedStrategiesName, mixedStrategies );

    static const IdentifierPtr payoffName = createIdentifierPtr("Payoff");
    ResultBuilderPtr payoffResult = ResultFactory::getInstance().buildResult();

    IdentifiersPtr   headers      = createIdentifiersPtr();
    headers->push_back( player1.getName() );
    headers->push_back( player2.getName() );
    payoffResult->setHeaders( headers );

    MessagesPtr payoffs = createMessagesPtr();
    payoffs->push_back( createMessagePtr(player1Payoff) );
    payoffs->push_back( createMessagePtr(player2Payoff) );
    payoffResult->addRecord( payoffName, payoffs );

    resultBuilder->addResult( payoffName, createMessagePtr(payoffResult->build()->getResult()) );

    return resultBuilder->build();
}

// }; /* END class Strategic2Player0SumMixedEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
