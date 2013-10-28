#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory {

SINGLETON_DEFINITION(ExceptionFactory, getInstance, exceptionFactoryMutex)

// public:

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

InvalidType ExceptionFactory::invalidObjectType(
    Identifier& expectedType
) {
    std::stringstream result;

    result << "Object is not of type " << expectedType;

    return InvalidType(result.str());
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

ExceptionFactory::~ExceptionFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
