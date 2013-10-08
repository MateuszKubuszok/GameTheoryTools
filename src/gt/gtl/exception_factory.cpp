#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

boost::mutex exceptionFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory {

ExceptionFactory* volatile ExceptionFactory::instance = 0;

// public:

ExceptionFactory& ExceptionFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking".
    if (!instance) {
        boost::mutex::scoped_lock lock(exceptionFactoryMutex);
        if (!instance) {
            ExceptionFactory* volatile tmp = (ExceptionFactory*) malloc(sizeof(ExceptionFactory));
            new (tmp) ExceptionFactory; // placement new
            instance = tmp;
        }
    }
    return *instance;
}

CyclicIdentifiers ExceptionFactory::cyclicIdentifiersFound(
    Param::VisitedIdentifiers& visitedIdentifiers,
    Identifier&                currentIdentifier
) {
    std::stringstream result;

    result << "Cyclic Identifiers found in list:\n";
    for (Identifier& identifier : visitedIdentifiers)
        result << "\t\'" << identifier << "\'\n";
    result << "identifier \'"
           << currentIdentifier
           << "\' already defined"; 

    return CyclicIdentifiers(result.str());
}

InvalidProperty ExceptionFactory::invalidObjectProperty(
    Identifier& propertyName
) {
    std::stringstream result;

    result << "Property \'" << propertyName << "\' not defined";

    return InvalidProperty(result.str());
}

NotDefinedParam ExceptionFactory::notDefinedParam(
    Identifier& paramName
) {
    std::stringstream result;

    result << "Param \'" << paramName << "\' not defined";

    return NotDefinedParam(result.str());
}

InvalidContentRequest ExceptionFactory::requiredUnavailableNumberFromParam() {
    return InvalidContentRequest("Cannot obtain Number from this Param");
}

InvalidContentRequest ExceptionFactory::requiredUnavailableObjectFromParam() {
    return InvalidContentRequest("Cannot obtain Object from this Param");
}

// private:

ExceptionFactory::ExceptionFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
