#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingValueDriver : ValueDriver {
// public:

CheckingValueDriver::CheckingValueDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

ParamPtr* CheckingValueDriver::get(
    const InputLocation& inputLocation,
    const IdentifierPtr*
) const {
    return new ParamPtr(
        setupLocation<Param>(
            NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

ParamPtr* CheckingValueDriver::get(
    const InputLocation& inputLocation,
    const NumberPtr*
) const {
    return new ParamPtr(
        setupLocation<Param>(
            NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

ObjectPtr* CheckingValueDriver::toObject(
    const GamePtr* game
) const {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*game));
}

ObjectPtr* CheckingValueDriver::toObject(
    const PlayerPtr* player
) const {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*player));
}

ObjectPtr* CheckingValueDriver::toObject(
    const ParamPtr* param
) const {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*param));
}

Message CheckingValueDriver::toString() const {
    return Message("CheckingValueDriver");
}

// }; /* END class CheckingValueDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
