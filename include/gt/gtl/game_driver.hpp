#ifndef __GT_GTL_GAME_DRIVER_HPP__
#define __GT_GTL_GAME_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for handling Games via Driver.
 *
 * @author Mateusz Kubuszok
 */
class GameDriver : public virtual Root {
public:
    /**
     * @brief Create Strategic Game.
     *
     * @param inputLocation input location of created Game
     * @param details       Details for game
     * @return              Game
     */
    virtual GamePtr* createStrategic(
        InputLocation& inputLocation,
        DetailsPtr*    details
    ) = 0;

    /**
     * @brief Create Extensive Game.
     *
     * @param inputLocation input location of created Game
     * @param details       Details for game
     * @return              Game
     */
    virtual GamePtr* createExtensive(
        InputLocation& inputLocation,
        DetailsPtr*    details
    ) = 0;

    /**
     * @brief Create Details.
     *
     * @param inputLocation input location of created Details
     * @param player        declared Players
     * @param data          declared Coordinates
     * @return              Details
     */
    virtual DetailsPtr* createDetails(
        InputLocation&  inputLocation,
        ObjectsPtr*     players,
        CoordinatesPtr* data
    ) = 0;

    /**
     * @brief Create Player.
     *
     * @param inputLocation input location of created Player
     * @param player        Player's name
     * @param strategies    strategies
     * @return              Player
     */
    virtual PlayerPtr* createPlayer(
        InputLocation&  inputLocation,
        IdentifierPtr*  player,
        IdentifiersPtr* strategies
    ) = 0;

    /**
     * @brief GameDriver's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class GameDriver */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null GameDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullGameDriver : public GameDriver {
public:
    NullGameDriver() :
        GameDriver()
        {}

    virtual GamePtr* createStrategic(
        InputLocation& inputLocation,
        DetailsPtr*
    ) {
        return new GamePtr(
            setupLocation<Game>(
                NullFactory::getInstance().createGame(),
                inputLocation
            )
        );
    }

    virtual GamePtr* createExtensive(
        InputLocation& inputLocation,
        DetailsPtr*
    ) {
        return new GamePtr(
            setupLocation<Game>(
                NullFactory::getInstance().createGame(),
                inputLocation
            )
        );
    }

    virtual DetailsPtr* createDetails(
        InputLocation& inputLocation,
        ObjectsPtr*,
        CoordinatesPtr*
    ) {
        return new DetailsPtr(
            setupLocation<Details>(
                NullFactory::getInstance().createDetails(),
                inputLocation
            )
        );
    }

    virtual PlayerPtr* createPlayer(
        InputLocation& inputLocation,
        IdentifierPtr*,
        IdentifiersPtr*
    ) {
        return new PlayerPtr(
            setupLocation<Player>(
                NullFactory::getInstance().createPlayer(),
                inputLocation
            )
        );
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullGameDriver");
    }
}; /* END class NullGameDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_DRIVER_HPP__ */
