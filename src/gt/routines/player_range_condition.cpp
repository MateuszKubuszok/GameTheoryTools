/**
 * @file      gt/routines/player_range_condition.cpp
 * @brief     Defines GT::Routines::PlayerRangeCondition methods.
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

using boost::dynamic_pointer_cast;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerRangeCondition final : public Condition {
// public:

PlayerRangeCondition::PlayerRangeCondition(
    const IdentifierPtr  definedPlayer,
    const IdentifiersPtr definedStrategies
) :
    player(definedPlayer),
    strategies(definedStrategies)
    {}

void PlayerRangeCondition::configureRoutine(
    RoutineConfigPtr routineConfig
) const {
    PlayerChoiceRoutineConfigPtr specificConfig =
        dynamic_pointer_cast<PlayerChoiceRoutineConfig>(routineConfig);

    if (!specificConfig)
        return;

    try {
        specificConfig->requireChoiceWithin(*player, *strategies);
    } catch (InvalidPlayerChoice& e) {
        throw ExceptionFactory::getInstance().invalidCondition(e);
    }
}

Message PlayerRangeCondition::toString() const {
    ResultBuilderPtr strategiesBuilder = ResultFactory::getInstance().buildResult();
    for (Index i = 0; i < strategies->size(); i++)
        strategiesBuilder->addResult(
            createIdentifierPtr(i+1),
            createMessagePtr(strategies->at(i))
        );
    MessagePtr strategiesValue = createMessagePtr(strategiesBuilder->build()->getResult());
    return ResultFactory::getInstance().buildResult()->addResult(player,strategiesValue).build()->getResult();
}

// }; /* END class PlayerRangeCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
