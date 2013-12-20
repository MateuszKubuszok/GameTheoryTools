#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NullFactory {

NullFactory& NullFactory::getInstance() {
    static NullFactory instance;
    return instance;
}

// public:

IdentifierPtr NullFactory::createIdentifier() const {
    return IdentifierPtr(new Identifier("NullIdentifier"));
}

IdentifiersPtr NullFactory::createIdentifiers() const {
    return IdentifiersPtr(new Identifiers());
}

MessagePtr NullFactory::createMessage() const {
    return MessagePtr(new Message("NullMessage"));
}

MessagesPtr NullFactory::createMessages() const {
    return MessagesPtr(new Messages());
}

NumberPtr NullFactory::createNumber() const {
    return NumberPtr(new Number(0));
}

NumbersPtr NullFactory::createNumbers() const {
    return NumbersPtr(new Numbers());
}

PlayerPtr NullFactory::createPlayer() const {
    return PlayerPtr(new NullPlayer());
}

PlayersPtr NullFactory::createPlayers() const {
    return PlayersPtr(new Players());
}

DataPtr NullFactory::createData() const {
    return DataPtr(new NullData());
}

DataAccessorPtr NullFactory::createDataAccessor() const {
    return DataAccessorPtr(new NullDataAccessor());
}

DataPiecePtr NullFactory::createDataPiece() const {
    return DataPiecePtr(new NullDataPiece());
}

DataBuilderPtr NullFactory::createDataBuilder() const {
    return DataBuilderPtr(new NullDataBuilder());
}

GamePtr NullFactory::createGame() const {
    return GamePtr(new NullGame());
}

GameBuilderPtr NullFactory::createGameBuilder() const {
    return GameBuilderPtr(new NullGameBuilder());
}

ResultPtr NullFactory::createResult() const {
    return ResultPtr(new NullResult());
}

ResultBuilderPtr NullFactory::createResultBuilder() const {
    return ResultBuilderPtr(new NullResultBuilder());
}

// private:

NullFactory::NullFactory() {}

NullFactory::~NullFactory() {}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
