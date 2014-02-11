/**
 * @file      gt/gtl/lazy_game_proxy.cpp
 * @brief     Defines GT::GTL::LazyGameProxy methods.
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

using boost::dynamic_pointer_cast;

using Model::DataBuilderPtr;
using Model::GameBuilderPtr;
using Model::Players;
using Model::PlayersPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class LazyGameProxy final : Model::Game {
// public:

LazyGameProxy::LazyGameProxy(
    const GameBuilderPtr definedGameBuilder,
    const ObjectsPtr     definedPlayers,
    const CoordinatesPtr definedCoordinates,
    const Context*       definedContext
) :
    gameBuilder(definedGameBuilder),
    players(definedPlayers),
    coordinates(definedCoordinates),
    context(definedContext)
    {}

const CoordinatesPtr LazyGameProxy::getCoordinates() const {
    return coordinates;
}

const ObjectsPtr LazyGameProxy::getPlayersParams() const {
    return players;
}

const PlayersPtr LazyGameProxy::getPlayers() const {
    return accessGame()->getPlayers();
}

const Model::DataAccessorPtr LazyGameProxy::getData() const {
    return accessGame()->getData();
}

Message LazyGameProxy::toString() const {
    return accessGame()->toString();
}

// private:

const Model::GamePtr LazyGameProxy::accessGame() const {
    GameBuilderPtr currentGameBuilder = gameBuilder->cloneBuilder();

    PlayersPtr modelPlayers(new Players());
    for (const ObjectPtr& objectPtr : *players) {
        const Player& player = objectPtr->toPlayer();
        const Param&  param  = objectPtr->toParam();

        if (player) {
            const PlayerPtr playerPtr = dynamic_pointer_cast<Player>(objectPtr);

            if (playerPtr) {
                modelPlayers->insert(
                    Players::value_type(
                        *player.getName(),
                        dynamic_pointer_cast<Model::Player>(playerPtr)
                    )
                );
                continue;
            }
        }

        if (param) {
            const ObjectPtr referredObject = param.getObject(*context);
            const Player&   referredPlayer = referredObject->toPlayer();

            if (referredPlayer) {
                PlayerPtr playerPtr = dynamic_pointer_cast<Player>(objectPtr);
                modelPlayers->insert(
                    Players::value_type(
                        *referredPlayer.getName(),
                        dynamic_pointer_cast<Model::Player>(referredObject)
                    )
                );
                continue;
            }
        }

        static const Identifier typeName = createIdentifier("Player");
        throw ExceptionFactory::getInstance().invalidObjectType(typeName);
    }
    currentGameBuilder->dataBuilder()->setPlayers(modelPlayers);

    for (const CoordinatePtr& coordinate : *coordinates) {
        DataBuilderPtr builderForCoordinate = currentGameBuilder->clone();
        coordinate->fillDataBuilder(*context, builderForCoordinate);
    }

    return currentGameBuilder->build();
}

// }; /* END class LazyGameProxy */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
