#ifndef __GT_GTL_GAME_MIXED_EQUILIBRIUM_PROPERTY_HPP__
#define __GT_GTL_GAME_MIXED_EQUILIBRIUM_PROPERTY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class GameMixedEquilibriumProperty : public ObjectProperty {
    Game* game;

public:
    explicit GameMixedEquilibriumProperty(
        Game* describedGame
    );

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class GameMixedEquilibriumProperty */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_GAME_MIXED_EQUILIBRIUM_PROPERTY_HPP__ */
