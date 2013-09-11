#ifndef __GT_GTL_COMMON_HPP__
#define __GT_GTL_COMMON_HPP__

/* Includes GT model headers  */
#include "gt/model/common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/* Class declarations */

class NullFactory;

class Object;     class NullObject;
class Condition;  class NullCondition;
class Context;    class NullContext;
class Coordinate; class NullCoordinate;
class Definition; class NullDefinition;
class Details;    class NullDetails;
class Game;       class NullGame;
class Query;      class NullQuery;
class Param;      class NullParam;
class Player;     class NullPlayer;

class Parser;
class Scanner;
class Driver;     class NullDriver;

////////////////////////////////////////////////////////////////////////////////

/* Shortens commonly used names */

typedef boost::shared_ptr<Object>                     ObjectPtr;
typedef boost::shared_ptr<Condition>                  ConditionPtr;
typedef boost::shared_ptr<Context>                    ContextPtr;
typedef boost::shared_ptr<Coordinate>                 CoordinatePtr;
typedef boost::shared_ptr<Definition>                 DefinitionPtr;
typedef boost::shared_ptr<Details>                    DetailsPtr;
typedef boost::shared_ptr<Game>                       GamePtr;
typedef boost::shared_ptr<Query>                      QueryPtr;
typedef boost::shared_ptr<Param>                      ParamPtr;
typedef boost::shared_ptr<Player>                     PlayerPtr;

typedef boost::container::vector<ConditionPtr>        Conditions;
typedef boost::shared_ptr<Conditions>                 ConditionsPtr;
typedef boost::container::vector<CoordinatePtr>       Coordinates;
typedef boost::shared_ptr<Coordinates>                CoordinatesPtr;
typedef boost::container::vector<ObjectPtr>           Objects;
typedef boost::shared_ptr<Objects>                    ObjectsPtr;
typedef boost::container::vector<ParamPtr>            Params;
typedef boost::shared_ptr<Params>                     ParamsPtr;

typedef boost::shared_ptr<Parser>                     ParserPtr;
typedef boost::shared_ptr<Scanner>                    ScannerPtr;
typedef boost::shared_ptr<Driver>                     DriverPtr;

typedef Model::Root                                   Root;
typedef Model::Result                                 Result;
typedef Model::NullResult                             NullResult;
typedef Model::ResultPtr                              ResultPtr;
typedef Model::ResultFactory                          ResultFactory;

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

////////////////////////////////////////////////////////////////////////////////

/* Includes GTL elements headers */

#include "gt/gtl/null_factory.hpp"
#include "gt/gtl/object.hpp"
#include "gt/gtl/condition.hpp"
#include "gt/gtl/condition_factory.hpp"
#include "gt/gtl/context.hpp"
#include "gt/gtl/coordinate.hpp"
#include "gt/gtl/definition.hpp"
#include "gt/gtl/details.hpp"
#include "gt/gtl/game.hpp"
#include "gt/gtl/query.hpp"
#include "gt/gtl/param.hpp"
#include "gt/gtl/param_factory.hpp"
#include "gt/gtl/player.hpp"

/* Includes GTL parsers elements */

#include "gt/gtl/collections_driver.hpp"
#include "gt/gtl/coordinate_driver.hpp"
#include "gt/gtl/condition_driver.hpp"
#include "gt/gtl/game_driver.hpp"
#include "gt/gtl/value_driver.hpp"
#include "gt/gtl/statement_driver.hpp"
#include "gt/gtl/driver.hpp"
#include "gt/gtl/parser.hpp"
#include "gt/gtl/scanner.hpp"

////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_GTL_COMMON_HPP__ */
