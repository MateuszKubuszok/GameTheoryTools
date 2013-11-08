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
    delete errorCheck;

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
    delete errorCheck;

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
    delete errorCheck;

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
    delete errorCheck;

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
