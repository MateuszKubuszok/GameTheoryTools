#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PlainData { 
// public:

PlainData::PlainData(
    PlayersPtr players
) :
    positionsHelper(players),
    paramsStorage(),
    paramsStorageAllocation()
{
    Index maxPosition = positionsHelper.getUpperBound();
    for (Index i = 0; i < maxPosition; i++) {
        paramsStorage.push_back( NullFactory::getInstance().createNumbers() );
        paramsStorageAllocation.push_back( false );
    }
}

PlayersPtr PlainData::getPlayers() {
    return positionsHelper.getPlayers();
}

DataPiecePtr PlainData::getValues(
    Index positionInStorage
) {
    if (!paramsStorageAllocation[positionInStorage])
        throw ExceptionFactory::getInstance()
                .noParamsForPositions(
                    positionInStorage,
                    positionsHelper.getUpperBound()
                );
    
    return DataPiecePtr(
        new PlainDataPiece(
            positionsHelper.getPlayers(),
            paramsStorage[positionInStorage]
        )
    );
}

DataPiecePtr PlainData::getValues(
    Positions& positions
) {
    return getValues(positionsHelper.calculatePosition(positions));
}

DataPiecePtr PlainData::getValues(
    PositionsPtr positions
) {
    return getValues(*positions);
}

Data& PlainData::setValues(
    Index      positionInStorage,
    NumbersPtr numbers
) {
    paramsStorage[positionInStorage] = numbers;
    paramsStorageAllocation[positionInStorage] = true;

    return *this;
}

Data& PlainData::setValues(
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

Data& PlainData::setValues(
    PositionsPtr positions,
    NumbersPtr   numbers
) {
    return setValues(*positions, numbers);
}

DataPiecePtr PlainData::operator[](
    Index positionInStorage
) {
    return getValues(positionInStorage);
}

DataPiecePtr PlainData::operator[](
    Positions& positions
) {
    return getValues(positions);
}

DataPiecePtr PlainData::operator[](
    PositionsPtr positions
) {
    return getValues(positions);
}

Message PlainData::toString() {
    return contentMessage()->getResult();
}

// private:

ResultPtr PlainData::contentMessage() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    IdentifierPtr positionName = createIdentifierPtr("Position");
    IdentifierPtr payoffName   = createIdentifierPtr("Payoff");
    IdentifiersPtr playersNames = createIdentifiersPtr();
    for (Index i = 0; i < positionsHelper.getPlayers()->size(); i++)
        playersNames->push_back( createIdentifierPtr(positionsHelper.retrievePlayer(i)) );

    Index maxPosition = paramsStorage.size();
    for (Index i = 0; i < maxPosition; i++)
        if (paramsStorageAllocation[i]) {
            IdentifierPtr  name       = createIdentifierPtr("Value");
            PositionsPtr   positions  = positionsHelper.retrievePositions(i);
            NumbersPtr     numbers    = paramsStorage[i];
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

    return resultBuilder->build();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
