#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class StrategicData { 
// public:

StrategicData::StrategicData(
    PlayersPtr players
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

PlayersPtr StrategicData::getPlayers() {
    return positionsHelper.getPlayers();
}

DataPiecePtr StrategicData::getValues(
    Index positionInStorage
) {
    if (!payoffStorageAllocation[positionInStorage])
        throw ExceptionFactory::getInstance()
                .noParamsForPositions(
                    positionInStorage,
                    positionsHelper.getUpperBound()
                );
    
    return DataPiecePtr(
        new PlainDataPiece(
            positionsHelper.getPlayers(),
            payoffStorage[positionInStorage]
        )
    );
}

DataPiecePtr StrategicData::getValues(
    Positions& positions
) {
    return getValues(positionsHelper.calculatePosition(positions));
}

DataPiecePtr StrategicData::getValues(
    PositionsPtr positions
) {
    return getValues(*positions);
}

Data& StrategicData::setValues(
    Index      positionInStorage,
    NumbersPtr numbers
) {
    if (positionInStorage < 0 || positionsHelper.getUpperBound() <= positionInStorage)
        throw ExceptionFactory::getInstance()
                .noParamsForPositions(
                    positionInStorage,
                    positionsHelper.getUpperBound()
                );

    payoffStorage[positionInStorage] = numbers;
    payoffStorageAllocation[positionInStorage] = true;

    return *this;
}

Data& StrategicData::setValues(
    Positions& positions,
    NumbersPtr numbers
) {
    if (!positionsHelper.checkPositions(positions))
        throw ExceptionFactory::getInstance()
                .invalidCoordinateFormat(positions);

    return setValues(
        positionsHelper.calculatePosition(positions),
        numbers
    );
}

Data& StrategicData::setValues(
    PositionsPtr positions,
    NumbersPtr   numbers
) {
    return setValues(*positions, numbers);
}

DataPiecePtr StrategicData::operator[](
    Index positionInStorage
) {
    return getValues(positionInStorage);
}

DataPiecePtr StrategicData::operator[](
    Positions& positions
) {
    return getValues(positions);
}

DataPiecePtr StrategicData::operator[](
    PositionsPtr positions
) {
    return getValues(positions);
}

Message StrategicData::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    IdentifierPtr positionName = createIdentifierPtr("Position");
    IdentifierPtr payoffName   = createIdentifierPtr("Payoff");
    IdentifiersPtr playersNames = createIdentifiersPtr();
    for (Index i = 0; i < positionsHelper.getPlayers()->size(); i++)
        playersNames->push_back( createIdentifierPtr(positionsHelper.retrievePlayer(i)) );

    Index maxPosition = payoffStorage.size();
    for (Index i = 0; i < maxPosition; i++)
        if (payoffStorageAllocation[i]) {
            IdentifierPtr  name       = createIdentifierPtr("Value");
            PositionsPtr   positions  = positionsHelper.retrievePositions(i);
            NumbersPtr     numbers    = payoffStorage[i];
            IdentifiersPtr strategies = createIdentifiersPtr();
            MessagesPtr    numbersStr = createMessagesPtr();

            BOOST_FOREACH(IdentifierPtr playerName, (*playersNames)) {
                strategies->push_back( createIdentifierPtr((*positions)[*playerName]) );
                numbersStr->push_back( createMessagePtr( (*numbers)[positionsHelper.calculatePlayer(playerName)] ) );
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

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
