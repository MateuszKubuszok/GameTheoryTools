/**
 * @file      gt/gtl/driver_factory.cpp
 * @brief     Defines GT::GTL::DriverFactory methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class DriverFactory {
// public:

DriverFactory& DriverFactory::getInstance() {
    static DriverFactory instance;
    return instance;
}

DriverPtr DriverFactory::createCheckingDriver(
    OutputStream* errorStream
) const {
    return make_shared<CheckingDriver>(errorStream);
}

DriverPtr DriverFactory::createExecutionDriver(
    OutputStream* outputStream,
    OutputStream* errorStream
) const {
    return make_shared<ExecutionDriver>(outputStream, errorStream);
}

// }; /* END class DriverFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
