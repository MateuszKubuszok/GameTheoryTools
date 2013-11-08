#ifndef __GT_GTL_CHECKING_GAME_DRIVER_HPP__
#define __GT_GTL_CHECKING_GAME_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Games via CheckingDriver.
 *
 * <p>Performs only syntax/type checking on Games' tokens.</p>
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
    explicit CheckingGameDriver(
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
    ) override;

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
    ) override;

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
    ) override;

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
    ) override;

    /**
     * @brief CheckingGameDriver's Message.
     *
     * @return message
     */
    virtual Message toString() override;
}; /* END class CheckingGameDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_GAME_DRIVER_HPP__ */
