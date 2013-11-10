#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingConditionDriver : public ConditionDriver {
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
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() +
            "Invalid Object: " + playerObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                inputLocation
            )
        );
    }

    const Player& player       = playerObject;
    const Param&  playerParam  = playerObject;
    if (!player && !playerParam) {
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() + "Object does not define a Player: " + player.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                inputLocation
            )
        );
    }

    const Param& strategyParam = strategyObject;
    if (!strategyParam) {
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() +
            "Object does not define a Param with strategy: " + strategyParam.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                inputLocation
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
