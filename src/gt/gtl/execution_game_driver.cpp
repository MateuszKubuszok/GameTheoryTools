/**
 * @file      gt/gtl/execution_game_driver.cpp
 * @brief     Defines GT::GTL::ExecutionGameDriver methods.
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

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using Model::GameBuilder;
using Model::GameBuilderPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionGameDriver final : public GameDriver {
// public:

ExecutionGameDriver::ExecutionGameDriver(
    Driver*  parentDriver,
    Context* contextPtr
) :
    checkingGameDriver(parentDriver),
    driver(parentDriver),
    context(contextPtr)
    {}

GamePtr* ExecutionGameDriver::createStrategic(
    const InputLocation& inputLocation,
    const DetailsPtr*    detailsPtr
) const {
    GamePtr* errorCheck = checkingGameDriver.createStrategic(inputLocation, detailsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const Details&       details        = **detailsPtr;
    const GameBuilderPtr gameBuilderPtr = Model::GameFactory::getInstance().buildStrategicGame();
    const GameBuilder&   gameBuilder    = *gameBuilderPtr;

    return createGameWithBuilder(inputLocation, details, gameBuilder);
}

GamePtr* ExecutionGameDriver::createExtensive(
    const InputLocation& inputLocation,
    const DetailsPtr*    detailsPtr
) const {
    GamePtr* errorCheck = checkingGameDriver.createStrategic(inputLocation, detailsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const Details&       details        = **detailsPtr;
    const GameBuilderPtr gameBuilderPtr = Model::GameFactory::getInstance().buildExtensiveGame();
    const GameBuilder&   gameBuilder    = *gameBuilderPtr;

    return createGameWithBuilder(inputLocation, details, gameBuilder);
}

DetailsPtr* ExecutionGameDriver::createDetails(
    const InputLocation&  inputLocation,
    const ObjectsPtr*     playersPtr,
    const CoordinatesPtr* dataPtr
) const {
    DetailsPtr* errorCheck = checkingGameDriver.createDetails(inputLocation, playersPtr, dataPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const ObjectsPtr&     objectPlayers = *playersPtr;
    const CoordinatesPtr& coordinates   = *dataPtr;

    return new DetailsPtr(
        setupLocation<Details>(
            DetailsPtr(new Details(objectPlayers, coordinates)),
            inputLocation
        )
    );
}

PlayerPtr* ExecutionGameDriver::createPlayer(
    const InputLocation&  inputLocation,
    const IdentifierPtr*  playerPtr,
    const IdentifiersPtr* strategiesPtr
) const {
    PlayerPtr* errorCheck = checkingGameDriver.createPlayer(inputLocation, playerPtr, strategiesPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const IdentifierPtr&  player     = *playerPtr;
    const IdentifiersPtr& strategies = *strategiesPtr;

    return new PlayerPtr(
        setupLocation<Player>(
            PlayerPtr(new Player(player, strategies)),
            inputLocation
        )
    );
}

Message ExecutionGameDriver::toString() const {
    return Message("ExecutionGameDriver");
}

// private:

GamePtr* ExecutionGameDriver::createGameWithBuilder(
    const InputLocation&      inputLocation,
    const Details&            details,
    const GameBuilder& gameBuilder
) const {
    Model::GamePtr lazyGame(
        new LazyGameProxy(
            gameBuilder.cloneBuilder(),
            details.getPlayers(),
            details.getCoordinates(),
            context
        )
    );

    return new GamePtr(
       setupLocation<Game>(
            GamePtr(new Game(lazyGame)),
            inputLocation
        )
    );
}

// }; /* END class ExecutionGameDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
