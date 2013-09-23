#ifndef __GT_MODEL_INNER_COMMON_HPP__
#define __GT_MODEL_INNER_COMMON_HPP__

////////////////////////////////////////////////////////////////////////////////

/* Include standard libraries */
#include <sstream>

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

class ConstResult;
class EmptyResult;

class AbstractResultBuilder;
class PlainResultBuilder;
class JSONResultBuilder;
class XMLResultBuilder;

class PositionsHelper;

class PlainDataPiece;
class PlainData;
class PlainDataBuilder;
class PlainGameBuilder;

class PlainDataAccessor;

class PureGame;
class PureGameBuilder;
class MixedGame;
class MixedGameBuilder;

/* Shortens comonly used names */

typedef boost::shared_ptr<PlainDataBuilder>              PlainDataBuilderPtr;
typedef boost::bimaps::bimap<Identifier, Index>          IdentifierMap;
typedef boost::container::map<Identifier, IdentifierMap> StrategyMap;

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

////////////////////////////////////////////////////////////////////////////////

/* Implementations headers */

#include "gt/model/const_result.hpp"
#include "gt/model/empty_result.hpp"

#include "gt/model/abstract_result_builder.hpp"
#include "gt/model/plain_result_builder.hpp"
#include "gt/model/json_result_builder.hpp"
#include "gt/model/xml_result_builder.hpp"

#include "gt/model/positions_helper.hpp"

#include "gt/model/plain_data_piece.hpp"
#include "gt/model/plain_data.hpp"
#include "gt/model/plain_data_builder.hpp"
#include "gt/model/plain_game_builder.hpp"

#include "gt/model/plain_data_accessor.hpp"
#include "gt/model/mixed_data_accessor.hpp"

#include "gt/model/pure_game.hpp"
#include "gt/model/pure_game_builder.hpp"
#include "gt/model/mixed_game.hpp"
#include "gt/model/mixed_game_builder.hpp"

////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_MODEL_INNER_COMMON_HPP__ */
