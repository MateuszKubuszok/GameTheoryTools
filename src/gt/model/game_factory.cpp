#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class GameFactory {

SINGLETON_DEFINITION(GameFactory, getInstance, gameFactoryMutex)

// public:

GameBuilderPtr GameFactory::buildStrategicGame() {
    return GameBuilderPtr(new StrategicGameBuilder());
}

GameBuilderPtr GameFactory::buildTreeGame() {
    return GameBuilderPtr(new TreeGameBuilder());
}

// private:

GameFactory::GameFactory() {}

GameFactory::~GameFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
