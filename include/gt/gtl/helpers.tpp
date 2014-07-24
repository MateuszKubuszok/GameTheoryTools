/**
 * @file      gt/gtl/helpers.tpp
 * @brief     Defines GT::GTL helpers.
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

template<typename Symbol>
shared_ptr<Symbol> setupLocation(
    shared_ptr<Symbol>   symbol,
    const InputLocation& inputLocation
) {
    symbol->setInputLocation(boost::make_shared<InputLocation>(inputLocation));
    return symbol;
}
