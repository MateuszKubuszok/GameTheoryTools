#ifndef __GT_GTL_COORDINATE_HPP__
#define __GT_GTL_COORDINATE_HPP__

namespace GT {
namespace GTL {

/**
 * @brief Contains some coordinate as well as data boind to it.
 *
 * @author Mateusz Kubuszok
 */
class Coordinate : public virtual Root {
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
     * @brief Defined Positions.
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
     * @brief Adds Param to the list.
     *
     * @param param single Param
     * @return      reference to itself
     */
    Coordinate& addParams(
        const ParamPtr param
    );

     /**
     * @brief Adds Params to the list.
     *
     * @param params Params' vector
     * @return       reference to itself
     */
    Coordinate& addParams(
        const ParamsPtr params
    );

    /**
     * @brief Add Position to known Coordinates.
     *
     * @param player   player (dimension)
     * @param strategy strategy (position on dimension)
     * @return         reference to itself
     */
    Coordinate& addPosition(
        const Identifier& player,
        const Identifier& strategy
    );

    /**
     * @brief Adds SubCoordinate.
     *
     * @param subCoordinate SubCoordinate
     * @return              reference to itself
     */
    Coordinate& addSubCoordinates(
        const Coordinate& subCoordinate
    );

    /**
     * @brief Adds SubCoordinates.
     *
     * @param subCoordinates SubCoordinate
     * @return               reference to itself
     */
    Coordinate& addSubCoordinates(
        const Coordinates& subCoordinates
    );

    /**
     * @brief Obtains params.
     *
     * @return Params
     */
    Params getParams();

     /**
     * @brief Obtains Positions.
     *
     * @return Positions
     */
    Positions getPositions();

    /**
     * @brief Obtain SubCoordinates.
     *
     * @return SubCoordinates
     */
    Coordinates getSubCoordinates();
}; /* END class Coordinate */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_COORDINATE_HPP__ */
