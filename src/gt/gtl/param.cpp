#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Param
// public:

Param::Param() :
    Object(createIdentifier("Param"))
{
    registerProperty(Identifier("value"), ObjectPropertyPtr(new ParamValueProperty(this)));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
