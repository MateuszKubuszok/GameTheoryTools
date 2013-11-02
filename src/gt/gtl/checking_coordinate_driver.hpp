#ifndef __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__
#define __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Coordinates via CheckingDriver.
 *
 * <p>Performs only syntax/type checking on Coordinates' tokens.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see CoordinateDriver
 */
class CheckingCoordinateDriver : public CoordinateDriver {
    /**
     * @brief Implementation of a main Driver.
     */
    Driver* driver;

public:
    /**
     * @brief Initiates CheckingCoordinateDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    CheckingCoordinateDriver(
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
     * @brief CheckingCoordinateDriver message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class CheckingCoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__ */
