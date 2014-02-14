/**
 * @file      gt/routines/strategic_2_player_mixed_equilibrium_routine.cpp
 * @brief     Defines GT::Routines::Strategic2PlayerMixedEquilibriumRoutine methods.
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

using std::atexit;
using std::numeric_limits;
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

// class Strategic2PlayerMixedEquilibriumRoutine final : public Routine {
// public:

ResultPtr Strategic2PlayerMixedEquilibriumRoutine::findResultFor(
    const GamePtr       game,
    const ConditionsPtr
) const {
    const StrategicDataAccessorPtr data    = dynamic_pointer_cast<StrategicDataAccessor>(game->getData());
    const Players&                 players = *data->getPlayers();
    if (!data || players.size() != 2) {
        static Identifier strategicGameName("Strategic Game with 2 players");
        throw ExceptionFactory::getInstance().invalidGameType(strategicGameName);
    }

    const StrategicGamePositionsHelper positionsHelper(data->getPlayers());
    LPProblemPtr                       problemPtr = initializeProblem(players);
    LPProblem*                         problem    = problemPtr.get();

    fillUpProblem(problem, *data, positionsHelper);

    return solveProblem(problem, *data, positionsHelper);
}

Message Strategic2PlayerMixedEquilibriumRoutine::toString() const {
    return Message("Strategic2PlayerMixedEquilibriumRoutine");
}

// private:

LPProblemPtr Strategic2PlayerMixedEquilibriumRoutine::initializeProblem(
    const Players& players
) const {
    const Player& player1 = *( players.begin()->second );
    const Player& player2 = *( (++players.begin())->second );

    const int b1ColStart  = 1;
    const int b2ColStart  = b1ColStart  + player1.getStrategiesNumber();
    const int p1ColStart  = b2ColStart  + player2.getStrategiesNumber();
    const int p2ColStart  = p1ColStart  + player1.getStrategiesNumber();
    const int u1sColStart = p2ColStart  + player2.getStrategiesNumber();
    const int u2sColStart = u1sColStart + player1.getStrategiesNumber();
    const int u1Col       = u2sColStart + player2.getStrategiesNumber();
    const int u2Col       = u1Col       + 1;
    const int r1ColStart  = u2Col       + 1;
    const int r2ColStart  = r1ColStart  + player1.getStrategiesNumber();
    const int colsNumber  = r2ColStart  + player2.getStrategiesNumber() - 1;

    const int p1Row        = 1;
    const int p2Row        = p1Row        + 1;
    const int u1RowStart   = p2Row        + 1;
    const int u2RowStart   = u1RowStart   + player1.getStrategiesNumber();
    const int max1RowStart = u2RowStart   + player2.getStrategiesNumber();
    const int max2RowStart = max1RowStart + player1.getStrategiesNumber();
    const int r1RowStart   = max2RowStart + player2.getStrategiesNumber();
    const int r2RowStart   = r1RowStart   + player1.getStrategiesNumber();
    const int pb1RowStart  = r2RowStart   + player2.getStrategiesNumber();
    const int pb2RowStart  = pb1RowStart  + player1.getStrategiesNumber();
    const int rm1RowStart  = pb2RowStart  + player2.getStrategiesNumber();
    const int rm2RowStart  = rm1RowStart  + player1.getStrategiesNumber();
    const int rowsNumber   = rm2RowStart  + player2.getStrategiesNumber() - 1;

    LPProblemPtr problemPtr = createLPProblem();
    LPProblem*   problem(problemPtr.get());

    glp_set_prob_name( problem, "2 player strategic form game" );
    glp_set_obj_dir(   problem, GLP_MIN );

    glp_set_obj_name(problem, "AvarageRegret");
    glp_add_cols(problem, colsNumber);
    glp_set_col_name(problem, u1Col,        "u1");
    glp_set_col_bnds(problem, u1Col,        GLP_LO, 0.0, 0.0);
    glp_set_col_name(problem, u2Col,        "u2");
    glp_set_col_bnds(problem, u2Col,        GLP_LO, 0.0, 0.0);
    glp_add_rows(problem, rowsNumber);
    glp_set_row_name(problem, p1Row,        "Probabilites1");
    glp_set_row_bnds(problem, p1Row,        GLP_FX, 1.0, 1.0);
    glp_set_row_name(problem, p2Row,        "Probabilites2");
    glp_set_row_bnds(problem, p2Row,        GLP_FX, 1.0, 1.0);
    for (const IdentifierPtr& player1Strategy : *player1.getStrategies()) {
        int i = player1.getStrategyOrdinal(*player1Strategy);

        glp_set_obj_coef(problem, r1ColStart   + i, 1.0);

        glp_set_col_name(problem, b1ColStart   + i, "b1s");
        glp_set_col_kind(problem, b1ColStart   + i, GLP_BV);
        glp_set_col_name(problem, p1ColStart   + i, "p1s");
        glp_set_col_bnds(problem, p1ColStart   + i, GLP_DB, 0.0, 1.0);
        glp_set_col_name(problem, u1sColStart  + i, "u1s");
        glp_set_col_bnds(problem, u1sColStart  + i, GLP_LO, 0.0, 0.0);
        glp_set_col_name(problem, r1ColStart   + i, "r1s");
        glp_set_col_bnds(problem, r1ColStart   + i, GLP_LO, 0.0, 0.0);

        glp_set_row_name(problem, u1RowStart   + i, "UtilitiesValue1");
        glp_set_row_bnds(problem, u1RowStart   + i, GLP_FX, -0.0, -0.0);
        glp_set_row_name(problem, max1RowStart + i, "MaxUtilities1");
        glp_set_row_bnds(problem, max1RowStart + i, GLP_LO, -0.0, -0.0);
        glp_set_row_name(problem, r1RowStart   + i, "Regret1");
        glp_set_row_bnds(problem, r1RowStart   + i, GLP_FX, -0.0, -0.0);
        glp_set_row_name(problem, pb1RowStart  + i, "Probability1");
        glp_set_row_bnds(problem, pb1RowStart  + i, GLP_UP, 1.0, 1.0);
        glp_set_row_name(problem, rm1RowStart  + i, "RegretAndMax1");
        glp_set_row_bnds(problem, rm1RowStart  + i, GLP_UP, -0.0, -0.0);
    }
    for (const IdentifierPtr& player2Strategy : *player2.getStrategies()) {
        int j = player2.getStrategyOrdinal(*player2Strategy);

        glp_set_obj_coef(problem, r2ColStart   + j, 1.0);

        glp_set_col_name(problem, b2ColStart   + j, "b2s");
        glp_set_col_kind(problem, b2ColStart   + j, GLP_BV);
        glp_set_col_name(problem, p2ColStart   + j, "p2s");
        glp_set_col_bnds(problem, p2ColStart   + j, GLP_DB, 0.0, 1.0);
        glp_set_col_name(problem, u2sColStart  + j, "u2s");
        glp_set_col_bnds(problem, u2sColStart  + j, GLP_LO, 0.0, 0.0);
        glp_set_col_name(problem, r2ColStart   + j, "r2s");
        glp_set_col_bnds(problem, r2ColStart   + j, GLP_LO, 0.0, 0.0);

        glp_set_row_name(problem, u2RowStart   + j, "UtilitiesValue2");
        glp_set_row_bnds(problem, u2RowStart   + j, GLP_FX, -0.0, -0.0);
        glp_set_row_name(problem, max2RowStart + j, "MaxUtilities2");
        glp_set_row_bnds(problem, max2RowStart + j, GLP_LO, -0.0, -0.0);
        glp_set_row_name(problem, r2RowStart   + j, "Regret2");
        glp_set_row_bnds(problem, r2RowStart   + j, GLP_FX, -0.0, -0.0);
        glp_set_row_name(problem, pb2RowStart  + j, "Probability2");
        glp_set_row_bnds(problem, pb2RowStart  + j, GLP_UP, 1.0, 1.0);
        glp_set_row_name(problem, rm2RowStart  + j, "RegretAndMax2");
        glp_set_row_bnds(problem, rm2RowStart  + j, GLP_UP, -0.0, -0.0);
    }

    return problemPtr;
}

void Strategic2PlayerMixedEquilibriumRoutine::fillUpProblem(
    LPProblem*                          problem,
    const StrategicDataAccessor&        data,
    const StrategicGamePositionsHelper& positionsHelper
) const {
    const Player&     player1     = *( positionsHelper.getPlayers()->begin()->second );
    const Player&     player2     = *( (++positionsHelper.getPlayers()->begin())->second );
    const Identifier& player1Name = *( player1.getName() );
    const Identifier& player2Name = *( player2.getName() );
    const Index       upperBound  = positionsHelper.getUpperBound();

    const int b1ColStart  = 1;
    const int b2ColStart  = b1ColStart  + player1.getStrategiesNumber();
    const int p1ColStart  = b2ColStart  + player2.getStrategiesNumber();
    const int p2ColStart  = p1ColStart  + player1.getStrategiesNumber();
    const int u1sColStart = p2ColStart  + player2.getStrategiesNumber();
    const int u2sColStart = u1sColStart + player1.getStrategiesNumber();
    const int u1Col       = u2sColStart + player2.getStrategiesNumber();
    const int u2Col       = u1Col       + 1;
    const int r1ColStart  = u2Col       + 1;
    const int r2ColStart  = r1ColStart  + player1.getStrategiesNumber();

    const int p1Row        = 1;
    const int p2Row        = p1Row        + 1;
    const int u1RowStart   = p2Row        + 1;
    const int u2RowStart   = u1RowStart   + player1.getStrategiesNumber();
    const int max1RowStart = u2RowStart   + player2.getStrategiesNumber();
    const int max2RowStart = max1RowStart + player1.getStrategiesNumber();
    const int r1RowStart   = max2RowStart + player2.getStrategiesNumber();
    const int r2RowStart   = r1RowStart   + player1.getStrategiesNumber();
    const int pb1RowStart  = r2RowStart   + player2.getStrategiesNumber();
    const int pb2RowStart  = pb1RowStart  + player1.getStrategiesNumber();
    const int rm1RowStart  = pb2RowStart  + player2.getStrategiesNumber();
    const int rm2RowStart  = rm1RowStart  + player1.getStrategiesNumber();

    vector<int>     rows;
    vector<int>     cols;
    vector<double>  values;
    rows.push_back(0);
    cols.push_back(0);
    values.push_back(0.0);

    double p1Min = numeric_limits<double>::max();
    double p1Max = numeric_limits<double>::min();
    double p2Min = numeric_limits<double>::max();
    double p2Max = numeric_limits<double>::min();
    for (Index k = 0; k < upperBound; k++) {
        const PositionsPtr positions       = positionsHelper.retrievePositions(k);
        const Identifier&  player1Strategy = positions->at(player1Name);
        const Identifier&  player2Strategy = positions->at(player2Name);
        const Index        i               = player1.getStrategyOrdinal(player1Strategy);
        const Index        j               = player2.getStrategyOrdinal(player2Strategy);
        const double       player1Payoff   = data[positions]->getPayoff(player1Name)->get_d();
        const double       player2Payoff   = data[positions]->getPayoff(player2Name)->get_d();

        if (p1Min > player1Payoff) p1Min = player1Payoff;
        if (p1Max < player1Payoff) p1Max = player1Payoff;
        if (p2Min > player2Payoff) p2Min = player2Payoff;
        if (p2Max < player2Payoff) p2Max = player2Payoff;

        rows.push_back(u1RowStart + i);
        cols.push_back(p2ColStart + j);
        values.push_back(-player1Payoff);

        rows.push_back(u2RowStart + j);
        cols.push_back(p1ColStart + i);
        values.push_back(-player2Payoff);
    }

    double U1 = p1Max - p1Min;
    double U2 = p2Max - p2Min;

    for (const IdentifierPtr& player1Strategy : *player1.getStrategies()) {
        int i = player1.getStrategyOrdinal(*player1Strategy);

        rows.push_back(p1Row);
        cols.push_back(p1ColStart + i);
        values.push_back(1.0);

        rows.push_back(u1RowStart + i);
        cols.push_back(u1sColStart + i);
        values.push_back(1.0);

        rows.push_back(max1RowStart + i);
        cols.push_back(u1sColStart + i);
        values.push_back(-1.0);

        rows.push_back(max1RowStart + i);
        cols.push_back(u1Col);
        values.push_back(1.0);

        rows.push_back(r1RowStart + i);
        cols.push_back(u1sColStart + i);
        values.push_back(1.0);

        rows.push_back(r1RowStart + i);
        cols.push_back(u1Col);
        values.push_back(-1.0);

        rows.push_back(r1RowStart + i);
        cols.push_back(r1ColStart + i);
        values.push_back(1.0);

        rows.push_back(pb1RowStart + i);
        cols.push_back(b1ColStart + i);
        values.push_back(1.0);

        rows.push_back(pb1RowStart + i);
        cols.push_back(p1ColStart + i);
        values.push_back(1.0);

        rows.push_back(rm1RowStart + i);
        cols.push_back(b1ColStart + i);
        values.push_back(-U1);

        rows.push_back(rm1RowStart + i);
        cols.push_back(r1ColStart + i);
        values.push_back(1.0);
    }

    for (const IdentifierPtr& player2Strategy : *player2.getStrategies()) {
        int j = player2.getStrategyOrdinal(*player2Strategy);

        rows.push_back(p2Row);
        cols.push_back(p2ColStart + j);
        values.push_back(1.0);

        rows.push_back(u2RowStart + j);
        cols.push_back(u2sColStart + j);
        values.push_back(1.0);

        rows.push_back(max2RowStart + j);
        cols.push_back(u2sColStart + j);
        values.push_back(-1.0);

        rows.push_back(max2RowStart + j);
        cols.push_back(u2Col);
        values.push_back(1.0);

        rows.push_back(r2RowStart + j);
        cols.push_back(u2sColStart + j);
        values.push_back(1.0);

        rows.push_back(r2RowStart + j);
        cols.push_back(u2Col);
        values.push_back(-1.0);

        rows.push_back(r2RowStart + j);
        cols.push_back(r2ColStart + j);
        values.push_back(1.0);

        rows.push_back(pb2RowStart + j);
        cols.push_back(b2ColStart + j);
        values.push_back(1.0);

        rows.push_back(pb2RowStart + j);
        cols.push_back(p2ColStart + j);
        values.push_back(1.0);

        rows.push_back(rm2RowStart + j);
        cols.push_back(b2ColStart + j);
        values.push_back(-U2);

        rows.push_back(rm2RowStart + j);
        cols.push_back(r2ColStart + j);
        values.push_back(1.0);
    }

    // vectors uses contignous memory - &x[0] "transforms" it into a C-style array
    glp_load_matrix(problem, rows.size()-1, &rows[0], &cols[0], &values[0]);
}

ResultPtr Strategic2PlayerMixedEquilibriumRoutine::solveProblem(
    LPProblem*                          problem,
    const StrategicDataAccessor&        data,
    const StrategicGamePositionsHelper& positionsHelper
) const {
    typedef map<Identifier, double> DistributionMap;

    glp_smcp parm;
    glp_init_smcp(&parm);
    parm.msg_lev = GLP_MSG_OFF;

    if (glp_simplex(problem, &parm) != 0 || glp_get_prim_stat(problem) != GLP_FEAS) {
        // TODO: create MessageFactory
        return ResultFactory::getInstance().constResult(Message("Failed to calculate the solution"));
    }

    const Player&     player1     = *( positionsHelper.getPlayers()->begin()->second );
    const Identifier& player1Name = *( player1.getName() );
    const Player&     player2     = *( (++positionsHelper.getPlayers()->begin())->second );
    const Identifier& player2Name = *( player2.getName() );

    const int b1ColStart  = 1;
    const int b2ColStart  = b1ColStart  + player1.getStrategiesNumber();
    const int p1ColStart  = b2ColStart  + player2.getStrategiesNumber();
    const int p2ColStart  = p1ColStart  + player1.getStrategiesNumber();

    DistributionMap player1Distribution;
    for (const IdentifierPtr& strategy : *player1.getStrategies()) {
        Index  i           = player1.getStrategyOrdinal(*strategy);
        double probability = glp_get_col_prim(problem, p1ColStart + i);

        player1Distribution.insert( DistributionMap::value_type(*strategy, probability) );
    }

    DistributionMap player2Distribution;
    for (const IdentifierPtr& strategy : *player2.getStrategies()) {
        Index  i           = player2.getStrategyOrdinal(*strategy);
        double probability = glp_get_col_prim(problem, p2ColStart + i);

        player2Distribution.insert( DistributionMap::value_type(*strategy, probability) );
    }

    double player1Payoff = 0.0;
    double player2Payoff = 0.0;
    for (const IdentifierPtr& player1Strategy : *player1.getStrategies()) {
        for (const IdentifierPtr& player2Strategy : *player2.getStrategies()) {
            Positions positions;
            positions.insert( Positions::value_type(player1Name, *player1Strategy) );
            positions.insert( Positions::value_type(player2Name, *player2Strategy) );

            player1Payoff += data[positions]->getPayoff(player1Name)->get_d() *
                             player1Distribution[*player1Strategy] *
                             player2Distribution[*player2Strategy];
            player2Payoff += data[positions]->getPayoff(player2Name)->get_d() *
                             player1Distribution[*player1Strategy] *
                             player2Distribution[*player2Strategy];
        }
    }

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

// }; /* END class Strategic2PlayerMixedEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
