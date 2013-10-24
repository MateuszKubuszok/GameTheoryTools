#ifndef __GT_MODEL_EXTENSIVE_GAME_HPP__
#define __GT_MODEL_EXTENSIVE_GAME_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defnies ExtensiveGame.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree.
 * Each level of that tree has assigned Player and for this level. As such
 * coordinates are mapping from turn into choosen strategy instead of
 * Player to strategy mapping.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExtensiveData
 */
class ExtensiveGame : public Game {
    PlayersPtr       players;
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
    virtual PlayersPtr getPlayers();

    /**
     * @brief Returns Game's Data.
     *
     * @return Game's Data
     */
    virtual DataAccessorPtr getData();

    /**
     * @brief Returns ExtensiveGame's Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class ExtensiveGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_GAME_HPP__ */
