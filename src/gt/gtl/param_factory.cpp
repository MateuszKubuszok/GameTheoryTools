/**
 * @file      gt/gtl/param_factory.cpp
 * @brief     Defines GT::GTL::ParamFactory methods.
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ParamFactory final {

ParamFactory& ParamFactory::getInstance() {
    static ParamFactory instance;
    return instance;
}

// public:

ParamPtr ParamFactory::createParam(
    const Identifier& identifier
) const {
    return ParamPtr(new IdentifierParam(identifier));
}

ParamPtr ParamFactory::createParam(
    const IdentifierPtr identifier
) const {
    return ParamPtr(new IdentifierParam(*identifier));
}

ParamPtr ParamFactory::createParam(
    const Number& number
) const {
    NumberPtr value(new Number(number));
    return ParamPtr(new NumberParam(value));
}

ParamPtr ParamFactory::createParam(
    const NumberPtr number
) const {
    return ParamPtr(new NumberParam(number));
}

ParamPtr ParamFactory::createParam(
    const ObjectPtr object
) const {
    const Param& param = object->toParam();
    return param ? dynamic_pointer_cast<Param>(object) : ParamPtr(new ObjectParam(object));
}

// private:

ParamFactory::ParamFactory() {}

ParamFactory::~ParamFactory() {}

// }; /* END class ParamFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
