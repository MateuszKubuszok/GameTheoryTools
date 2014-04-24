#ifndef GT_MODEL_COMMON_HPP_INCLUDED
#define GT_MODEL_COMMON_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/common.hpp
 * @brief     Declares classes for GT::Model module.
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
#include <stdexcept>

/* Includes GT headers  */
#include "gt/common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @namespace GT::Model
 * @brief     Contains classes related to storing GT data.
 *
 * It consists of Players, Games, Datas, DataAccessors and builders that help with creating models.
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::container::map;
using boost::container::vector;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Exception declarations */

class IllegalInnerState;
class InvalidCoordinate;

/* Factory declarations */

class NullFactory;
class GameFactory;
class ResultFactory;

/* Model declarations */

class Player;        class NullPlayer;
class DataPiece;     class NullDataPiece;
class DataAccessor;  class NullDataAccessor;
class Data;          class NullData;
class DataBuilder;   class NullDataBuilder;
class Game;          class NullGame;
class GameBuilder;   class NullGameBuilder;
class Result;        class NullResult;
class ResultBuilder; class NullResultBuilder;

/* Shortens comonly used names */

typedef shared_ptr<Player>         PlayerPtr;        /**< @brief Smart pointer to Player. */
typedef map<Identifier, PlayerPtr> Players;          /**< @brief Map of Identifier-PlayerPtr pairs. */
typedef shared_ptr<Players>        PlayersPtr;       /**< @brief Smart pointer to Players. */
typedef shared_ptr<Data>           DataPtr;          /**< @brief Smart pointer to Data. */
typedef shared_ptr<DataAccessor>   DataAccessorPtr;  /**< @brief Smart pointer to DataAccessor. */
typedef shared_ptr<DataPiece>      DataPiecePtr;     /**< @brief Smart pointer to DataPiece. */
typedef shared_ptr<DataBuilder>    DataBuilderPtr;   /**< @brief Smart pointer to DataBuilder. */
typedef shared_ptr<Game>           GamePtr;          /**< @brief Smart pointer to Game. */
typedef shared_ptr<GameBuilder>    GameBuilderPtr;   /**< @brief Smart pointer to GameBuilder. */
typedef shared_ptr<Result>         ResultPtr;        /**< @brief Smart pointer to Result. */
typedef shared_ptr<ResultBuilder>  ResultBuilderPtr; /**< @brief Smart pointer to ResultBuilder. */

/* Declares functions for equality check */

/**
 * @brief Check if Players are equal.
 *
 * @param players1 first Players vector
 * @param players2 second Players vector
 * @return         true if vectors have equal content
 */
bool operator==(Players& players1, Players& players2);
/**
 * @brief Check if Players are different.
 *
 * @param players1 first Players vector
 * @param players2 second Players vector
 * @return         true if vectors have different content
 */
bool operator!=(Players& players1, Players& players2);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

/* Includes GT model headers */

#include "gt/model/helpers.hpp"

#include "gt/model/exceptions.hpp"

#include "gt/model/null_factory.hpp"

#include "gt/model/root.hpp"
#include "gt/model/player.hpp"
#include "gt/model/data_piece.hpp"
#include "gt/model/data_accessor.hpp"
#include "gt/model/data.hpp"
#include "gt/model/data_builder.hpp"
#include "gt/model/game.hpp"
#include "gt/model/game_builder.hpp"
#include "gt/model/game_factory.hpp"
#include "gt/model/result.hpp"
#include "gt/model/result_builder.hpp"
#include "gt/model/result_factory.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef GT_MODEL_COMMON_HPP_INCLUDED */
