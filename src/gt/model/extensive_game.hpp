#ifndef __GT_MODEL_EXTENSIVE_GAME_HPP__
#define __GT_MODEL_EXTENSIVE_GAME_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defnies ExtensiveGame.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree. Each node of that tree has assigned
 * Player. As such each SubCoordinates is mapped to strategy of the same Player.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExtensiveData
 */
class ExtensiveGame : public Game {
    /**
     * @brief Players.
     */
    PlayersPtr       players;
    /**
     * @brief Game's data.
     */
    ExtensiveDataPtr data;

public:
    /**
     * @brief Initiates Game with Players and Data.
     *
     * @param newPlayers Players' definitions
     * @param newData    Data for Game
     */
    ExtensiveGame(
        PlayersPtr       newPlayers,
        ExtensiveDataPtr newData
    );

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' denifitions
     */
    virtual PlayersPtr getPlayers() override;

    /**
     * @brief Returns Game's Data.
     *
     * @return Game's Data
     */
    virtual DataAccessorPtr getData() override;

    /**
     * @brief Returns ExtensiveGame's Message.
     *
     * @return Message
     */
    virtual Message toString() override;
}; /* END class ExtensiveGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_GAME_HPP__ */
