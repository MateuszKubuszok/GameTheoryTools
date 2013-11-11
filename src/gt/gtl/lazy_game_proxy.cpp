#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class LazyGameProxy : Model::Game {
// public:

LazyGameProxy::LazyGameProxy(
    const Model::GameBuilderPtr definedGameBuilder,
    const ObjectsPtr            definedPlayers,
    const CoordinatesPtr        definedCoordinates,
    const Context*              definedContext
) :
    gameBuilder(definedGameBuilder),
    players(definedPlayers),
    coordinates(definedCoordinates),
    context(definedContext)
    {}

const Model::PlayersPtr LazyGameProxy::getPlayers() const {
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
    Model::GameBuilderPtr currentGameBuilder = gameBuilder->cloneBuilder();

    Model::PlayersPtr modelPlayers(new Model::Players());
    for (const ObjectPtr& objectPtr : *players) {
        const Player& player = *objectPtr;
        const Param&  param  = *objectPtr;

        if (player) {
            const PlayerPtr playerPtr = boost::dynamic_pointer_cast<Player>(objectPtr);

            if (playerPtr) {
                modelPlayers->insert(
                    Model::Players::value_type(
                        *player.getName(),
                        boost::dynamic_pointer_cast<Model::Player>(playerPtr)
                    )
                );
                continue;
            }
        }

        if (param) {
            const ObjectPtr referredObject = param.getObject(*context);
            const Player&   referredPlayer = *referredObject;

            if (referredPlayer) {
                PlayerPtr playerPtr = boost::dynamic_pointer_cast<Player>(objectPtr);
                modelPlayers->insert(
                    Model::Players::value_type(
                        *referredPlayer.getName(),
                        boost::dynamic_pointer_cast<Model::Player>(referredObject)
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
        Model::DataBuilderPtr builderForCoordinate = currentGameBuilder->clone();
        coordinate->fillDataBuilder(*context, builderForCoordinate);
    }

    return currentGameBuilder->build();
}

// }; /* END class LazyGameProxy */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
