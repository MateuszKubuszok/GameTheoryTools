#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

//class ValueParam {
// public:

ValueParam::ValueParam(
    NumberPtr number
) :
    value(number)
    {}

ObjectPtr ValueParam::getObject(
    Context& context
) {
    throw std::invalid_argument("Cannot obatin object for value param");
}

NumberPtr ValueParam::getValue(
    Context& context
) {
    return value;
}

Message ValueParam::toString() {
    return Message("Param:Value=") + value->get_str(10);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
