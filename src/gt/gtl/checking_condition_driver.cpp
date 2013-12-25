/**
 * @file      gt/gtl/checking_condition_driver.cpp
 * @brief     Defines GT::GTL::CheckingConditionDriver methods.
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

// class CheckingConditionDriver final : public ConditionDriver {
// public:

CheckingConditionDriver::CheckingConditionDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

ConditionPtr* CheckingConditionDriver::playerChoosed(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectPtr*     strategyPtr
) const {
    const Object& playerObject   = **playerPtr;
    const Object& strategyObject = **strategyPtr;

    if (!playerObject) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Invalid Object: " + playerObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *playerObject.getInputLocation()
            )
        );
    }

    const Player& player       = playerObject;
    const Param&  playerParam  = playerObject;
    if (!player && !playerParam) {
        // TODO: create MessageFactory
        Message errorMessage = Message() + "Object does not define a Player: " + player.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *player.getInputLocation()
            )
        );
    }

    const Param& strategyParam = strategyObject;
    if (!strategyParam) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Object does not define a Param with strategy: " + strategyParam.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *strategyParam.getInputLocation()
            )
        );
    }

    return new ConditionPtr(
        setupLocation<Condition>(
            NullFactory::getInstance().createCondition(),
            inputLocation
        )
    );
}

Message CheckingConditionDriver::toString() const {
    return Message("CheckingConditionDriver");
}

// }; /* END class CheckingConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
