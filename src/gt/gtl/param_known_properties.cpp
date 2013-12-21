/**
 * @file      gt/gtl/param_known_properties.cpp
 * @brief     Defines GT::Model::ParamKnownProperties methods.
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

// class ParamKnownProperties final : public ObjectProperty {
// public:

ParamKnownProperties::ParamKnownProperties(
    const Param* describedParam
) :
    param(describedParam)
    {}

ResultPtr ParamKnownProperties::findForConditions(
    const Context&    context,
    const Conditions& conditions
) const {
    try {
        static const Identifier propertyName = createIdentifier("properties");
        return param->getObject(context)->findPropertyWithConditions(context, propertyName, conditions);
    } catch (const CyclicIdentifiers&) {
    } catch (const InvalidContentRequest&) {
    } catch (const NotDefinedParam&) {}

    static const IdentifierPtr knownProperties = createIdentifierPtr("Known Properties");
    static const MessagePtr    message         = createMessagePtr("Param does not refer to an Object");
    return ResultFactory::getInstance().buildResult()->addResult(knownProperties, message).build();
}

// }; /* END class ParamKnownProperties */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
