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

////////////////////////////////////////////////////////////////////////////////

/* Shortens commonly used names */

typedef std::istream                            InputStream;
typedef std::ostream                            OutputStream;
typedef std::string                             Message;
typedef boost::shared_ptr<Message>              MessagePtr;
typedef boost::container::vector<MessagePtr>    Messages;
typedef boost::shared_ptr<Messages>             MessagesPtr;
typedef std::string                             Identifier;
typedef boost::shared_ptr<Identifier>           IdentifierPtr;
typedef boost::container::vector<IdentifierPtr> Identifiers;
typedef boost::shared_ptr<Identifiers>          IdentifiersPtr;
typedef mpz_class                               Number;
typedef boost::shared_ptr<Number>               NumberPtr;

namespace Model {

////////////////////////////////////////////////////////////////////////////////

/* Class declarations */

class NullFactory;

class Player;        class NullPlayer;
class Result;        class NullResult;
class ResultFactory;

/* Shortens comonly used names */

typedef boost::shared_ptr<Player> PlayerPtr;
typedef boost::shared_ptr<Result> ResultPtr;

////////////////////////////////////////////////////////////////////////////////

} /* END namepsace GTL */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */

/* Includes GT model headers */

#include "gt/model/null_factory.hpp"

#include "gt/model/root.hpp"
#include "gt/model/player.hpp"
#include "gt/model/result.hpp"
#include "gt/model/result_builder.hpp"
#include "gt/model/result_factory.hpp"

////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_MODEL_COMMON_HPP__ */
