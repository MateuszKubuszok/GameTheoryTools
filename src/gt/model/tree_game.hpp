#ifndef __GT_MODEL_TREE_GAME_HPP__
#define __GT_MODEL_TREE_GAME_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defnies TreeGame.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree.
 * Each level of that tree has assigned Player and for this level. As such
 * coordinates are mapping from turn into choosen strategy instead of
 * Player to strategy mapping.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see TreeData
 */
class TreeGame : public Game {
    PlayersPtr  players;
    TreeDataPtr data;

public:
    /**
     * @brief Initiates Game with Players and Data. 
     *
     * @param newPlayers Players' definitions
     * @param newData    Data for Game
     */
    TreeGame(
        PlayersPtr  newPlayers,
        TreeDataPtr newData
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
     * @brief Returns TreeGame's Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class TreeGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_TREE_GAME_HPP__ */
