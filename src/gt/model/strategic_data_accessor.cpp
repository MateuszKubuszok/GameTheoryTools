/**
 * @file      gt/model/strategic_data_accessor.cpp
 * @brief     Defines GT::Model::StrategicDataAccessor methods.
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

// class StrategicDataAccessor final : public DataAccessor {
// public:

StrategicDataAccessor::StrategicDataAccessor(
    const StrategicDataPtr strategicData
) :
    data(strategicData)
    {}

const PlayersPtr StrategicDataAccessor::getPlayers() const {
    return data->getPlayers();
}

const DataPiecePtr StrategicDataAccessor::getPayoffs(
    const Index positionInStorage
) const {
    return data->getPayoffs(positionInStorage);
}

const DataPiecePtr StrategicDataAccessor::getPayoffs(
    const PositionsPtr positions
) const {
    return data->getPayoffs(positions);
}

const DataPiecePtr StrategicDataAccessor::getPayoffs(
    const Positions& positions
) const {
    return data->getPayoffs(positions);
}

Message StrategicDataAccessor::toString() const {
    static const IdentifierPtr name      = createIdentifierPtr("Strategic Data Accessor");
    const MessagePtr           subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

const DataPiecePtr StrategicDataAccessor::operator[](
    const Index positionInStorage
) const {
    return (*data)[positionInStorage];
}

const DataPiecePtr StrategicDataAccessor::operator[](
    const Positions& positions
) const {
    return (*data)[positions];
}

const DataPiecePtr StrategicDataAccessor::operator[](
    const PositionsPtr positions
) const {
    return (*data)[positions];
}

// }; /* END class StrategicDataAccessor*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
