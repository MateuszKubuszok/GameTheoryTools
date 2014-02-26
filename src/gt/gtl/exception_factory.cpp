/**
 * @file      gt/gtl/exception_factory.cpp
 * @brief     Defines GT::GTL::ExceptionFactory methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory final {
// public:

ExceptionFactory& ExceptionFactory::getInstance() {
    static ExceptionFactory instance;
    return instance;
}

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

// }; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
