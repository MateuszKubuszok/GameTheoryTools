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
     * @param details Details for game
     * @return        Game
     */
    virtual GamePtr* createStrategic(
        DetailsPtr* details
    ) = 0;

    /**
     * @brief Create Tree Game.
     *
     * @param details Details for game
     * @return        Game
     */
    virtual GamePtr* createTree(
        DetailsPtr* details
    ) = 0;

    /**
     * @brief Create Details.
     *
     * @param player declared Players
     * @param data   declared Coordinates
     * @return       Details
     */
    virtual DetailsPtr* createDetails(
        ObjectsPtr*     players,
        CoordinatesPtr* data
    ) = 0;

    /**
     * @brief Create Player.
     * 
     * @param player     Player's name
     * @param strategies strategies
     * @return Player
     */
    virtual PlayerPtr* createPlayer(
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
        DetailsPtr* details
    ) {
        return new GamePtr(NullFactory::getInstance().createGame());
    }

    virtual GamePtr* createTree(
        DetailsPtr* details
    ) {
        return new GamePtr(NullFactory::getInstance().createGame());
    }

    virtual DetailsPtr* createDetails(
        ObjectsPtr*     players,
        CoordinatesPtr* data
    ) {
        return new DetailsPtr(NullFactory::getInstance().createDetails());
    }

    virtual PlayerPtr* createPlayer(
        IdentifierPtr*  player,
        IdentifiersPtr* strategies
    ) {
        return new PlayerPtr(NullFactory::getInstance().createPlayer());
    }

    virtual Message toString() {
        return Message("NullGameDriver");
    }
}; /* END class NullGameDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_DRIVER_HPP__ */
