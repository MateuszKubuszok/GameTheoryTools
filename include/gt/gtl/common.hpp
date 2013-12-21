#ifndef __GT_GTL_COMMON_HPP__
#define __GT_GTL_COMMON_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/common.hpp
 * @brief     Declares classes for GT::GTL module.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Includes standard libraries */
#include <iostream>
#include <fstream>

/* Includes GT Model headers  */
#include "gt/model/common.hpp"
/* Includes Routines headers  */
#include "gt/routines/common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @namespace GT::GTL
 * @brief     Contains classes related to parsing text input as a GTL language.
 *
 * It consists of Parser, Scanner, Drivers responsible for specific tasks and Object classes that help turn
 * Parser's input into Model instances and Routines Results.
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::container::vector;
using boost::container::map;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

class DriverFactory;

class location;
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Shortens commonly used names */

typedef shared_ptr<Object>                ObjectPtr;          /**< @brief Smart pointer to Object. */
typedef shared_ptr<ObjectProperty>        ObjectPropertyPtr;  /**< @brief Smart pointer to ObjectProperty. */
typedef shared_ptr<Condition>             ConditionPtr;       /**< @brief Smart pointer to Condition. */
typedef shared_ptr<Context>               ContextPtr;         /**< @brief Smart pointer to Context. */
typedef shared_ptr<Coordinate>            CoordinatePtr;      /**< @brief Smart pointer to Coordinate. */
typedef shared_ptr<Definition>            DefinitionPtr;      /**< @brief Smart pointer to Definition. */
typedef shared_ptr<Details>               DetailsPtr;         /**< @brief Smart pointer to Details. */
typedef shared_ptr<Game>                  GamePtr;            /**< @brief Smart pointer to Game. */
typedef shared_ptr<Query>                 QueryPtr;           /**< @brief Smart pointer to Query. */
typedef shared_ptr<Param>                 ParamPtr;           /**< @brief Smart pointer to Param. */
typedef shared_ptr<Player>                PlayerPtr;          /**< @brief Smart pointer to Player. */

typedef vector<ConditionPtr>              Conditions;         /**< @brief Vector of Conditions. */
typedef shared_ptr<Conditions>            ConditionsPtr;      /**< @brief Smart pointer to Conditions. */
typedef vector<CoordinatePtr>             Coordinates;        /**< @brief Vector of Coordinates. */
typedef shared_ptr<Coordinates>           CoordinatesPtr;     /**< @brief Smart pointer to Coordinates. */
typedef vector<ObjectPtr>                 Objects;            /**< @brief Vector of Objects. */
typedef shared_ptr<Objects>               ObjectsPtr;         /**< @brief Smart pointer to Objects. */
typedef map<Identifier,ObjectPropertyPtr> ObjectPropertyMap;  /**< @brief Maps Identifer to ObjectProperty. */
typedef vector<ParamPtr>                  Params;             /**< @brief Vector of Params. */
typedef shared_ptr<Params>                ParamsPtr;          /**< @brief Smart pointer to Params. */

typedef shared_ptr<Parser>                ParserPtr;          /**< @brief Smart pointer to Parser. */
typedef shared_ptr<Scanner>               ScannerPtr;         /**< @brief Smart pointer to Scanner. */
typedef shared_ptr<Driver>                DriverPtr;          /**< @brief Smart pointer to Driver. */
typedef shared_ptr<ConditionDriver>       ConditionDriverPtr; /**< @brief Smart pointer to ConditionDriver. */
typedef shared_ptr<CoordinateDriver>      CoordinateDriverPtr;/**< @brief Smart pointer to CoordinateDriver.*/
typedef shared_ptr<GameDriver>            GameDriverPtr;      /**< @brief Smart pointer to GameDriver. */
typedef shared_ptr<ValueDriver>           ValueDriverPtr;     /**< @brief Smart pointer to ValueDriver. */
typedef shared_ptr<StatementDriver>       StatementDriverPtr; /**< @brief Smart pointer to StatementDriver. */

/** @brief Smart pointer to CollectionsDriver. */
template<typename Content> using CollectionsDriverPtr = shared_ptr<CollectionsDriver<Content>>;

typedef location                           InputLocation;     /**< @brief Alias for Bison-generated class. */
typedef shared_ptr<InputLocation>          InputLocationPtr;  /**< @brief Smart pointer to InputLocation. */

typedef Model::Root                        Root;              /**< @brief Alias for Model::Root. */
typedef Model::Result                      Result;            /**< @brief Alias for Model::Result. */
typedef Model::NullResult                  NullResult;        /**< @brief Alias for Model::NullResult. */
typedef Model::ResultPtr                   ResultPtr;         /**< @brief Alias for Model::ResultPtr */

/* Declares functions for equality check */

/**
 * @brief Check if Conditions are equal.
 *
 * @param conditions1 first Conditions vector
 * @param conditions2 second Conditions vector
 * @return            true if vectors have equal content
 */
bool operator==(const Conditions&  conditions1,  const Conditions&  conditions2);
/**
 * @brief Check if Conditions are different.
 *
 * @param conditions1 first Conditions vector
 * @param conditions2 second Conditions vector
 * @return            true if vectors have different content
 */
bool operator!=(const Conditions&  conditions1,  const Conditions&  conditions2);
/**
 * @brief Check if Coordinates are equal.
 *
 * @param coordinates1 first Coordinates vector
 * @param coordinates2 second Coordinates vector
 * @return             true if vectors have equal content
 */
bool operator==(const Coordinates& coordinates1, const Coordinates& coordinates2);
/**
 * @brief Check if Coordinates are different.
 *
 * @param coordinates1 first Coordinates vector
 * @param coordinates2 second Coordinates vector
 * @return             true if vectors have different content
 */
bool operator!=(const Coordinates& coordinates1, const Coordinates& coordinates2);
/**
 * @brief Check if Objects are equal.
 *
 * @param objects1 first Objects vector
 * @param objects2 second Objects vector
 * @return         true if vectors have equal content
 */
bool operator==(const Objects&     objects1,     const Objects&     objects2);
/**
 * @brief Check if Objects are different.
 *
 * @param objects1 first Objects vector
 * @param objects2 second Objects vector
 * @return         true if vectors have different content
 */
bool operator!=(const Objects&     objects1,     const Objects&     objects2);
/**
 * @brief Check if Params are equal.
 *
 * @param params1 first Params vector
 * @param params2 second Params vector
 * @return        true if vectors have equal content
 */
bool operator==(const Params&      params1,      const Params&      params2);
/**
 * @brief Check if Params are different.
 *
 * @param params1 first Params vector
 * @param params2 second Params vector
 * @return        true if vectors have different content
 */
bool operator!=(const Params&      params1,      const Params&      params2);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Includes GTL elements headers */

#include "gt/gtl/location.hh"
#include "gt/gtl/helpers.hpp"

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

#include "gt/gtl/driver_factory.hpp"

#include "gt/gtl/collections_driver.hpp"
#include "gt/gtl/coordinate_driver.hpp"
#include "gt/gtl/condition_driver.hpp"
#include "gt/gtl/game_driver.hpp"
#include "gt/gtl/value_driver.hpp"
#include "gt/gtl/statement_driver.hpp"
#include "gt/gtl/driver.hpp"
#include "gt/gtl/parser.hpp"
#include "gt/gtl/scanner.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_GTL_COMMON_HPP__ */
