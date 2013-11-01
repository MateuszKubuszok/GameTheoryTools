#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ParamFactory {

SINGLETON_DEFINITION(ParamFactory, getInstance, paramFactoryMutex)

// public:

ParamPtr ParamFactory::createParam(
    Identifier& identifier
) {
    return ParamPtr(new IdentifierParam(identifier));
}

ParamPtr ParamFactory::createParam(
    IdentifierPtr identifier
) {
    return ParamPtr(new IdentifierParam(*identifier));
}

ParamPtr ParamFactory::createParam(
    Number& number
) {
    NumberPtr value(new Number(number));
    return ParamPtr(new NumberParam(value));
}

ParamPtr ParamFactory::createParam(
    NumberPtr number
) {
    return ParamPtr(new NumberParam(number));
}

ParamPtr ParamFactory::createParam(
    ObjectPtr object
) {
    return ParamPtr(new ObjectParam(object));
}

// private:

ParamFactory::ParamFactory() {}

ParamFactory::~ParamFactory() {}

// }; /* END class ParamFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
