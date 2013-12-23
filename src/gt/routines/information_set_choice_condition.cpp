/**
 * @file      gt/routines/information_set_choice_condition.cpp
 * @brief     Defines GT::Routines::InformationSetChoiceCondition methods.
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

// class InformationSetChoiceCondition final : public Condition {
// public:

InformationSetChoiceCondition::InformationSetChoiceCondition(
    const IdentifierPtr definedPlayer,
    const IdentifierPtr definedInformationSet,
    const IdentifierPtr definedStrategy
) :
    player(definedPlayer),
    informationSet(definedInformationSet),
    strategy(definedStrategy)
    {}

void InformationSetChoiceCondition::configureRoutine(
    RoutineConfigPtr routineConfig
) const {
    InformationSetChoiceRoutineConfigPtr specificConfig =
        dynamic_pointer_cast<InformationSetChoiceRoutineConfig>(routineConfig);

    if (!specificConfig)
        return;

    try {
        specificConfig->requireChoiceExactly(*player, *informationSet, *strategy);
    } catch (InvalidPlayerChoice& e) {
        throw ExceptionFactory::getInstance().invalidCondition(e);
    }
}

Message InformationSetChoiceCondition::toString() const {
    MessagePtr strategyName = createMessagePtr(strategy);
    MessagePtr setValue     = createMessagePtr(
        ResultFactory::getInstance()
        .buildResult()->addResult(informationSet, strategyName)
        .build()->getResult()
    );
    return ResultFactory::getInstance().buildResult()->addResult(player, setValue).build()->getResult();
}

// }; /* END class InformationSetChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
