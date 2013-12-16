#ifndef __GT_GTL_EXECUTION_COORDINATE_DRIVER_HPP__
#define __GT_GTL_EXECUTION_COORDINATE_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Coordinates via ExecutionDriver.
 *
 * <p>Performs actual execution of instructions for Coordinates.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see CoordinateDriver
 */
class ExecutionCoordinateDriver final : public CoordinateDriver {
    /**
     * @brief Driver for error handling.
     */
    CheckingCoordinateDriver checkingCoordinateDriver;
    /**
     * @brief Implementation of a main Driver.
     */
    Driver*                  driver;

public:
    /**
     * @brief Initiates ExecutionCoordinateDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit ExecutionCoordinateDriver(
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
        const InputLocation& inputLocation,
        const IdentifierPtr* player,
        const IdentifierPtr* strategy
    ) const override;

    /**
     * @brief Fills Coordinate with subcoordinates.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate    Coordinate to fill
     * @param data          data to insert
     * @return              Coordinate
     */
    virtual CoordinatePtr* fillWithData(
        const InputLocation&  inputLocation,
        const CoordinatePtr*  coordinate,
        const CoordinatesPtr* data
    ) const override;

    /**
     * @brief Fills Coordinate with Params.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate    Coordinate to fill
     * @param data          data to insert
     * @return              Coordinate
     */
    virtual CoordinatePtr* fillWithData(
        const InputLocation& inputLocation,
        const CoordinatePtr* coordinate,
        const ParamsPtr*     data
    ) const override;

    /**
     * @brief Merge two coordinates into one.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate1   first Coorinate
     * @param coordinate2   second Coorinate
     * @return              merged Coordinates
     */
    virtual CoordinatePtr* merge(
        const InputLocation& inputLocation,
        const CoordinatePtr* coordinate1,
        const CoordinatePtr* coordinate2
    ) const override;

    /**
     * @brief ExecutionCoordinateDriver message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class ExecutionCoordinateDriver */

//////////////////////////////////////////////////////1///////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_EXECUTION_COORDINATE_DRIVER_HPP__ */
