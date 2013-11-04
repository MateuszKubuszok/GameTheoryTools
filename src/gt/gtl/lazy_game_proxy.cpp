#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class LazyGameProxy : Model::Game {
// public:

LazyGameProxy::LazyGameProxy(
    Model::GameBuilderPtr definedGameBuilder,
    ObjectsPtr            definedPlayers,
    CoordinatesPtr        definedCoordinates,
    ContextPtr            definedContext
) :
    gameBuilder(definedGameBuilder),
    players(definedPlayers),
    coordinates(definedCoordinates),
    context(definedContext)
    {}

Model::PlayersPtr LazyGameProxy::getPlayers() {
    return accessGame()->getPlayers();
}

Model::DataAccessorPtr LazyGameProxy::getData() {
    return accessGame()->getData();
}

Message LazyGameProxy::toString() {
    return accessGame()->toString();
}

// private:

Model::GamePtr LazyGameProxy::accessGame() {
    Model::GameBuilderPtr currentGameBuilder = gameBuilder->cloneBuilder();

    Model::PlayersPtr modelPlayers(new Model::Players());
    for (ObjectPtr& objectPtr : *players) {
        Player& player = *objectPtr;
        Param&  param  = *objectPtr;

        if (player) {
            PlayerPtr playerPtr = boost::dynamic_pointer_cast<Player>(objectPtr);

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
            ObjectPtr referredObject = param.getObject(*context);
            Player&   referredPlayer = *referredObject;

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

        Identifier typeName = createIdentifier("Player");
        throw ExceptionFactory::getInstance().invalidObjectType(typeName);
    }
    currentGameBuilder->dataBuilder()->setPlayers(modelPlayers);

    for (CoordinatePtr& coordinate : *coordinates) {
        Model::DataBuilderPtr builderForCoordinate = currentGameBuilder->clone();
        coordinate->fillDataBuilder(*context, builderForCoordinate);
    }

    return currentGameBuilder->build();
}

// }; /* END class LazyGameProxy */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
