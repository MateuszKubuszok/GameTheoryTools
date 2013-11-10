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

const DataPiecePtr StrategicData::getValues(
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

const DataPiecePtr StrategicData::getValues(
    const Positions& positions
) const {
    return getValues(positionsHelper.calculatePosition(positions));
}

const DataPiecePtr StrategicData::getValues(
    const PositionsPtr positions
) const {
    return getValues(*positions);
}

Data& StrategicData::setValues(
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

Data& StrategicData::setValues(
    const Positions& positions,
    const NumbersPtr numbers
) {
    if (!positionsHelper.checkPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    return setValues(
        positionsHelper.calculatePosition(positions),
        numbers
    );
}

Data& StrategicData::setValues(
    const PositionsPtr positions,
    const NumbersPtr   numbers
) {
    return setValues(*positions, numbers);
}

const DataPiecePtr StrategicData::operator[](
    const Index positionInStorage
) const {
    return getValues(positionInStorage);
}

const DataPiecePtr StrategicData::operator[](
    const Positions& positions
) const {
    return getValues(positions);
}

const DataPiecePtr StrategicData::operator[](
    const PositionsPtr positions
) const {
    return getValues(positions);
}

Message StrategicData::toString() const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    IdentifierPtr positionName  = createIdentifierPtr("Position");
    IdentifierPtr payoffName    = createIdentifierPtr("Payoff");
    IdentifiersPtr playersNames = createIdentifiersPtr();
    for (Index i = 0; i < positionsHelper.getPlayers()->size(); i++)
        playersNames->push_back( createIdentifierPtr(positionsHelper.retrievePlayer(i)) );

    Index maxPosition = payoffStorage.size();
    for (Index i = 0; i < maxPosition; i++)
        if (payoffStorageAllocation.at(i)) {
            const IdentifierPtr  name       = createIdentifierPtr("Value");
            const PositionsPtr   positions  = positionsHelper.retrievePositions(i);
            const NumbersPtr     numbers    = payoffStorage[i];
            const IdentifiersPtr strategies = createIdentifiersPtr();
            const MessagesPtr    numbersStr = createMessagesPtr();

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
