#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionConditionDriver : public ConditionDriver {
// public:

ExecutionConditionDriver::ExecutionConditionDriver(
    Driver* parentDriver
) :
    checkingConditionDriver(parentDriver),
    driver(parentDriver)
    {}

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

Message ExecutionConditionDriver::toString() const {
    return Message("ExecutionConditionDriver");
}

// }; /* END class ExecutionConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
