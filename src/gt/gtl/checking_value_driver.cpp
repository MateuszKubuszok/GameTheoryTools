/**
 * @file      gt/gtl/checking_value_driver.cpp
 * @brief     Defines GT::GTL::CheckingValueDriver methods.
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

// class CheckingValueDriver final : ValueDriver {
// public:

ParamPtr* CheckingValueDriver::get(
    const InputLocation& inputLocation,
    const IdentifierPtr*
) const {
    return new ParamPtr(
        setupLocation<Param>(
            NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

ParamPtr* CheckingValueDriver::get(
    const InputLocation& inputLocation,
    const NumberPtr*
) const {
    return new ParamPtr(
        setupLocation<Param>(
            NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

ObjectPtr* CheckingValueDriver::toObject(
    const GamePtr* game
) const {
    return new ObjectPtr(dynamic_pointer_cast<Object>(*game));
}

ObjectPtr* CheckingValueDriver::toObject(
    const PlayerPtr* player
) const {
    return new ObjectPtr(dynamic_pointer_cast<Object>(*player));
}

ObjectPtr* CheckingValueDriver::toObject(
    const ParamPtr* param
) const {
    return new ObjectPtr(dynamic_pointer_cast<Object>(*param));
}

Message CheckingValueDriver::toString() const {
    return Message("CheckingValueDriver");
}

// }; /* END class CheckingValueDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
