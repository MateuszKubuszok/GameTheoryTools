#ifndef __GT_GTL_COMMON_HPP__
#define __GT_GTL_COMMON_HPP__

/* Includes GT model headers  */
#include "gt/model/common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/* Exceptions declarations */

class InvalidProperty;

/* Class declarations */

class ValidableSymbol;   class NullFactory;          class ErrorFactory;

class Object;            class NullObject;           class ErrorObject;
class ObjectProperty;
class Condition;         class NullCondition;        class ErrorCondition;
class Coordinate;        class NullCoordinate;       class ErrorCoordinate;
class Definition;        class NullDefinition;       class ErrorDefinition;
class Details;           class NullDetails;          class ErrorDetails;
class Game;              class NullGame;             class ErrorGame;
class Param;             class NullParam;            class ErrorParam;
class Player;            class NullPlayer;           class ErrorPlayer;
class Query;             class NullQuery;            class ErrorQuery;

class Context;           class NullContext;

class Parser;
class Scanner;
class Driver;            class NullDriver;
class ConditionDriver;   class NullConditionDriver;
class CoordinateDriver;  class NullCoordinateDriver;
class GameDriver;        class NullGameDriver;
class ValueDriver;       class NullValueDriver;
class StatementDriver;   class NullStatementDriver;

template <typename Content> class CollectionsDriver;
template <typename Content> class NullCollectionsDriver;

////////////////////////////////////////////////////////////////////////////////

/* Shortens commonly used names */

typedef boost::shared_ptr<Object>                     ObjectPtr;
typedef boost::shared_ptr<ObjectProperty>             ObjectPropertyPtr;
typedef boost::shared_ptr<Condition>                  ConditionPtr;
typedef boost::shared_ptr<Context>                    ContextPtr;
typedef boost::shared_ptr<Coordinate>                 CoordinatePtr;
typedef boost::shared_ptr<Definition>                 DefinitionPtr;
typedef boost::shared_ptr<Details>                    DetailsPtr;
typedef boost::shared_ptr<Game>                       GamePtr;
typedef boost::shared_ptr<Query>                      QueryPtr;
typedef boost::shared_ptr<Param>                      ParamPtr;
typedef boost::shared_ptr<Player>                     PlayerPtr;

typedef boost::container::vector<ConditionPtr>               Conditions;
typedef boost::shared_ptr<Conditions>                        ConditionsPtr;
typedef boost::container::vector<CoordinatePtr>              Coordinates;
typedef boost::shared_ptr<Coordinates>                       CoordinatesPtr;
typedef boost::container::vector<ObjectPtr>                  Objects;
typedef boost::shared_ptr<Objects>                           ObjectsPtr;
typedef boost::container::map<Identifier, ObjectPropertyPtr> ObjectPropertyMap;
typedef boost::container::vector<ParamPtr>                   Params;
typedef boost::shared_ptr<Params>                            ParamsPtr;

typedef boost::shared_ptr<Parser>                     ParserPtr;
typedef boost::shared_ptr<Scanner>                    ScannerPtr;
typedef boost::shared_ptr<Driver>                     DriverPtr;
typedef boost::shared_ptr<ConditionDriver>            ConditionDriverPtr;
typedef boost::shared_ptr<CoordinateDriver>           CoordinateDriverPtr;
typedef boost::shared_ptr<GameDriver>                 GameDriverPtr;
typedef boost::shared_ptr<ValueDriver>                ValueDriverPtr;
typedef boost::shared_ptr<StatementDriver>            StatementDriverPtr;

template<typename Content>
using CollectionsDriverPtr = boost::shared_ptr<CollectionsDriver<Content>>;

typedef Model::Root                                   Root;
typedef Model::Result                                 Result;
typedef Model::NullResult                             NullResult;
typedef Model::ResultPtr                              ResultPtr;

/* Declares functions for equality check */

bool operator==(Conditions&  conditions1,  Conditions&  conditions2);
bool operator!=(Conditions&  conditions1,  Conditions&  conditions2);
bool operator==(Coordinates& coordinates1, Coordinates& coordinates2);
bool operator!=(Coordinates& coordinates1, Coordinates& coordinates2);
bool operator==(Objects&     objects1,     Objects&     objects2);
bool operator!=(Objects&     objects1,     Objects&     objects2);
bool operator==(Params&      params1,      Params&      params2);
bool operator!=(Params&      params1,      Params&      params2);

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

////////////////////////////////////////////////////////////////////////////////

/* Includes GTL elements headers */

#include "gt/gtl/exceptions.hpp"

#include "gt/gtl/null_factory.hpp"
#include "gt/gtl/error_factory.hpp"

#include "gt/gtl/validable_symbol.hpp"

#include "gt/gtl/object.hpp"
#include "gt/gtl/condition.hpp"
#include "gt/gtl/condition_factory.hpp"
#include "gt/gtl/context.hpp"
#include "gt/gtl/coordinate.hpp"
#include "gt/gtl/definition.hpp"
#include "gt/gtl/details.hpp"
#include "gt/gtl/game.hpp"
#include "gt/gtl/param.hpp"
#include "gt/gtl/param_factory.hpp"
#include "gt/gtl/player.hpp"
#include "gt/gtl/query.hpp"

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
