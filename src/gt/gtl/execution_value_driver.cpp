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
    IdentifierPtr* identifierPtr
) {
    IdentifierPtr& identifier = *identifierPtr;

    return new ParamPtr(
        setupLocation<Param>(
            ParamFactory::getInstance().createParam(identifier),
            inputLocation
        )
    );
}

ParamPtr* ExecutionValueDriver::get(
    InputLocation& inputLocation,
    NumberPtr*     valuePtr
) {
    NumberPtr& value = *valuePtr;

    return new ParamPtr(
        setupLocation<Param>(
            ParamFactory::getInstance().createParam(value),
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
