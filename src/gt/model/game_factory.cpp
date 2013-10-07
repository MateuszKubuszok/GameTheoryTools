#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

boost::mutex gameFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class GameFactory {

GameFactory* volatile GameFactory::instance = 0;

// public:

GameFactory& GameFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking".
    if (!instance) {
        boost::mutex::scoped_lock lock(gameFactoryMutex);
        if (!instance) {
            GameFactory* volatile tmp = (GameFactory*) malloc(sizeof(GameFactory));
            new (tmp) GameFactory; // placement new
            instance = tmp;
        }
    }
    return *instance;
}

GameBuilderPtr GameFactory::buildStrategicGame() {
    return GameBuilderPtr(new StrategicGameBuilder());
}

GameBuilderPtr GameFactory::buildTreeGame() {
    return GameBuilderPtr(new TreeGameBuilder());
}

// private:

GameFactory::GameFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
