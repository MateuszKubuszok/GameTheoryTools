#ifndef __GT_GTL_DRIVER_FACTORY_HPP__
#define __GT_GTL_DRIVER_FACTORY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Error instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class DriverFactory {
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
     * @param object to copy
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
