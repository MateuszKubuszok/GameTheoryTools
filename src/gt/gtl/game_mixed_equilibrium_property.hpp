#ifndef __GT_GTL_GAME_MIXED_EQUILIBRIUM_PROPERTY_HPP__
#define __GT_GTL_GAME_MIXED_EQUILIBRIUM_PROPERTY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Describes mixed-strategy equilibria of Games.
 *
 * @author Mateusz Kubuszok
 *
 * @see Game
 */
class GameMixedEquilibriumProperty : public ObjectProperty {
    /**
     * @brief Described Game.
     */
    Game* game;

public:
    /**
     * @brief Initiates Property with Game it's describing.
     *
     * @param describedGame described Game
     */
    explicit GameMixedEquilibriumProperty(
        Game* describedGame
    );

    /**
     * @brief Finds equilibrium for given Conditions.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class GameMixedEquilibriumProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_GAME_MIXED_EQUILIBRIUM_PROPERTY_HPP__ */
