#ifndef __GT_MODEL_PURE_GAME_HPP__
#define __GT_MODEL_PURE_GAME_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PureGame : public Game {
    PlayersPtr players;
    DataPtr    data;

public:
    PureGame(
        PlayersPtr newPlayers,
        DataPtr    newData
    );

    virtual PlayersPtr getPlayers();

    virtual Message toString();
}; /* END class PureGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PURE_GAME_HPP__ */
