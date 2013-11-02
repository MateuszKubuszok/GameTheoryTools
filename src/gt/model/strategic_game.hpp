#ifndef __GT_MODEL_STRATEGIC_GAME_HPP__
#define __GT_MODEL_STRATEGIC_GAME_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defnies StrategicGame.
 *
 * <p>Games in this form should have all coordinates filled with payoffs. Since all Players and their
 * strategies are known beforehand, positions can also be hashed to Indexes with PositionsHelper.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see StrategicData
 */
class StrategicGame : public Game {
    /**
     * @brief Players.
     */
    PlayersPtr       players;
    /**
     * @brief Game's Data.
     */
    StrategicDataPtr data;

public:
    /**
     * @brief Initiates Game with Players and Data.
     *
     * @param newPlayers Players' definitions
     * @param newData    Data for Game
     */
    StrategicGame(
        PlayersPtr       newPlayers,
        StrategicDataPtr newData
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
     * @brief Returns StrategicGame's Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class StrategicGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_GAME_HPP__ */
