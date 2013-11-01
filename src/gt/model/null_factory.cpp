#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NullFactory {

SINGLETON_DEFINITION(NullFactory, getInstance, nullFactoryMutex)

// public:

IdentifierPtr NullFactory::createIdentifier() {
    return IdentifierPtr(new Identifier("NullIdentifier"));
}

IdentifiersPtr NullFactory::createIdentifiers() {
    return IdentifiersPtr(new Identifiers());
}

MessagePtr NullFactory::createMessage() {
    return MessagePtr(new Message("NullMessage"));
}

MessagesPtr NullFactory::createMessages() {
    return MessagesPtr(new Messages());
}

NumberPtr NullFactory::createNumber() {
    return NumberPtr(new Number(0));
}

NumbersPtr NullFactory::createNumbers() {
    return NumbersPtr(new Numbers());
}

PlayerPtr NullFactory::createPlayer() {
    return PlayerPtr(new NullPlayer());
}

PlayersPtr NullFactory::createPlayers() {
    return PlayersPtr(new Players());
}

DataPtr NullFactory::createData() {
    return DataPtr(new NullData());
}

DataAccessorPtr NullFactory::createDataAccessor() {
    return DataAccessorPtr(new NullDataAccessor());
}

DataPiecePtr NullFactory::createDataPiece() {
    return DataPiecePtr(new NullDataPiece());
}

DataBuilderPtr NullFactory::createDataBuilder() {
    return DataBuilderPtr(new NullDataBuilder());
}

GamePtr NullFactory::createGame() {
    return GamePtr(new NullGame());
}

GameBuilderPtr NullFactory::createGameBuilder() {
    return GameBuilderPtr(new NullGameBuilder());
}

ResultPtr NullFactory::createResult() {
    return ResultPtr(new NullResult());
}

ResultBuilderPtr NullFactory::createResultBuilder() {
    return ResultBuilderPtr(new NullResultBuilder());
}

// private:

NullFactory::NullFactory() {}

NullFactory::~NullFactory() {}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
