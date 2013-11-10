#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionGameDriver : public GameDriver {
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

    const Details&              details        = **detailsPtr;
    const Model::GameBuilderPtr gameBuilderPtr = Model::GameFactory::getInstance().buildStrategicGame();
    const Model::GameBuilder&   gameBuilder    = *gameBuilderPtr;

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

    const Details&              details        = **detailsPtr;
    const Model::GameBuilderPtr gameBuilderPtr = Model::GameFactory::getInstance().buildExtensiveGame();
    const Model::GameBuilder&   gameBuilder    = *gameBuilderPtr;

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
    const Model::GameBuilder& gameBuilder
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
