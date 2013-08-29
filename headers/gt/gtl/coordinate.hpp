#ifndef __GT_GTL_COORDINATE_HPP__
#define __GT_GTL_COORDINATE_HPP__ 1

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

class Coordinate {
public:
	Coordinate() :
		positions(),
		params(),
		subCoordinates();

	Coordinate(
		Identifier& player,
		Identifier& strategy
	) :
		positions(),
		params(),
		subCoordinates();

	Coordiante& addParams(
		Param& param
	);

	Coordiante& addParams(
		Params& params
	);

	Coordinate& addPosition(
		Identifier& player,
		Identifier& strategy
	);

	Coordinate& addSubCoordinates(
		Coordinate& subCoordinate
	);

	Coordinate& addSubCoordinates(
		Coordinates& subCoordinate
	);

	Params getParams();

	Positions getPositions();

	Coordinates getSubCoordinates();

private:
	Positions positions;

	Params params;

	Coordinates subCoordinates;
}

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_COORDINATE_HPP__ */
