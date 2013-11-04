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
    InputLocation& inputLocation,
    IdentifierPtr*
) {
    return new ParamPtr(
        setupLocation<Param>(
            NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

ParamPtr* CheckingValueDriver::get(
    InputLocation& inputLocation,
    NumberPtr*
) {
    return new ParamPtr(
        setupLocation<Param>(
            NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

ObjectPtr* CheckingValueDriver::toObject(
    GamePtr* game
) {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*game));
}

ObjectPtr* CheckingValueDriver::toObject(
    PlayerPtr* player
) {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*player));
}

ObjectPtr* CheckingValueDriver::toObject(
    ParamPtr* param
) {
    return new ObjectPtr(boost::dynamic_pointer_cast<Object>(*param));
}

Message CheckingValueDriver::toString() {
    return Message("CheckingValueDriver");
}

// }; /* END class CheckingValueDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
