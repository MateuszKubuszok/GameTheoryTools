#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory {

SINGLETON_DEFINITION(ExceptionFactory, getInstance, exceptionFactoryMutex)

// public:

CyclicIdentifiers ExceptionFactory::cyclicIdentifiersFound(
    const Param::VisitedIdentifiers& visitedIdentifiers,
    const Identifier&                currentIdentifier
) const {
    std::stringstream result;

    result << "Cyclic Identifiers found in list:\n";
    for (const Identifier& identifier : visitedIdentifiers)
        result << "\t\'" << identifier << "\'\n";
    result << "identifier \'"
           << currentIdentifier
           << "\' already defined";

    return CyclicIdentifiers(result.str());
}

InvalidProperty ExceptionFactory::invalidObjectProperty(
    const Identifier& propertyName
) const {
    std::stringstream result;

    result << "Property \'" << propertyName << "\' not defined";

    return InvalidProperty(result.str());
}

InvalidType ExceptionFactory::invalidObjectType(
    const Identifier& expectedType
) const {
    std::stringstream result;

    result << "Object is not of type " << expectedType;

    return InvalidType(result.str());
}

NotDefinedParam ExceptionFactory::notDefinedParam(
    const Identifier& paramName
) const {
    std::stringstream result;

    result << "Param \'" << paramName << "\' not defined";

    return NotDefinedParam(result.str());
}

InvalidContentRequest ExceptionFactory::requiredUnavailableNumberFromParam() const {
    return InvalidContentRequest("Cannot obtain Number from this Param");
}

InvalidContentRequest ExceptionFactory::requiredUnavailableObjectFromParam() const {
    return InvalidContentRequest("Cannot obtain Object from this Param");
}

// private:

ExceptionFactory::ExceptionFactory() {}

ExceptionFactory::~ExceptionFactory() {}

// }; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
