#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

boost::mutex innerNullFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class NullFactory {

InnerNullFactory* volatile InnerNullFactory::instance = 0;

// public:

InnerNullFactory& InnerNullFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(innerNullFactoryMutex);
        if (!instance) {
            InnerNullFactory* volatile tmp = new InnerNullFactory();
            instance = tmp;
        }
    }
    return *instance;
}

StrategicDataPtr InnerNullFactory::createStrategicData() {
    return StrategicDataPtr(new NullStrategicData());
}

TreeDataPtr InnerNullFactory::createTreeData() {
    return TreeDataPtr(new NullTreeData());
}

// private:

InnerNullFactory::InnerNullFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
