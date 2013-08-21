#ifndef __GT_GTL_COMMON_HPP__
#define __GT_GTL_COMMON_HPP__ 1

/* Include standard libraries */
#include <stdexcept>

/* Includes boost libraries */
#include <boost/container/slist.hpp>

/* Includes GTL elements headers */
#include "gt/gtl/result.hpp"
#include "gt/gtl/object.hpp"
#include "gt/gtl/condition.hpp"
#include "gt/gtl/data.hpp"
#include "gt/gtl/data_piece.hpp"
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

/* Shortens comonly used names */
typedef std::string                          Identifier;
typedef boost::containers::slist<Identifier> Identifiers;
typedef boost::containers::slist<Condition>  Conditions;
typedef boost::containers::slist<Objects>    Objects;
typedef boost::containers::slist<Param>      Params;

#endif /* END #ifndef __GT_GTL_COMMON_HPP__ */
