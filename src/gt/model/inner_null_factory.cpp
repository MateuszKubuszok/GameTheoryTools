#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class InnerNullFactory {

InnerNullFactory& InnerNullFactory::getInstance() {
    static InnerNullFactory instance;
    return instance;
}

// public:

StrategicDataPtr InnerNullFactory::createStrategicData() {
    return StrategicDataPtr(new NullStrategicData());
}

ExtensiveDataPtr InnerNullFactory::createExtensiveData() {
    return ExtensiveDataPtr(new NullExtensiveData());
}

ExtensiveDataNodePtr InnerNullFactory::createExtensiveDataNode() {
    return ExtensiveDataNodePtr(new NullExtensiveDataNode());
}

// private:

InnerNullFactory::InnerNullFactory() {}

InnerNullFactory::~InnerNullFactory() {}

// }; /* END class InnerNullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
