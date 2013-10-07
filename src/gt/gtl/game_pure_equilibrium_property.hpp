#ifndef __GT_GTL_GAME_PURE_EQUILIBRIUM_PROPERTY_HPP__
#define __GT_GTL_GAME_PURE_EQUILIBRIUM_PROPERTY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class GamePureEquilibriumProperty : public ObjectProperty {
    Game* game;

public:
    explicit GamePureEquilibriumProperty(
        Game* describedGame
    );

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class GamePureEquilibriumProperty */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_GAME_PURE_EQUILIBRIUM_PROPERTY_HPP__ */
