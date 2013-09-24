#ifndef __GT_MODEL_MIXED_GAME_HPP__
#define __GT_MODEL_MIXED_GAME_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class MixedGame : public Game {
    PlayersPtr players;
    DataPtr    data;

public:
    MixedGame(
        PlayersPtr newPlayers,
        DataPtr    newData
    );

    virtual PlayersPtr getPlayers();

    virtual DataAccessorPtr equilibriumData();

    virtual Message toString();
}; /* END class MixedGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_MIXED_GAME_HPP__ */
