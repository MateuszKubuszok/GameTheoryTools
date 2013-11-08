#ifndef __GT_GTL_COORDINATE_DRIVER_HPP__
#define __GT_GTL_COORDINATE_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
     * @param inputLocation input location of created Coordinate
     * @param player        dimension (Player)
     * @param strategy      position (strategy)
     * @return              Coordinate
     */
    virtual CoordinatePtr* create(
        InputLocation&       inputLocation,
        const IdentifierPtr* player,
        const IdentifierPtr* strategy
    ) = 0;

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
    ) = 0;

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
    ) = 0;

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
    ) = 0;

    /**
     * @brief CoordinateDriver message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class CoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        InputLocation& inputLocation,
        const IdentifierPtr*,
        const IdentifierPtr*
    ) override {
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                NullFactory::getInstance().createCoordinate(),
                inputLocation
            )
        );
    }

    virtual CoordinatePtr* fillWithData(
        InputLocation& inputLocation,
        const CoordinatePtr*,
        const CoordinatesPtr*
    ) override {
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                NullFactory::getInstance().createCoordinate(),
                inputLocation
            )
        );
    }

    virtual CoordinatePtr* fillWithData(
        InputLocation& inputLocation,
        const CoordinatePtr*,
        const ParamsPtr*
    ) override {
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                NullFactory::getInstance().createCoordinate(),
                inputLocation
            )
        );
    }

    virtual CoordinatePtr* merge(
        InputLocation& inputLocation,
        const CoordinatePtr*,
        const CoordinatePtr*
    ) override {
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                NullFactory::getInstance().createCoordinate(),
                inputLocation
            )
        );
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullCoordinateDriver");
    }
}; /* END class NullCoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_COORDINATE_DRIVER_HPP__ */
