#ifndef __GT_GTL_EXECUTION_GAME_DRIVER_HPP__
#define __GT_GTL_EXECUTION_GAME_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Games via ExecutionDriver.
 *
 * <p>Performs actual execution of instructions for Games.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see GameDriver
 */
class ExecutionGameDriver : public GameDriver {
    /**
     * @brief Driver for error handling.
     */
    CheckingGameDriver checkingGameDriver;
    /**
     * @brief Implementation of a main Driver.
     */
    Driver*            driver;
    /**
     * @brief Contains Context.
     */
    Context*           context;

public:
    /**
     * @brief Initiates ExecutionGameDriver with its parent.
     *
     * @param parentDriver parent Driver
     * @param context      Context data
     */
    ExecutionGameDriver(
        Driver*  parentDriver,
        Context* context
    );

    /**
     * @brief Create Strategic Game.
     *
     * @param inputLocation input location of created Game
     * @param details       Details for game
     * @return              Game
     */
    virtual GamePtr* createStrategic(
        const InputLocation& inputLocation,
        const DetailsPtr*    details
    ) const override;

    /**
     * @brief Create Extensive Game.
     *
     * @param inputLocation input location of created Game
     * @param details       Details for game
     * @return              Game
     */
    virtual GamePtr* createExtensive(
        const InputLocation& inputLocation,
        const DetailsPtr*    details
    ) const override;

    /**
     * @brief Create Details.
     *
     * @param inputLocation input location of created Details
     * @param player        declared Players
     * @param data          declared Coordinates
     * @return              Details
     */
    virtual DetailsPtr* createDetails(
        const InputLocation&  inputLocation,
        const ObjectsPtr*     players,
        const CoordinatesPtr* data
    ) const override;

    /**
     * @brief Create Player.
     *
     * @param inputLocation input location of created Player
     * @param player        Player's name
     * @param strategies    strategies
     * @return              Player
     */
    virtual PlayerPtr* createPlayer(
        const InputLocation&  inputLocation,
        const IdentifierPtr*  player,
        const IdentifiersPtr* strategies
    ) const override;

    /**
     * @brief ExecutionGameDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;

private:
    /**
     * @brief Game building routine common for Strategic and Extensive form Games.
     *
     * @param inputLocation input location of created Game
     * @param details       Details built game details
     * @param gameBuilder   GameBuilder specific for given game
     * @return              Game instance (valid or not)
     */
    GamePtr* createGameWithBuilder(
        const InputLocation&      inputLocation,
        const Details&            details,
        const Model::GameBuilder& gameBuilder
    ) const;
}; /* END class ExecutionGameDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_GAME_DRIVER_HPP__ */
