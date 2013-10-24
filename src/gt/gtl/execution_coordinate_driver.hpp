#ifndef __GT_GTL_EXECUTION_COORDINATE_DRIVER_HPP__
#define __GT_GTL_EXECUTION_COORDINATE_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Coordinates via ExecutionDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see CoordinateDriver
 */
class ExecutionCoordinateDriver : public CoordinateDriver {
    Driver* driver;

public:
    /**
     * @brief Initiates ExecutionCoordinateDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    ExecutionCoordinateDriver(
        Driver* parentDriver
    );

    /**
     * @brief Creates coordinate.
     *
     * @param inputLocation input location of created Coordinate
     * @param player        dimension (Player)
     * @param strategy      position (strategy)
     * @return              Coordinate
     */
    virtual CoordinatePtr* create(
        InputLocation&       inputLocation,
        const IdentifierPtr* player,
        const IdentifierPtr* strategy
    );

    /**
     * @brief Fills Coordinate with subcoordinates.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate    Coordinate to fill
     * @param data          data to insert
     * @return              Coordinate
     */
    virtual CoordinatePtr* fillWithData(
        InputLocation&        inputLocation,
        const CoordinatePtr*  coordinate,
        const CoordinatesPtr* data
    );

    /**
     * @brief Fills Coordinate with Params.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate    Coordinate to fill
     * @param data          data to insert
     * @return              Coordinate
     */
    virtual CoordinatePtr* fillWithData(
        InputLocation&       inputLocation,
        const CoordinatePtr* coordinate,
        const ParamsPtr*     data
    );

    /**
     * @brief Merge two coordinates into one.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate1   first Coorinate
     * @param coordinate2   second Coorinate
     * @return              merged Coordinates
     */
    virtual CoordinatePtr* merge(
        InputLocation&       inputLocation,
        const CoordinatePtr* coordinate1,
        const CoordinatePtr* coordinate2
    );

    /**
     * @brief ExecutionCoordinateDriver message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class ExecutionCoordinateDriver */

//////////////////////////////////////////////////////1//////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_EXECUTION_COORDINATE_DRIVER_HPP__ */
