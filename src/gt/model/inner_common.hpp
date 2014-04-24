#ifndef GT_MODEL_INNER_COMMON_HPP_INCLUDED
#define GT_MODEL_INNER_COMMON_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/inner_common.hpp
 * @brief     Declares inner classes for GT::Model module.
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
#include <sstream>
#include <iomanip>

/* Includes boost libraries */
#include <boost/algorithm/string.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/range/adaptor/reversed.hpp>

/* Includes public interface */
#include "gt/model/common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::bimaps::bimap;
using boost::container::map;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Implementations declarations */

class ExceptionFactory;
class InnerNullFactory;

class ConstResult;
class EmptyResult;

class AbstractResultBuilder;
class PlainResultBuilder;
class JSONResultBuilder;
class XMLResultBuilder;

class PlainDataPiece;

class StrategicGamePositionsHelper;

class StrategicData;            class NullStrategicData;
class StrategicDataBuilder;
class StrategicDataAccessor;
class StrategicGame;
class StrategicGameBuilder;

class ExtensiveGamePositionsHelper;

class ExtensiveDataNode;        class NullExtensiveDataNode;
class ExtensiveData;            class NullExtensiveData;
class ExtensiveDataBuilder;
class ExtensiveDataAccessor;
class ExtensiveGame;
class ExtensiveGameBuilder;

/* Shortens comonly used names */

typedef shared_ptr<StrategicDataAccessor>     StrategicDataAccessorPtr;
typedef shared_ptr<StrategicData>             StrategicDataPtr;
typedef shared_ptr<StrategicDataBuilder>      StrategicDataBuilderPtr;

typedef bimap<Identifier, Index>              IdentifierMap;
typedef map<Identifier, IdentifierMap>        StrategyMap;

typedef shared_ptr<ExtensiveDataNode>         ExtensiveDataNodePtr;
typedef map<Identifier, ExtensiveDataNodePtr> ExtensiveDataNodes;
typedef shared_ptr<ExtensiveDataNodes>        ExtensiveDataNodesPtr;
typedef shared_ptr<ExtensiveDataAccessor>     ExtensiveDataAccessorPtr;
typedef shared_ptr<ExtensiveData>             ExtensiveDataPtr;
typedef shared_ptr<ExtensiveDataBuilder>      ExtensiveDataBuilderPtr;

typedef map<Identifier, PlayerPtr>            PlayersInTurns;
typedef shared_ptr<PlayersInTurns>            PlayersInTurnsPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Implementations headers */

#include "gt/model/exception_factory.hpp"

#include "gt/model/inner_null_factory.hpp"

#include "gt/model/const_result.hpp"
#include "gt/model/empty_result.hpp"

#include "gt/model/abstract_result_builder.hpp"
#include "gt/model/plain_result_builder.hpp"
#include "gt/model/json_result_builder.hpp"
#include "gt/model/xml_result_builder.hpp"

#include "gt/model/strategic_game_positions_helper.hpp"

#include "gt/model/plain_data_piece.hpp"

#include "gt/model/strategic_data.hpp"
#include "gt/model/strategic_data_builder.hpp"
#include "gt/model/strategic_data_accessor.hpp"
#include "gt/model/strategic_game.hpp"
#include "gt/model/strategic_game_builder.hpp"

#include "gt/model/extensive_game_positions_helper.hpp"

#include "gt/model/extensive_data_node.hpp"
#include "gt/model/extensive_data.hpp"
#include "gt/model/extensive_data_builder.hpp"
#include "gt/model/extensive_data_accessor.hpp"
#include "gt/model/extensive_game.hpp"
#include "gt/model/extensive_game_builder.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* #define GT_MODEL_INNER_COMMON_HPP_INCLUDED */
