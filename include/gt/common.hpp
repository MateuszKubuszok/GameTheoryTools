#ifndef __GT_COMMON_HPP__
#define __GT_COMMON_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/common.hpp
 * @brief     Declares classes for GT module.
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

/* Include standard libraries */
#include <string>
#include <utility>

/* Includes boost libraries */
#include <boost/container/map.hpp>
#include <boost/container/set.hpp>
#include <boost/container/vector.hpp>
#include <boost/shared_ptr.hpp>

/* GNU MultiPrecision library */
#include <gmpxx.h>

namespace GT {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @namespace GT
 * @brief     Contains classes and modules related to Nash equilibria calculation.
 *
 * GT namespace itself creates some aliases used in nested namespaces responsible for specific tasks. This
 * helps the project to have consistent names and coventions.
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::istream;
using std::ostream;
using std::string;

using boost::container::map;
using boost::container::map;
using boost::container::set;
using boost::container::vector;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Rename of some primary types */

typedef unsigned int Index; /**< @brief Position in array or storage */

/* Shortens commonly used names */

typedef istream                     InputStream;    /**< @brief Input stream alias. */
typedef ostream                     OutputStream;   /**< @brief Output stream alias. */
typedef string                      Message;        /**< @brief Alias for string used as messages. */
typedef shared_ptr<Message>         MessagePtr;     /**< @brief Smart pointer to Message */
typedef vector<MessagePtr>          Messages;       /**< @brief Vector of Messages. */
typedef shared_ptr<Messages>        MessagesPtr;    /**< @brief Smart pointer to Messages. */
typedef string                      Identifier;     /**< @brief Alias for string used as identifiers. */
typedef shared_ptr<Identifier>      IdentifierPtr;  /**< @brief Smart pointer to Identifier. */
typedef vector<IdentifierPtr>       Identifiers;    /**< @brief Vector of Identifiers. */
typedef shared_ptr<Identifiers>     IdentifiersPtr; /**< @brief Smart pointer to Identifiers. */
typedef mpf_class                   Number;         /**< @brief Alias for multiple precision float class. */
typedef shared_ptr<Number>          NumberPtr;      /**< @brief Smart pointer to Number. */
typedef vector<NumberPtr>           Numbers;        /**< @brief Vector of Numbers. */
typedef shared_ptr<Numbers>         NumbersPtr;     /**< @brief Smart pointer to Numbers. */
typedef map<Identifier, Identifier> Positions;      /**< @brief Map of dimension-position pairs. */
typedef shared_ptr<Positions>       PositionsPtr;   /**< @brief Smart pointer to Positions. */

/* Declares functions for equality check */

/**
 * @brief Check if Messages are equal.
 *
 * @param messages1 first Messages vector
 * @param messages2 second Messages vector
 * @return          true if vectors have equal content
 */
bool operator==(Messages&    messages1,   Messages&    messages2);
/**
 * @brief Check if Messages are different.
 *
 * @param messages1 first Messages vector
 * @param messages2 second Messages vector
 * @return          true if vectors have different content
 */
bool operator!=(Messages&    messages1,   Messages&    messages2);
/**
 * @brief Check if Identifiers are equal.
 *
 * @param identifier1 first Identifiers vector
 * @param identifier2 second Identifiers vector
 * @return            true if vectors have equal content
 */
bool operator==(Identifiers& identifier1, Identifiers& identifier2);
/**
 * @brief Check if Identifiers are different.
 *
 * @param identifier1 first Identifiers vector
 * @param identifier2 second Identifiers vector
 * @return            true if vectors have different content
 */
bool operator!=(Identifiers& identifier1, Identifiers& identifier2);
/**
 * @brief Check if Numbers are equal.
 *
 * @param numbers1 first Numbers vector
 * @param numbers2 second Numbers vector
 * @return         true if vectors have equal content
 */
bool operator==(Numbers&     numbers1,    Numbers&     numbers2);
/**
 * @brief Check if Numbers are different.
 *
 * @param numbers1 first Numbers vector
 * @param numbers2 second Numbers vector
 * @return         true if vectors have different content
 */
bool operator!=(Numbers&     numbers1,    Numbers&     numbers2);
/**
 * @brief Check if Positions are equal.
 *
 * @param positions1 first Positions vector
 * @param positions2 second Positions vector
 * @return           true if vectors have equal content
 */
bool operator==(Positions&   positions1,  Positions&   positions2);
/**
 * @brief Check if Positions are different.
 *
 * @param positions1 first Positions vector
 * @param positions2 second Positions vector
 * @return           true if vectors have different content
 */
bool operator!=(Positions&   positions1,  Positions&   positions2);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */

/* Includes GT headers */

#include "gt/helpers.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_COMMON_HPP__ */
