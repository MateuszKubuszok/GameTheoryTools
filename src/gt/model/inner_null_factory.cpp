#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class InnerNullFactory {

SINGLETON_DEFINITION(InnerNullFactory, getInstance, innerNullFactoryMutex)

// public:

StrategicDataPtr InnerNullFactory::createStrategicData() {
    return StrategicDataPtr(new NullStrategicData());
}

ExtensiveDataPtr InnerNullFactory::createExtensiveData() {
    return ExtensiveDataPtr(new NullExtensiveData());
}

// private:

InnerNullFactory::InnerNullFactory() {}

InnerNullFactory::~InnerNullFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
