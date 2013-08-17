#ifndef __GTL_COMMON_HPP__
#define __GTL_COMMON_HPP__ 1

/* Includes boost libraries */
#include <boost/container/slist.hpp>

/* Includes GTL elements headers */
#include "gtl/condition.hpp"
#include "gtl/data.hpp"
#include "gtl/data_piece.hpp"
#include "gtl/definition.hpp"
#include "gtl/details.hpp"
#include "gtl/game.hpp"
#include "gtl/query.hpp"
#include "gtl/object.hpp"
#include "gtl/param.hpp"
#include "gtl/player.hpp"

/* Includes GTL parsers elements */
#include "gtl/driver.hpp"
#include "gtl/scanner.hpp"
#include "gtl/parser.hpp"

/* Shortens comonly used names */
typedef std::string                          Identifier;
typedef boost::containers::slist<Identifier> Identifiers;
typedef boost::containers::slist<Condition>  Conditions;
typedef boost::containers::slist<Objects>    Objects;
typedef boost::containers::slist<Param>      Params;

#ifndef /* END #ifndef __GTL_COMMON_HPP__ */