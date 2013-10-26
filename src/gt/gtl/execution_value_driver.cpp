#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ExecutionValueDriver {
// public:

ExecutionValueDriver::ExecutionValueDriver(
    Driver* parentDriver
) :
    checkingValueDriver(parentDriver),
    driver(parentDriver)
    {}

ParamPtr* ExecutionValueDriver::get(
    InputLocation& inputLocation,
    IdentifierPtr*
) {
    // TODO create an actual implementation
    return new ParamPtr(
        setupLocation<Param>(
            NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

ParamPtr* ExecutionValueDriver::get(
    InputLocation& inputLocation,
    NumberPtr*
) {
    // TODO create an actual implementation
    return new ParamPtr(
        setupLocation<Param>(
            NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

ObjectPtr* ExecutionValueDriver::toObject(
    GamePtr* game
) {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*game));
}

ObjectPtr* ExecutionValueDriver::toObject(
    PlayerPtr* player
) {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*player));
}

ObjectPtr* ExecutionValueDriver::toObject(
    ParamPtr* param
) {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*param));
}

Message ExecutionValueDriver::toString() {
    return Message("ExecutionValueDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
