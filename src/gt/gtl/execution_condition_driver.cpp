#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ExecutionConditionDriver {
// public:

ExecutionConditionDriver::ExecutionConditionDriver(
    Driver* parentDriver
) :
    checkingConditionDriver(parentDriver),
    driver(parentDriver)
    {}

ConditionPtr* ExecutionConditionDriver::playerChoosed(
    InputLocation& inputLocation,
    ObjectPtr*     playerPtr,
    ObjectPtr*     strategyPtr
) {
    ConditionPtr* errorCheck = checkingConditionDriver.playerChoosed(inputLocation, playerPtr, strategyPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    // Object& playerObject   = **playerPtr;
    // Object& strategyObject = **strategyPtr;

    // TODO ConditionFactory and implementations
    return new ConditionPtr(
        NullFactory::getInstance().createCondition()
    );
}

Message ExecutionConditionDriver::toString() {
    return Message("ExecutionConditionDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
