/**
 * @file      gt/gtl/current_context_values_property.cpp
 * @brief     Defines GT::GTL::CurrentContextValuesProperty methods.
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

// class CurrentContextValuesProperty final : public ObjectProperty {
// public:

CurrentContextValuesProperty::CurrentContextValuesProperty(
    const Context* describedContext
) :
    context(describedContext)
    {}

ResultPtr CurrentContextValuesProperty::getDescription() const {
    static Message description =
        "Lists all declared Params that can be used in queries";
    return ResultFactory::getInstance().constResult(description);
}

ResultPtr CurrentContextValuesProperty::findForConditions(
    const Context&,
    const Conditions&
) const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    for (const Context::KnownObjects::value_type& objectPair : context->getKnownObjects()) {
        IdentifierPtr name  = createIdentifierPtr(objectPair.first);
        MessagePtr    value = createMessagePtr(objectPair.second->toString());
        resultBuilder->addResult(name, value);
    }

    return resultBuilder->build();
}

// }; /* END class CurrentContextValuesProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
