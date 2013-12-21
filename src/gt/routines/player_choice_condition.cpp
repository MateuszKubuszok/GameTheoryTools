/**
 * @file      gt/routines/player_choice_condition.cpp
 * @brief     Defines GT::Routines::PlayerChoiceCondition methods.
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

using std::find_if;
using std::remove_if;

using boost::dynamic_pointer_cast;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerChoiceCondition final : public Condition {
// public:

PlayerChoiceCondition::PlayerChoiceCondition(
    const IdentifierPtr definedPlayer,
    const IdentifierPtr definedStrategy
) :
    player(definedPlayer),
    strategy(definedStrategy)
    {}

void PlayerChoiceCondition::configureRoutine(
    RoutinePtr routine
) const {
    SelectableStrategiesRoutinePtr specificRoutine =
        dynamic_pointer_cast<SelectableStrategiesRoutine>(routine);

    if (!routine)
        return;

    try {
        IdentifiersPtr availableStrategies = specificRoutine->getAvailableStrategiesForPlayer(*player);

        Identifiers::iterator strategyPosition = find_if(
            availableStrategies->begin(),
            availableStrategies->end(),
            [this](IdentifierPtr& currentStrategy) { return (bool) (*strategy == *currentStrategy); }
        );
        if (strategyPosition == availableStrategies->end())
            throw ExceptionFactory::getInstance().strategyNotFound(*player, *strategy);

        availableStrategies->erase(
            remove_if(
                availableStrategies->begin(),
                availableStrategies->end(),
                [this](IdentifierPtr& currentStrategy) { return (bool) (*strategy != *currentStrategy); }
            )
        );
    } catch (InvalidPlayerChoice& e) {
        throw ExceptionFactory::getInstance().invalidCondition(e);
    }
}

Message PlayerChoiceCondition::toString() const {
    MessagePtr strategyName = createMessagePtr(strategy);

    return ResultFactory::getInstance()
        .buildResult()->addResult(player, strategyName).build()->getResult();
}

// }; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
