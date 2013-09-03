#ifndef __GT_MODEL_COMMON_HPP__
#define __GT_MODEL_COMMON_HPP__

/* Include standard libraries */
#include <stdexcept>
#include <string>
#include <utility>

/* Includes boost libraries */
#include <boost/shared_ptr.hpp>
#include <boost/container/map.hpp>
#include <boost/container/vector.hpp>

/* GNU MultiPrecision library */
#include <gmpxx.h>

namespace GT {

/* Shortens comonly used names */
typedef std::string                          Message;
typedef boost::shared_ptr<Message>           MessagePtr;
typedef std::string                          Identifier;
typedef boost::shared_ptr<Identifier>        IdentifierPtr;
typedef boost::container::vector<Identifier> Identifiers;
typedef boost::shared_ptr<Identifiers>       IdentifiersPtr;
typedef mpz_class                            Number;
typedef boost::shared_ptr<Number>            NumberPtr;

namespace Model {

/* Class declarations */
class Player;
class Result;
class ResultFactory;

/* Shortens comonly used names */
typedef boost::shared_ptr<Player> PlayerPtr;
typedef boost::shared_ptr<Result> ResultPtr;

} /* END namepsace GTL */

} /* END namespace GT */

/* Includes GT model headers */
#include "gt/model/player.hpp"
#include "gt/model/result.hpp"
#include "gt/model/result_factory.hpp"

#endif /* END #ifndef __GT_MODEL_COMMON_HPP__ */
