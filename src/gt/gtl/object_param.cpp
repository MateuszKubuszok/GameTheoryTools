/**
 * @file      gt/gtl/object_param.cpp
 * @brief     Defines GT::GTL::ObjectParam methods.
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

// class ObjectParam final : public Param {
// public:

ObjectParam::ObjectParam(
    const ObjectPtr object
) :
    Param(),
    value(object)
    {}

const ObjectPtr ObjectParam::getObject(
    const Context&,
    VisitedIdentifiers&
) const {
    return value;
}

const NumberPtr ObjectParam::getNumber(
    const Context&,
    VisitedIdentifiers&
) const {
    throw ExceptionFactory::getInstance().requiredUnavailableNumberFromParam();
}

Message ObjectParam::serialize() const {
    return value->serialize();
}

Message ObjectParam::toString() const {
    static const IdentifierPtr name  = createIdentifierPtr("ObjectParam");
    MessagePtr                 val   = createMessagePtr(value->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, val).build()->getResult();
}

// }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
