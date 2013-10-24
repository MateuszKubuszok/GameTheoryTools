#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class ExtensiveDataBuilder {
// public:

ExtensiveDataBuilder::ExtensiveDataBuilder() :
    data(InnerNullFactory::getInstance().createExtensiveData()),
    players(NullFactory::getInstance().createPlayers()),
    currentPositions(),
    depthValue(1),
    depthName(createIdentifier(1))
    {}

ExtensiveDataPtr ExtensiveDataBuilder::build() {
    return data;
}

PlayersPtr ExtensiveDataBuilder::getPlayers() {
    return players;
}

DataBuilder& ExtensiveDataBuilder::setPlayers(
    PlayersPtr newPlayers
) {
    if (data->isNotNull())
        throw ExceptionFactory::getInstance()
                .playersAlreadySet();

    data    = ExtensiveDataPtr(new ExtensiveData(newPlayers));
    players = newPlayers;

    return *this;
}

DataBuilder& ExtensiveDataBuilder::addNextPositions(
    PositionsPtr positions
) {
    if (positions->size() != 1)
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(*positions);

    PlayersInTurnsPtr playersInTurns  = data->getPlayersInTurns();
    Identifier        currentPlayer   = positions->begin()->first;
    Identifier        currentStrategy = positions->begin()->second;
    if (playersInTurns->count(depthName) && (*(*playersInTurns)[depthName]->getName()) != currentPlayer)
        throw ExceptionFactory::getInstance().invalidExtensiveCoordinateFormat(*positions);

    if (!playersInTurns->count(depthName))
        playersInTurns->insert( PlayersInTurns::value_type(depthName, (*players)[currentPlayer]) );

    currentPositions.insert( Positions::value_type(depthName, currentStrategy) );
    depthName = createIdentifier(++depthValue);

    return *this;
}

DataBuilder& ExtensiveDataBuilder::setParams(
    NumbersPtr params
) {
    data->setValues(currentPositions, params);
    return *this;
}

DataBuilderPtr ExtensiveDataBuilder::clone() {
    return DataBuilderPtr(new ExtensiveDataBuilder(*this));
}

Message ExtensiveDataBuilder::toString() {
    IdentifierPtr name    = createIdentifierPtr("Current Data");
    MessagePtr    message = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
