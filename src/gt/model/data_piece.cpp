/**
 * @file      gt/model/data_piece.cpp
 * @brief     Defines GT::Model::DataPiece methods.
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

#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class DataPiece : public virtual Root {
// public:

const NumberPtr& DataPiece::getPayoff(
    const IdentifierPtr playerName
) const {
    return getPayoff(*playerName);
}

const NumberPtr& DataPiece::operator[](
    const Identifier& playerName
) const {
    return getPayoff(playerName);
}

const NumberPtr& DataPiece::operator[](
    const IdentifierPtr playerName
) const {
    return getPayoff(playerName);
}

// }; /* END class DataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
