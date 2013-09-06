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

MessagePtr NullFactory::createMessage() {
    return MessagePtr(new Identifier("NullMessage"));
}

NumberPtr NullFactory::createNumber() {
    return NumberPtr(new Number(0));
}

PlayerPtr NullFactory::createPlayer() {
    return PlayerPtr(new NullPlayer());
}

ResultPtr NullFactory::createResult() {
    return ResultPtr(new NullResult());
}

// private:
NullFactory::NullFactory() {}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
