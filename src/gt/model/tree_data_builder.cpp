#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class TreeDataBuilder {
// public:

TreeDataBuilder::TreeDataBuilder() :
    data(InnerNullFactory::getInstance().createTreeData()),
    players(NullFactory::getInstance().createPlayers()),
    currentPositions(),
    depthValue(1),
    depthName(createIdentifier(1))
    {}

TreeDataPtr TreeDataBuilder::build() {
    return data;
}

PlayersPtr TreeDataBuilder::getPlayers() {
    return players;
}

DataBuilder& TreeDataBuilder::setPlayers(
    PlayersPtr newPlayers
) {
    if (data->isNotNull())
        throw ExceptionFactory::getInstance()
                .playersAlreadySet();

    data    = TreeDataPtr(new TreeData(newPlayers));
    players = newPlayers;

    return *this;
}

DataBuilder& TreeDataBuilder::addNextPositions(
    PositionsPtr positions
) {
    if (positions->size() != 1)
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(*positions);

    PlayersInTurnsPtr playersInTurns  = data->getPlayersInTurns();
    Identifier        currentPlayer   = positions->begin()->first;
    Identifier        currentStrategy = positions->begin()->second;
    if (playersInTurns->count(depthName) && (*(*playersInTurns)[depthName]->getName()) != currentPlayer)
        throw ExceptionFactory::getInstance().invalidTreeCoordinateFormat(*positions);

    if (!playersInTurns->count(depthName))
        playersInTurns->insert( PlayersInTurns::value_type(depthName, (*players)[currentPlayer]) );

    currentPositions.insert( Positions::value_type(depthName, currentStrategy) );
    depthName = createIdentifier(++depthValue);

    return *this; 
}

DataBuilder& TreeDataBuilder::setParams(
    NumbersPtr params
) {
    data->setValues(currentPositions, params);
    return *this;
}

DataBuilderPtr TreeDataBuilder::clone() {
    return DataBuilderPtr(new TreeDataBuilder(*this));
}

Message TreeDataBuilder::toString() {
    IdentifierPtr name    = createIdentifierPtr("Current Data");
    MessagePtr    message = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
