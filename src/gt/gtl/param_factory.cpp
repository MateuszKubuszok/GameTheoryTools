#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ParamFactory {

SINGLETON_DEFINITION(ParamFactory, getInstance, paramFactoryMutex)

// public:

ParamPtr ParamFactory::createParam(
    const Identifier& identifier
) const {
    return ParamPtr(new IdentifierParam(identifier));
}

ParamPtr ParamFactory::createParam(
    const IdentifierPtr identifier
) const {
    return ParamPtr(new IdentifierParam(*identifier));
}

ParamPtr ParamFactory::createParam(
    const Number& number
) const {
    NumberPtr value(new Number(number));
    return ParamPtr(new NumberParam(value));
}

ParamPtr ParamFactory::createParam(
    const NumberPtr number
) const {
    return ParamPtr(new NumberParam(number));
}

ParamPtr ParamFactory::createParam(
    const ObjectPtr object
) const {
    const Param& param = *object;
    return param ? boost::dynamic_pointer_cast<Param>(object) : ParamPtr(new ObjectParam(object));
}

// private:

ParamFactory::ParamFactory() {}

ParamFactory::~ParamFactory() {}

// }; /* END class ParamFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
