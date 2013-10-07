#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

boost::mutex paramFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class ParamFactory {

ParamFactory* volatile ParamFactory::instance = 0;

// public:

ParamFactory& ParamFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking".
    if (!instance) {
        boost::mutex::scoped_lock lock(paramFactoryMutex);
        if (!instance) {
            ParamFactory* volatile tmp = (ParamFactory*) malloc(sizeof(ParamFactory));
            new (tmp) ParamFactory; // placement new
            instance = tmp;
        }
    }
    return *instance;
}

ParamFactory::ParamFactory() {}

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

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
