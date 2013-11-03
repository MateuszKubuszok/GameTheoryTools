#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionGameDriver : public GameDriver {
// public:

ExecutionGameDriver::ExecutionGameDriver(
    Driver*     parentDriver,
    ContextPtr& contextPtr
) :
    checkingGameDriver(parentDriver),
    driver(parentDriver),
    context(contextPtr)
    {}

GamePtr* ExecutionGameDriver::createStrategic(
    InputLocation& inputLocation,
    DetailsPtr*    detailsPtr
) {
    GamePtr* errorCheck = checkingGameDriver.createStrategic(inputLocation, detailsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    Details&              details        = **detailsPtr;
    Model::GameBuilderPtr gameBuilderPtr = Model::GameFactory::getInstance().buildStrategicGame();
    Model::GameBuilder&   gameBuilder    = *gameBuilderPtr;

    return createGameWithBuilder(inputLocation, details, gameBuilder);
}

GamePtr* ExecutionGameDriver::createExtensive(
    InputLocation& inputLocation,
    DetailsPtr*    detailsPtr
) {
    GamePtr* errorCheck = checkingGameDriver.createStrategic(inputLocation, detailsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    Details&              details        = **detailsPtr;
    Model::GameBuilderPtr gameBuilderPtr = Model::GameFactory::getInstance().buildExtensiveGame();
    Model::GameBuilder&   gameBuilder    = *gameBuilderPtr;

    return createGameWithBuilder(inputLocation, details, gameBuilder);
}

DetailsPtr* ExecutionGameDriver::createDetails(
    InputLocation&  inputLocation,
    ObjectsPtr*     playersPtr,
    CoordinatesPtr* dataPtr
) {
    DetailsPtr* errorCheck = checkingGameDriver.createDetails(inputLocation, playersPtr, dataPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    ObjectsPtr&     objectPlayers = *playersPtr;
    CoordinatesPtr& coordinates   = *dataPtr;

    return new DetailsPtr(
        setupLocation<Details>(
            DetailsPtr(new Details(objectPlayers, coordinates)),
            inputLocation
        )
    );
}

PlayerPtr* ExecutionGameDriver::createPlayer(
    InputLocation&  inputLocation,
    IdentifierPtr*  playerPtr,
    IdentifiersPtr* strategiesPtr
) {
    PlayerPtr* errorCheck = checkingGameDriver.createPlayer(inputLocation, playerPtr, strategiesPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    IdentifierPtr&  player     = *playerPtr;
    IdentifiersPtr& strategies = *strategiesPtr;

    return new PlayerPtr(
        setupLocation<Player>(
            PlayerPtr(new Player(player, strategies)),
            inputLocation
        )
    );
}

Message ExecutionGameDriver::toString() {
    return Message("ExecutionGameDriver");
}

// private:

GamePtr* ExecutionGameDriver::createGameWithBuilder(
    InputLocation&      inputLocation,
    Details&            details,
    Model::GameBuilder& gameBuilder
) {
    try {
        Model::PlayersPtr players(new Model::Players());
        for (ObjectPtr& objectPtr : *details.getPlayers()) {
            Player& player = *objectPtr;
            Param&  param  = *objectPtr;

            if (player) {
                PlayerPtr playerPtr = boost::dynamic_pointer_cast<Player>(objectPtr);

                if (playerPtr) {
                    players->insert(
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
                    players->insert(
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
        gameBuilder.dataBuilder()->setPlayers(players);

        for (CoordinatePtr& coordinate : *details.getCoordinates()) {
            Model::DataBuilderPtr builderForCoordinate = gameBuilder.clone();
            coordinate->fillDataBuilder(*context, builderForCoordinate);
        }

        return new GamePtr(
            setupLocation<Game>(
                GamePtr(new Game(gameBuilder.build())),
                inputLocation
            )
        );
    } catch (const std::exception& e) {
        return new GamePtr(
            setupLocation<Game>(
                ErrorFactory::getInstance().createGame(e.what()),
                inputLocation
            )
        );
    }
}

// }; /* END class ExecutionGameDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
