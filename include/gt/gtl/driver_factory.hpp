#ifndef __GT_GTL_DRIVER_FACTORY_HPP__
#define __GT_GTL_DRIVER_FACTORY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/driver_factory.hpp
 * @brief     Defines GT::GTL::DriverFactory class.
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

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class DriverFactory
 * @brief Used for creation of Error instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class DriverFactory final {
public:
    /**
     * @brief Returns the instance of a DriverFactory.
     *
     * @return DriverFactory instance
     */
    static DriverFactory& getInstance();

    /**
     * @brief Creates Driver that only checks errors.
     *
     * @param errorStream error stream to write out
     * @result            Driver
     */
    DriverPtr createCheckingDriver(
        OutputStream* errorStream
    ) const;

    /**
     * @brief Creates Driver that executes input.
     *
     * @param outputStream output stream to write out
     * @param errorStream  error stream to write out
     * @result             Driver
     */
    DriverPtr createExecutionDriver(
        OutputStream* outputStream,
        OutputStream* errorStream
    ) const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    DriverFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param driverFactory object to copy
     */
    DriverFactory(
        const DriverFactory& driverFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~DriverFactory();
}; /* END class DriverFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_DRIVER_FACTORY_HPP__ */
