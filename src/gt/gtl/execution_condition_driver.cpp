/**
 * @file      gt/gtl/execution_condition_driver.cpp
 * @brief     Defines GT::GTL::ExecutionConditionDriver methods.
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

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionConditionDriver final : public ConditionDriver {
// public:

ExecutionConditionDriver::ExecutionConditionDriver(
    Driver* parentDriver
) :
    checkingConditionDriver(parentDriver),
    driver(parentDriver)
    {}

ConditionPtr* ExecutionConditionDriver::informationSetChoosed(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectPtr*     informationSetPtr,
    const ObjectPtr*     strategyPtr
) const {
    ConditionPtr* errorCheck = checkingConditionDriver
        .informationSetChoosed(inputLocation, playerPtr, informationSetPtr, strategyPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const ObjectPtr& playerObject         = *playerPtr;
    const ObjectPtr& informationSetObject = *informationSetPtr;
    const ObjectPtr& strategyObject       = *strategyPtr;

    return new ConditionPtr(
        setupLocation<Condition>(
            ConditionFactory::getInstance()
                .createInformationSetChoiceCondition(playerObject, informationSetObject, strategyObject),
            inputLocation
        )
    );
}

ConditionPtr* ExecutionConditionDriver::informationSetWithin(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectPtr*     informationSetPtr,
    const ObjectsPtr*    strategiesPtr
) const {
    ConditionPtr* errorCheck = checkingConditionDriver
        .informationSetWithin(inputLocation, playerPtr, informationSetPtr, strategiesPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const ObjectPtr&  playerObject         = *playerPtr;
    const ObjectPtr&  informationSetObject = *informationSetPtr;
    const ObjectsPtr& strategiesObjects    = *strategiesPtr;

    return new ConditionPtr(
        setupLocation<Condition>(
            ConditionFactory::getInstance()
                .createInformationSetRangeCondition(playerObject, informationSetObject, strategiesObjects),
            inputLocation
        )
    );
}

ConditionPtr* ExecutionConditionDriver::playerChoosed(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectPtr*     strategyPtr
) const {
    ConditionPtr* errorCheck = checkingConditionDriver.playerChoosed(inputLocation, playerPtr, strategyPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const ObjectPtr& playerObject   = *playerPtr;
    const ObjectPtr& strategyObject = *strategyPtr;

    return new ConditionPtr(
        setupLocation<Condition>(
            ConditionFactory::getInstance().createPlayerChoiceCondition(playerObject, strategyObject),
            inputLocation
        )
    );
}

ConditionPtr* ExecutionConditionDriver::playerWithin(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectsPtr*    strategiesPtr
) const {
    ConditionPtr* errorCheck = checkingConditionDriver.playerWithin(inputLocation, playerPtr, strategiesPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const ObjectPtr&  playerObject      = *playerPtr;
    const ObjectsPtr& strategiesObjects = *strategiesPtr;

    return new ConditionPtr(
        setupLocation<Condition>(
            ConditionFactory::getInstance().createPlayerRangeCondition(playerObject, strategiesObjects),
            inputLocation
        )
    );
}

Message ExecutionConditionDriver::toString() const {
    return Message("ExecutionConditionDriver");
}

// }; /* END class ExecutionConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
