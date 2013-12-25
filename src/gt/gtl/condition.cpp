/**
 * @file      gt/gtl/condition.cpp
 * @brief     Defines GT::GTL::Condition methods.
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

using boost::dynamic_pointer_cast;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Condition : public virtual ValidableSymbol {
// public:

Condition::~Condition() {}

// protected:

Identifier Condition::getIdentifier(
    const Context&   context,
    const ObjectPtr& object
) const {
    const Param& param = *object;
    if (!param) {
        static const Identifier expectedType = createIdentifier("Param");
        throw ExceptionFactory::getInstance().invalidObjectType(expectedType);
    }

    shared_ptr<IdentifierParam> identifierParam;
    try {
        identifierParam = dynamic_pointer_cast<IdentifierParam>( param.getObject(context) );
    } catch (const InvalidContentRequest& e) {
        identifierParam = dynamic_pointer_cast<IdentifierParam>( object );
    } catch (const NotDefinedParam& e) {
        identifierParam = dynamic_pointer_cast<IdentifierParam>( object );
    }

    if (!identifierParam) {
        static const Identifier expectedType = createIdentifier("Identifier Param");
        throw ExceptionFactory::getInstance().invalidObjectType(expectedType);
    }

    return identifierParam->getIdentifier();
}

// }; /* END class Condition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
