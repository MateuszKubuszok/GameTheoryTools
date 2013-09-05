#ifndef __GT_GTL_PLAYER_HPP__
#define __GT_GTL_PLAYER_HPP__

namespace GT {
namespace GTL {

/**
 * @brief Defines Player.
 *
 * @author Mateusz Kubuszok
 */
class Player : public virtual Object, public virtual Model::Player {
public:
    /**
     * @brief Constructor of the Player.
     *
     * @param playerName     name of the player
     * @param playerStrategy declared strategies
     */
    Player(
        const Identifier&  playerName,
        const Identifiers& playerStrategies
    );

    /**
     * @brief Returns Message about Player.
     *
     * @return Player's Message
     */
    virtual Message toString();
}; /* END class Player */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_HPP__ */
