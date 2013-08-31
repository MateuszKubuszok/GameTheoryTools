#ifndef __GT_GTL_COMMON_HPP__
#define __GT_GTL_COMMON_HPP__

/* Includes GT model headers  */
#include "gt/model/common.hpp"

/* Class declarations */
class Object;
class Condition;
class ConditionFactory;
class Coordinate;
class Definition;
class Details;
class Game;
class Query;
class Param;
class Player; 

/* Includes GTL elements headers */
#include "gt/gtl/object.hpp"
#include "gt/gtl/condition.hpp"
#include "gt/gtl/condition_factory.hpp"
#include "gt/gtl/coordinate.hpp"
#include "gt/gtl/definition.hpp"
#include "gt/gtl/details.hpp"
#include "gt/gtl/game.hpp"
#include "gt/gtl/query.hpp"
#include "gt/gtl/param.hpp"
#include "gt/gtl/player.hpp"

/* Includes GTL parsers elements */
#include "gt/gtl/driver.hpp"
#include "gt/gtl/scanner.hpp"
#include "gt/gtl/parser.hpp"

namespace GT {
namespace GTL {

/* Shortens commonly used names */
typedef boost::containers::map<Identifier, Identifier> Positions;
typedef boost::containers::vector<Condition>           Conditions;
typedef boost::containers::vector<Coordinate>          Coordinates;
typedef boost::containers::vector<Objects>             Objects;
typedef boost::containers::vector<Param>               Params;
typedef Model::Result                                  Result;

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_COMMON_HPP__ */
