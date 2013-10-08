#ifndef __GT_GTL_COORDINATE_DRIVER_HPP__
#define __GT_GTL_COORDINATE_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for handling Coordinates via Driver.
 *
 * @author Mateusz Kubuszok
 */
class CoordinateDriver : public virtual Root {
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
    ) = 0;

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
    ) = 0;

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
    ) = 0;

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
    ) = 0;

    /**
     * @brief CoordinateDriver message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class CoordinateDriver */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null CoordinateDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCoordinateDriver : public CoordinateDriver {
public:
    NullCoordinateDriver() :
        CoordinateDriver()
        {}

    virtual CoordinatePtr* create(
        const IdentifierPtr* player,
        const IdentifierPtr* strategy
    ) {
        return new CoordinatePtr(NullFactory::getInstance().createCoordinate());
    }

    virtual CoordinatePtr* fillWithData(
        const CoordinatePtr*  coordinate,
        const CoordinatesPtr* data
    ) {
        return new CoordinatePtr(NullFactory::getInstance().createCoordinate());
    }

    virtual CoordinatePtr* fillWithData(
        const CoordinatePtr* coordinate,
        const ParamsPtr*     data
    ) {
        return new CoordinatePtr(NullFactory::getInstance().createCoordinate());
    }

    virtual CoordinatePtr* merge(
        const CoordinatePtr* coordinate1,
        const CoordinatePtr* coordinate2
    ) {
        return new CoordinatePtr(NullFactory::getInstance().createCoordinate());
    }

    virtual Message toString() {
        return Message("NullCoordinateDriver");
    }
}; /* END class NullCoordinateDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_COORDINATE_DRIVER_HPP__ */