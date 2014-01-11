/**
 * @file      gt/gtl/number_param.cpp
 * @brief     Defines GT::GTL::NumberParam methods.
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

// class NumberParam final : public Param {
// public:

NumberParam::NumberParam(
    const NumberPtr number
) :
    Param(),
    value(number)
    {}

const ObjectPtr NumberParam::getObject(
    const Context&,
    VisitedIdentifiers&
) const {
    throw ExceptionFactory::getInstance().requiredUnavailableObjectFromParam();
}

const NumberPtr NumberParam::getNumber(
    const Context&,
    VisitedIdentifiers&
) const {
    return value;
}

Message NumberParam::serialize() const {
    return createMessage(value);
}

Message NumberParam::toString() const {
    static const IdentifierPtr name  = createIdentifierPtr("NumberParam");
    MessagePtr                 val   = createMessagePtr(value);
    return ResultFactory::getInstance().buildResult()->addResult(name, val).build()->getResult();
}

// }; /* END class NumberParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
