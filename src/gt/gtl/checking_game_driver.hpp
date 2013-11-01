#ifndef __GT_GTL_CHECKING_GAME_DRIVER_HPP__
#define __GT_GTL_CHECKING_GAME_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Games via CheckingDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see GameDriver
 */
class CheckingGameDriver : public GameDriver {
    /**
     * @brief Implementation of a main Driver.
     */
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
     * @param inputLocation input location of created Game
     * @param details       Details for game
     * @return              Game
     */
    virtual GamePtr* createStrategic(
        InputLocation& inputLocation,
        DetailsPtr*    details
    );

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
    );

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
    );

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
    );

    /**
     * @brief CheckingGameDriver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class CheckingGameDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_GAME_DRIVER_HPP__ */
