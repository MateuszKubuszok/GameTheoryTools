#ifndef __GT_MODEL_TREE_GAME_HPP__
#define __GT_MODEL_TREE_GAME_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class TreeGame : public Game {
    PlayersPtr  players;
    TreeDataPtr data;

public:
    TreeGame(
        PlayersPtr  newPlayers,
        TreeDataPtr newData
    );

    virtual PlayersPtr getPlayers();

    virtual DataAccessorPtr getData();

    virtual Message toString();
}; /* END class TreeGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_TREE_GAME_HPP__ */
