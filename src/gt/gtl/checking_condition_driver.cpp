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

ConditionPtr* CheckingConditionDriver::informationSetChoosed(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectPtr*     informationSetPtr,
    const ObjectPtr*     strategyPtr
) const {
    const Object& playerObject         = **playerPtr;
    const Object& informationSetObject = **informationSetPtr;
    const Object& strategyObject       = **strategyPtr;

    if (!isPlayerOrParam(playerObject)) {
        // TODO: create MessageFactory
        Message errorMessage = Message() + "Object does not define a Player: " + playerObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *playerObject.getInputLocation()
            )
        );
    }

    if (!hasIdentifier(informationSetObject)) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Object does not define a Param with information set: " + informationSetObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *informationSetObject.getInputLocation()
            )
        );
    }

    if (!hasIdentifier(strategyObject)) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Object does not define a Param with strategy: " + strategyObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *strategyObject.getInputLocation()
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

ConditionPtr* CheckingConditionDriver::informationSetWithin(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectPtr*     informationSetPtr,
    const ObjectsPtr*    strategiesPtr
) const {
    const Object&  playerObject         = **playerPtr;
    const Object&  informationSetObject = **informationSetPtr;
    const Objects& strategiesObjects    = **strategiesPtr;

    if (!isPlayerOrParam(playerObject)) {
        // TODO: create MessageFactory
        Message errorMessage = Message() + "Object does not define a Player: " + playerObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *playerObject.getInputLocation()
            )
        );
    }

    if (!hasIdentifier(informationSetObject)) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Object does not define a Param with information set: " + informationSetObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *informationSetObject.getInputLocation()
            )
        );
    }

    for (const ObjectPtr& strategy : strategiesObjects) {
        const Object& strategyObject = *strategy;
        if (!hasIdentifier(strategyObject)) {
            // TODO: create MessageFactory
            Message errorMessage = Message() +
                "Object does not define a Param with strategy: " + strategyObject.toString();
            return new ConditionPtr(
                setupLocation<Condition>(
                    ErrorFactory::getInstance().createCondition(errorMessage),
                    *strategyObject.getInputLocation()
                )
            );
        }
    }

    return new ConditionPtr(
        setupLocation<Condition>(
            NullFactory::getInstance().createCondition(),
            inputLocation
        )
    );
}

ConditionPtr* CheckingConditionDriver::playerChoosed(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectPtr*     strategyPtr
) const {
    const Object& playerObject   = **playerPtr;
    const Object& strategyObject = **strategyPtr;

    if (!isPlayerOrParam(playerObject)) {
        // TODO: create MessageFactory
        Message errorMessage = Message() + "Object does not define a Player: " + playerObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *playerObject.getInputLocation()
            )
        );
    }

    if (!hasIdentifier(strategyObject)) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Object does not define a Param with strategy: " + strategyObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *strategyObject.getInputLocation()
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

ConditionPtr* CheckingConditionDriver::playerWithin(
    const InputLocation& inputLocation,
    const ObjectPtr*     playerPtr,
    const ObjectsPtr*    strategiesPtr
) const {
    const Object&  playerObject      = **playerPtr;
    const Objects& strategiesObjects = **strategiesPtr;

    if (!isPlayerOrParam(playerObject)) {
        // TODO: create MessageFactory
        Message errorMessage = Message() + "Object does not define a Player: " + playerObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                *playerObject.getInputLocation()
            )
        );
    }

    for (const ObjectPtr& strategy : strategiesObjects) {
        const Object& strategyObject = *strategy;
        if (!hasIdentifier(strategyObject)) {
            // TODO: create MessageFactory
            Message errorMessage = Message() +
                "Object does not define a Param with strategy: " + strategyObject.toString();
            return new ConditionPtr(
                setupLocation<Condition>(
                    ErrorFactory::getInstance().createCondition(errorMessage),
                    *strategyObject.getInputLocation()
                )
            );
        }
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

// private:

bool CheckingConditionDriver::isPlayerOrParam(
    const Object& object
) const {
    if (!object)
        return false;

    const Player& player = object;
    const Param&  param  = object;

    return (player || param);
}

bool CheckingConditionDriver::hasIdentifier(
    const Object& object
) const {
    const Param& param = object;
    return param;
}

// }; /* END class CheckingConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
