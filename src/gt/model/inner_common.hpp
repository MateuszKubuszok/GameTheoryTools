#ifndef __GT_MODEL_INNER_COMMON_HPP__
#define __GT_MODEL_INNER_COMMON_HPP__

////////////////////////////////////////////////////////////////////////////////

/* Include standard libraries */
#include <sstream>
#include <iomanip>

/* Includes boost libraries */
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/thread/mutex.hpp>

/* Includes public interface */
#include "gt/model/common.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace GT{
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/* Implementations declarations */

class ExceptionFactory;

class ConstResult;
class EmptyResult;

class AbstractResultBuilder;
class PlainResultBuilder;
class JSONResultBuilder;
class XMLResultBuilder;


class PlainDataPiece;

class StrategicPositionsHelper;
class StrategicData;            class NullStrategicData;
class StrategicDataBuilder;
class StrategicDataAccessor;
class StrategicGame;
class StrategicGameBuilder;

class TreeDataNode;
class TreeData;

/* Shortens comonly used names */

typedef boost::shared_ptr<StrategicData>                   StrategicDataPtr;
typedef boost::shared_ptr<StrategicDataBuilder>            StrategicDataBuilderPtr;

typedef boost::bimaps::bimap<Identifier, Index>            IdentifierMap;
typedef boost::container::map<Identifier, IdentifierMap>   StrategyMap;

typedef boost::shared_ptr<TreeDataNode>                    TreeDataNodePtr;
typedef boost::container::map<Identifier, TreeDataNodePtr> TreeDataNodes;
typedef boost::shared_ptr<TreeDataNodes>                   TreeDataNodesPtr;

typedef boost::container::map<Identifier, PlayerPtr>       PlayersInTurns;
typedef boost::shared_ptr<PlayersInTurns>                  PlayersInTurnsPtr;

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

////////////////////////////////////////////////////////////////////////////////

/* Implementations headers */

#include "gt/model/exception_factory.hpp"

#include "gt/model/const_result.hpp"
#include "gt/model/empty_result.hpp"

#include "gt/model/abstract_result_builder.hpp"
#include "gt/model/plain_result_builder.hpp"
#include "gt/model/json_result_builder.hpp"
#include "gt/model/xml_result_builder.hpp"

#include "gt/model/positions_helper.hpp"

#include "gt/model/plain_data_piece.hpp"

#include "gt/model/strategic_data.hpp"
#include "gt/model/strategic_data_builder.hpp"
#include "gt/model/strategic_data_accessor.hpp"
#include "gt/model/strategic_game.hpp"
#include "gt/model/strategic_game_builder.hpp"

#include "gt/model/tree_data_node.hpp"
#include "gt/model/tree_data.hpp"

////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_MODEL_INNER_COMMON_HPP__ */
