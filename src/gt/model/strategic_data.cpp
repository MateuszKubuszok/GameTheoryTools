/**
 * @file      gt/model/strategic_data.cpp
 * @brief     Defines GT::Model::StrategicData methods.
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

// class StrategicData : public Data {
// public:

StrategicData::StrategicData(
    const PlayersPtr players
) :
    positionsHelper(players),
    payoffStorage(),
    payoffStorageAllocation()
{
    Index maxPosition = positionsHelper.getUpperBound();
    for (Index i = 0; i < maxPosition; i++) {
        payoffStorage.push_back( NullFactory::getInstance().createNumbers() );
        payoffStorageAllocation.push_back( false );
    }
}

const PlayersPtr StrategicData::getPlayers() const {
    return positionsHelper.getPlayers();
}

const DataPiecePtr StrategicData::getPayoffs(
    const Index positionInStorage
) const {
    if (!payoffStorageAllocation.at(positionInStorage))
        throw ExceptionFactory::getInstance().noParamsForPositions(
            positionInStorage,
            positionsHelper.getUpperBound()
        );

    return DataPiecePtr(
        new PlainDataPiece(
            positionsHelper.getPlayers(),
            payoffStorage.at(positionInStorage)
        )
    );
}

const DataPiecePtr StrategicData::getPayoffs(
    const Positions& positions
) const {
    return getPayoffs(positionsHelper.calculatePosition(positions));
}

const DataPiecePtr StrategicData::getPayoffs(
    const PositionsPtr positions
) const {
    return getPayoffs(*positions);
}

Data& StrategicData::setPayoffs(
    const Index      positionInStorage,
    const NumbersPtr numbers
) {
    if (positionsHelper.getUpperBound() <= positionInStorage)
        throw ExceptionFactory::getInstance().noParamsForPositions(
            positionInStorage,
            positionsHelper.getUpperBound()
        );

    payoffStorage.at(positionInStorage)           = numbers;
    payoffStorageAllocation.at(positionInStorage) = true;

    return *this;
}

Data& StrategicData::setPayoffs(
    const Positions& positions,
    const NumbersPtr numbers
) {
    if (!positionsHelper.checkPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    return setPayoffs(
        positionsHelper.calculatePosition(positions),
        numbers
    );
}

Data& StrategicData::setPayoffs(
    const PositionsPtr positions,
    const NumbersPtr   numbers
) {
    return setPayoffs(*positions, numbers);
}

Index StrategicData::getUpperBound() const {
    return positionsHelper.getUpperBound();
}

const DataPiecePtr StrategicData::operator[](
    const Index positionInStorage
) const {
    return getPayoffs(positionInStorage);
}

const DataPiecePtr StrategicData::operator[](
    const Positions& positions
) const {
    return getPayoffs(positions);
}

const DataPiecePtr StrategicData::operator[](
    const PositionsPtr positions
) const {
    return getPayoffs(positions);
}

Message StrategicData::toString() const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    static const IdentifierPtr positionName  = createIdentifierPtr("Position");
    static const IdentifierPtr payoffName    = createIdentifierPtr("Payoff");
    IdentifiersPtr playersNames = createIdentifiersPtr();
    for (Index i = 0; i < positionsHelper.getPlayers()->size(); i++)
        playersNames->push_back( createIdentifierPtr(positionsHelper.retrievePlayer(i)) );

    Index maxPosition = payoffStorage.size();
    for (Index i = 0; i < maxPosition; i++)
        if (payoffStorageAllocation.at(i)) {
            static const IdentifierPtr name       = createIdentifierPtr("Value");
            const PositionsPtr         positions  = positionsHelper.retrievePositions(i);
            const NumbersPtr           numbers    = payoffStorage[i];
            const IdentifiersPtr       strategies = createIdentifiersPtr();
            const MessagesPtr          numbersStr = createMessagesPtr();

            for (const IdentifierPtr& playerName : (*playersNames)) {
                strategies->push_back( createIdentifierPtr((*positions)[*playerName]) );
                numbersStr->push_back( createMessagePtr(
                    (*numbers)[positionsHelper.calculatePlayer(playerName)]
                ) );
            }

            ResultBuilderPtr subresultBuilder = ResultFactory::getInstance().buildResult();
            subresultBuilder->setHeaders(playersNames)
                             .addRecord(positionName, strategies)
                             .addRecord(payoffName, numbersStr);
            MessagePtr subresult = createMessagePtr(subresultBuilder->buildRaw()->getResult());
            resultBuilder->addResult(name, subresult);
        }

    return resultBuilder->build()->getResult();
}

// }; /* END class StrategicData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
