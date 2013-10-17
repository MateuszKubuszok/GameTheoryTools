#ifndef __GT_GTL_CHECKING_GAME_DRIVER_HPP__
#define __GT_GTL_CHECKING_GAME_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Games via CheckingDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see GameDriver
 */
class CheckingGameDriver : public GameDriver {
    Driver* driver;

public:
    /**
     * @brief Initiates CheckingGameDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    CheckingGameDriver(
        Driver* parentDriver
    );

    /**
     * @brief Create Strategic Game.
     *
     * @param details Details for game
     * @return        Game
     */
    virtual GamePtr* createStrategic(
        DetailsPtr* details
    );

    /**
     * @brief Create Tree Game.
     *
     * @param details Details for game
     * @return        Game
     */
    virtual GamePtr* createTree(
        DetailsPtr* details
    );

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
    );

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
    );

    /**
     * @brief CheckingGameDriver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class CheckingGameDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_GAME_DRIVER_HPP__ */
