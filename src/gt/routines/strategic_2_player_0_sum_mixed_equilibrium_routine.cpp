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
    const Player& player1 = *( players.begin()->second );
    const Player& player2 = *( (++players.begin())->second );

    unique_ptr<glp_prob, void(*)(glp_prob*)> problemPtr(glp_create_prob(), glp_delete_prob);
    glp_prob*                                problem(problemPtr.get());

    glp_set_prob_name( problem, "2 player 0-sum strategic form game" );
    glp_set_obj_dir(   problem, GLP_MAX );

    // for each

    // TODO: create MessageFactory
    return ResultFactory::getInstance().constResult(Message("No Nash equilibrium found"));
}

Message Strategic2Player0SumMixedEquilibriumRoutine::toString() const {
    return Message("Strategic2Player0SumMixedEquilibriumRoutine");
}

// }; /* END class Strategic2Player0SumMixedEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
