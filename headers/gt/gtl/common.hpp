#ifndef __GT_GTL_COMMON_HPP__
#define __GT_GTL_COMMON_HPP__ 1

/* Includes GT model headers  */
#include "gt/model/common.hpp"

/* Class declarations */
class Object;
class Condition;
class ConditionFactory;
class Data;
class DataPiece;
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
#include "gt/gtl/coordinate.hpp" // TODO
#include "gt/gtl/data.hpp" // TODO
#include "gt/gtl/data_piece.hpp" // TODO
#include "gt/gtl/definition.hpp" // TODO
#include "gt/gtl/details.hpp" // TODO
#include "gt/gtl/game.hpp" // TODO
#include "gt/gtl/query.hpp" // TODO
#include "gt/gtl/param.hpp"
#include "gt/gtl/player.hpp" // TODO

/* Includes GTL parsers elements */
#include "gt/gtl/driver.hpp"
#include "gt/gtl/scanner.hpp"
#include "gt/gtl/parser.hpp"

/* Shortens commonly used names */
typedef boost::containers::map<Identifier, GT::GTL::DataPiece> DataPieceMap;
typedef boost::containers::vector<GT::GTL::Condition>          Conditions;
typedef boost::containers::vector<DataPieceMap>                DataPieces;
typedef boost::containers::vector<GT::GTL::Objects>            Objects;
typedef boost::containers::vector<GT::GTL::Param>              Params;
typedef GT::Model::Result                                      Result;

#endif /* END #ifndef __GT_GTL_COMMON_HPP__ */
