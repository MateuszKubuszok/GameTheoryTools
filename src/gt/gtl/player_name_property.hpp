#ifndef __GT_GTL_PLAYER_NAME_PROPERTY_HPP__
#define __GT_GTL_PLAYER_NAME_PROPERTY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Describes Player's name.
 *
 * @author Mateusz Kubuszok
 *
 * @see Player
 */
class PlayerNameProperty : public ObjectProperty {
    /**
     * @brief Described Player.
     */
    Player* player;

public:
    /**
     * @brief Initiates Property with Player it's describing.
     *
     * @param describedPlayer described Player
     */
    PlayerNameProperty(
        Player* describedPlayer
    );

    /**
     * @brief Finds Player's strategies.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class PlayerNameProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PLAYER_NAME_PROPERTY_HPP__ */
