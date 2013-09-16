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
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(paramFactoryMutex);
        if (!instance) {
            ParamFactory* volatile tmp = new ParamFactory();
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
    Number& number
) {
    NumberPtr value(new Number(number));
    return ParamPtr(new ValueParam(value));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
