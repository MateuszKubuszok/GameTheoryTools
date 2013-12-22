/**
 * @file      gt/model/extensive_data_accessor.cpp
 * @brief     Defines GT::Model::ExtensiveDataAccessor methods.
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

#include "inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveDataAccessor final : public DataAccessor {
// public:

ExtensiveDataAccessor::ExtensiveDataAccessor(
    const ExtensiveDataPtr strategicData
) :
    data(strategicData)
    {}

const ExtensiveDataNodePtr ExtensiveDataAccessor::getRoot() const {
    return data->getRoot();
}

const PlayersPtr ExtensiveDataAccessor::getPlayers() const {
    return data->getPlayers();
}

const DataPiecePtr ExtensiveDataAccessor::getPayoffs(
    const PositionsPtr positions
) const {
    return data->getPayoffs(positions);
}

const DataPiecePtr ExtensiveDataAccessor::getPayoffs(
    const Positions& positions
) const {
    return data->getPayoffs(positions);
}

Message ExtensiveDataAccessor::toString() const {
    static const IdentifierPtr name      = createIdentifierPtr("Extensive Data Accessor");
    const MessagePtr           subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

const DataPiecePtr ExtensiveDataAccessor::operator[](
    const Positions& positions
) const {
    return (*data)[positions];
}

const DataPiecePtr ExtensiveDataAccessor::operator[](
    const PositionsPtr positions
) const {
    return (*data)[positions];
}

// }; /* END class ExtensiveDataAccessor */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
