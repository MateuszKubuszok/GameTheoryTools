#ifndef __GT_GTL_EXECUTION_GAME_DRIVER_HPP__
#define __GT_GTL_EXECUTION_GAME_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Games via ExecutionDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see GameDriver
 */
class ExecutionGameDriver : public GameDriver {
    CheckingGameDriver checkingGameDriver;
    Driver*            driver;

public:
    /**
     * @brief Initiates ExecutionGameDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    ExecutionGameDriver(
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
     * @brief ExecutionGameDriver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class ExecutionGameDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_GAME_DRIVER_HPP__ */
