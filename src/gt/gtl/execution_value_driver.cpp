#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionValueDriver : public ValueDriver {
// public:

ExecutionValueDriver::ExecutionValueDriver(
    Driver* parentDriver
) :
    checkingValueDriver(parentDriver),
    driver(parentDriver)
    {}

ParamPtr* ExecutionValueDriver::get(
    const InputLocation& inputLocation,
    const IdentifierPtr* identifierPtr
) const {
    const IdentifierPtr& identifier = *identifierPtr;

    return new ParamPtr(
        setupLocation<Param>(
            ParamFactory::getInstance().createParam(identifier),
            inputLocation
        )
    );
}

ParamPtr* ExecutionValueDriver::get(
    const InputLocation& inputLocation,
    const NumberPtr*     valuePtr
) const {
    const NumberPtr& value = *valuePtr;

    return new ParamPtr(
        setupLocation<Param>(
            ParamFactory::getInstance().createParam(value),
            inputLocation
        )
    );
}

ObjectPtr* ExecutionValueDriver::toObject(
    const GamePtr* game
) const {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*game));
}

ObjectPtr* ExecutionValueDriver::toObject(
    const PlayerPtr* player
) const {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*player));
}

ObjectPtr* ExecutionValueDriver::toObject(
    const ParamPtr* param
) const {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*param));
}

Message ExecutionValueDriver::toString() const {
    return Message("ExecutionValueDriver");
}

// }; /* END class ExecutionValueDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
