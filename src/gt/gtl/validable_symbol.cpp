/**
 * @file      gt/gtl/validable_symbol.cpp
 * @brief     Defines GT::GTL::ValidableSymbol methods.
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

// class ValidableSymbol : public virtual Root {

void ValidableSymbol::comparisonsAreNotAllowed() const {}

// public:

ValidableSymbol::ValidableSymbol() :
    inputLocation(new InputLocation())
    {}

ValidableSymbol::~ValidableSymbol() {}

bool ValidableSymbol::isValid() const {
    return true;
}

const InputLocationPtr ValidableSymbol::getInputLocation() const {
    return inputLocation;
}

void ValidableSymbol::setInputLocation(
    const InputLocationPtr newInputLocation
) {
    inputLocation = newInputLocation;
}

ValidableSymbol::operator SafeBoolIdiom() const {
    return isValid() ? &ValidableSymbol::comparisonsAreNotAllowed : 0;
}

// }; /* END class ValidableSymbol */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
