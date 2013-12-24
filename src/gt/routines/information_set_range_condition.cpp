/**
 * @file      gt/routines/information_set_range_condition.cpp
 * @brief     Defines GT::Routines::InformationSetRangeCondition methods.
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

// class InformationSetRangeCondition final : public Condition {
// public:

InformationSetRangeCondition::InformationSetRangeCondition(
    const IdentifierPtr  definedPlayer,
    const IdentifierPtr  definedInformationSet,
    const IdentifiersPtr definedStrategies
) :
    player(definedPlayer),
    informationSet(definedInformationSet),
    strategies(definedStrategies)
    {}

void InformationSetRangeCondition::configureRoutine(
    RoutineConfigPtr routineConfig
) const {
    InformationSetChoiceRoutineConfigPtr specificConfig =
        dynamic_pointer_cast<InformationSetChoiceRoutineConfig>(routineConfig);

    if (!specificConfig)
        return;

    try {
        specificConfig->requireChoiceWithin(*player, *informationSet, *strategies);
    } catch (const InvalidPlayerChoice& e) {
        throw ExceptionFactory::getInstance().invalidCondition(e);
    }
}

Message InformationSetRangeCondition::toString() const {
    ResultBuilderPtr strategiesBuilder = ResultFactory::getInstance().buildResult();
    for (Index i = 0; i < strategies->size(); i++)
        strategiesBuilder->addResult(
            createIdentifierPtr(i+1),
            createMessagePtr(strategies->at(i))
        );
    MessagePtr strategiesValue = createMessagePtr(strategiesBuilder->build()->getResult());
    MessagePtr setValue        = createMessagePtr(
        ResultFactory::getInstance()
        .buildResult()->addResult(informationSet, strategiesValue)
        .build()->getResult()
    );
    return ResultFactory::getInstance().buildResult()->addResult(player, setValue).build()->getResult();
}

// }; /* END class InformationSetRangeCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
