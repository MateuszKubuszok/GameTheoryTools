#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

boost::mutex nullFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class NullFactory {

NullFactory* volatile NullFactory::instance = 0;

// public:

NullFactory& NullFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking".
    if (!instance) {
        boost::mutex::scoped_lock lock(nullFactoryMutex);
        if (!instance) {
            NullFactory* volatile tmp = (NullFactory*) malloc(sizeof(NullFactory));
            new (tmp) NullFactory; // placement new
            instance = tmp;
        }
    }
    return *instance;
}

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

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
