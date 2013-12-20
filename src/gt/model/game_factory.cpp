#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class GameFactory {

GameFactory& GameFactory::getInstance() {
    static GameFactory instance;
    return instance;
}

// public:

GameBuilderPtr GameFactory::buildStrategicGame() const {
    return GameBuilderPtr(new StrategicGameBuilder());
}

GameBuilderPtr GameFactory::buildExtensiveGame() const {
    return GameBuilderPtr(new ExtensiveGameBuilder());
}

// private:

GameFactory::GameFactory() {}

GameFactory::~GameFactory() {}

// }; /* END class GameFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
