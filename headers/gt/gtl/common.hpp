#ifndef __GT_GTL_COMMON_HPP__
#define __GT_GTL_COMMON_HPP__ 1

/* Includes GT model headers  */
#include "gt/model/common.hpp"

/* Includes GTL elements headers */
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
typedef boost::containers::slist<GT::GTL::Condition> Conditions;
typedef boost::containers::slist<GT::GTL::Objects>   Objects;
typedef boost::containers::slist<GT::GTL::Param>     Params;

#endif /* END #ifndef __GT_GTL_COMMON_HPP__ */
