#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class DriverFactory {

DriverFactory& DriverFactory::getInstance() {
    static DriverFactory instance;
    return instance;
}

// public:

DriverPtr DriverFactory::createCheckingDriver(
    OutputStream* errorStream
) const {
    return DriverPtr(new CheckingDriver(errorStream));
}

DriverPtr DriverFactory::createExecutionDriver(
    OutputStream* outputStream,
    OutputStream* errorStream
) const {
    return DriverPtr(new ExecutionDriver(outputStream, errorStream));
}

// private:

DriverFactory::DriverFactory() {}

DriverFactory::~DriverFactory() {}

// }; /* END class DriverFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
