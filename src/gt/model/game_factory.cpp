#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

boost::mutex gameFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {
GameFactory* volatile GameFactory::instance = 0;

// public:
GameFactory& GameFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(gameFactoryMutex);
        if (!instance) {
            GameFactory* volatile tmp = new GameFactory();
            instance = tmp;
        }
    }
    return *instance;
}

GameBuilderPtr GameFactory::buildPureGame() {
	// TODO
	return NullFactory::getInstance().createGameBuilder();
}

GameBuilderPtr GameFactory::buildMixedGame() {
	// TODO
	return NullFactory::getInstance().createGameBuilder();
}

GameBuilderPtr GameFactory::buildTreeGame() {
	// TODO
	return NullFactory::getInstance().createGameBuilder();
}

// private:
GameFactory::GameFactory() {}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
