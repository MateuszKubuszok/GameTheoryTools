#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class CheckingValueDriver {
// public:

CheckingValueDriver::CheckingValueDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

ParamPtr* CheckingValueDriver::get(
    IdentifierPtr* identifier
) {
    return new ParamPtr(NullFactory::getInstance().createParam());
}

ParamPtr* CheckingValueDriver::get(
    NumberPtr* number
) {
    return new ParamPtr(NullFactory::getInstance().createParam());
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

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
