#ifndef __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__
#define __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Coordinates via CheckingDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 */
class CheckingCoordinateDriver : public virtual Root {
public:
    /**
     * @brief Creates coordinate.
     *
     * @param player   dimension (Player)
     * @param strategy position (strategy)
     * @return         coordinate
     */
    virtual CoordinatePtr* create(
        const IdentifierPtr* player,
        const IdentifierPtr* strategy
    );

    /**
     * @brief Fills Coordinate with subcoordinates.
     *
     * @param coordinate coordinate to fill
     * @param data       data to insert
     * @return           coordinate
     */
    virtual CoordinatePtr* fillWithData(
        const CoordinatePtr*  coordinate,
        const CoordinatesPtr* data
    );

    /**
     * @brief Fills Coordinate with Params.
     *
     * @param coordinate coordinate to fill
     * @param data       data to insert
     * @return           coordinate
     */
    virtual CoordinatePtr* fillWithData(
        const CoordinatePtr* coordinate,
        const ParamsPtr*     data
    );

    /**
     * @brief Merge two coordinates into one.
     *
     * @param coordinate1 first coorinate
     * @param coordinate2 second coorinate
     * @return            merged coordinates
     */
    virtual CoordinatePtr* merge(
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

//////////////////////////////////////////////////////1//////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__ */
