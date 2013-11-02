#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class DriverFactory {

SINGLETON_DEFINITION(DriverFactory, getInstance, driverFactoryMutex)

// public:

DriverPtr DriverFactory::createCheckingDriver(
    OutputStream* errorStream
) {
    return DriverPtr(new CheckingDriver(errorStream));
}

DriverPtr DriverFactory::createExecutionDriver(
    OutputStream* outputStream,
    OutputStream* errorStream
) {
    return DriverPtr(new ExecutionDriver(outputStream, errorStream));
}

// private:

DriverFactory::DriverFactory() {}

DriverFactory::~DriverFactory() {}

// }; /* END class DriverFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
