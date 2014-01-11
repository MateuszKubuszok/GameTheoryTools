/**
 * @file      gt/gtl/param_value_property.cpp
 * @brief     Defines GT::GTL::ParamValueProperty methods.
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

// class ParamValueProperty final : public ObjectProperty {
// public:

ParamValueProperty::ParamValueProperty(
    const Param* describedParam
) :
    param(describedParam)
    {}

ResultPtr ParamValueProperty::findForConditions(
    const Context& context,
    const Conditions&
) const {
    Message content;
    try {
        content = param->getObject(context)->toString();
    } catch (const InvalidContentRequest&) {
        try {
            content = createMessage(param->getNumber(context));
        } catch (const InvalidContentRequest&) {
            content = param->toString();
        }
    }
    return ResultFactory::getInstance().constResult(content);
}

// }; /* END class ParamValueProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
