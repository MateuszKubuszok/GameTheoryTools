#ifndef __GT_GTL_COORDINATE_HPP__
#define __GT_GTL_COORDINATE_HPP__ 1

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

class Coordinate {
public:
	/**
	 * @brief Default constructor.
	 */
	Coordinate() :
		positions(),
		params(),
		subCoordinates();

	/**
	 * @brief Constructor for initial strategies.
	 *
	 * @param player   player   identifier
	 * @param strategy strategy identifier
	 */
	Coordinate(
		const Identifier& player,
		const Identifier& strategy
	) :
		positions(),
		params(),
		subCoordinates();

	/**
	 * @brief Adds param to the list.
	 *
	 * @param param single Param
	 * @return      reference to itself
	 */
	Coordinate& addParams(
		const Param& param
	);

	 /**
	 * @brief Adds params to the list.
	 *
	 * @param params Params' vector
	 * @return       reference to itself
	 */
	Coordinate& addParams(
		const Params& params
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

private:
	/**
	 * @brief Defined positions.
	 */
	const Positions positions;

	/**
	 * @brief Defined Params.
	 */
	const Params params;

	/**
	 * @brief Defined subcoordinetes. 
	 */
	const Coordinates subCoordinates;
} /* END class Coordinate */

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

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_COORDINATE_HPP__ */
