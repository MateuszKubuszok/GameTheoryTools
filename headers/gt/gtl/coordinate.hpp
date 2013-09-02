#ifndef __GT_GTL_COORDINATE_HPP__
#define __GT_GTL_COORDINATE_HPP__

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Contains some coordinate as well as data boind to it.
 *
 * @author Mateusz Kubuszok
 */
class Coordinate {
    /**
     * @brief Merges two Coordinates into one.
     *
     * @param coordinate1 first coordinate
     * @param coordinate2 second coordinate
     * @return            merged coordinates
     */
    friend Coordinate operator+(
        const Coordinate& coordinate1,
        const Coordinate& coordinate2
    );

    /**
     * @brief Defined positions.
     */
    const Positions positions;

    /**
     * @brief Defined Params.
     */
    const ParamsPtr params;

    /**
     * @brief Defined subcoordinetes. 
     */
    const CoordinatesPtr subCoordinates;

public:
    /**
     * @brief Default constructor.
     */
    Coordinate();

    /**
     * @brief Constructor for initial strategies.
     *
     * @param player   player   identifier
     * @param strategy strategy identifier
     */
    Coordinate(
        const Identifier& player,
        const Identifier& strategy
    );

    /**
     * @brief Adds param to the list.
     *
     * @param param single Param
     * @return      reference to itself
     */
    Coordinate& addParams(
        const ParamPtr param
    );

     /**
     * @brief Adds params to the list.
     *
     * @param params Params' vector
     * @return       reference to itself
     */
    Coordinate& addParams(
        const ParamsPtr params
    );

    Coordinate& addPosition(
        const Identifier& player,
        const Identifier& strategy
    );

    /**
     * @brief
     *
     * @param
     * @return
     */
    Coordinate& addSubCoordinates(
        const Coordinate& subCoordinate
    );

    /**
     * @brief
     *
     * @param
     * @return
     */
    Coordinate& addSubCoordinates(
        const Coordinates& subCoordinate
    );

    /**
     * @brief
     *
     * @return
     */
    Params getParams();

     /**
     * @brief
     *
     * @return
     */
    Positions getPositions();

    /**
     * @brief
     *
     * @return
     */
    Coordinates getSubCoordinates();
}; /* END class Coordinate */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_COORDINATE_HPP__ */
