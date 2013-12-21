#ifndef __GT_GTL_HELPERS_HPP__
#define __GT_GTL_HELPERS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/helpers.hpp
 * @brief     Declares GT::GTL helpers.
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

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Sets up location for ValidableSymbols.
 *
 * @param  symbol        symbol to set
 * @param  inputLocation location to set
 * @return               reference to selffor chaining
 */
template<typename Symbol>
shared_ptr<Symbol> setupLocation(
    shared_ptr<Symbol>   symbol,
    const InputLocation& inputLocation
);

/**
 * @brief Creates error Message for given parent message and error origin.
 *
 * @param parentMessage parent message that will be explained by suberror message
 * @param invalidSymbol invalid symbol to display
 * @return              message to show
 */
Message suberrorMessage(
    const Message&         parentMessage,
    const ValidableSymbol& invalidSymbol
);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/helpers.tpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_HELPERS_HPP__ */
