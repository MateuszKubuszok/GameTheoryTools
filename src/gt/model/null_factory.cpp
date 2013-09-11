#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

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
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(nullFactoryMutex);
        if (!instance) {
            NullFactory* volatile tmp = new NullFactory();
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
    return MessagePtr(new Identifier("NullMessage"));
}

NumberPtr NullFactory::createNumber() {
    return NumberPtr(new Number(0));
}

PlayerPtr NullFactory::createPlayer() {
    return PlayerPtr(new NullPlayer());
}

PlayersPtr NullFactory::createPlayers() {
    return PlayersPtr(new Players());
}

GamePtr NullFactory::createGame() {
    return GamePtr(new NullGame());
}

DataBuilderPtr NullFactory::createDataBuilder() {
    return DataBuilderPtr(new NullDataBuilder());
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
