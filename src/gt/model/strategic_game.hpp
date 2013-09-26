#ifndef __GT_MODEL_STRATEGIC_GAME_HPP__
#define __GT_MODEL_STRATEGIC_GAME_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class StrategicGame : public Game {
    PlayersPtr       players;
    StrategicDataPtr data;

public:
    StrategicGame(
        PlayersPtr       newPlayers,
        StrategicDataPtr newData
    );

    virtual PlayersPtr getPlayers();

    virtual DataAccessorPtr equilibriumData();

    virtual Message toString();
}; /* END class StrategicGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_GAME_HPP__ */
