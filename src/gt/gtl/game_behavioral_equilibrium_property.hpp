#ifndef __GT_GTL_GAME_BEHAVIORAL_EQUILIBRIUM_PROPERTY_HPP__
#define __GT_GTL_GAME_BEHAVIORAL_EQUILIBRIUM_PROPERTY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class GameBehavioralEquilibriumProperty : public ObjectProperty {
    Game* game;

public:
    explicit GameBehavioralEquilibriumProperty(
        Game* describedGame
    );

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class GameBehavioralEquilibriumProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_GAME_BEHAVIORAL_EQUILIBRIUM_PROPERTY_HPP__ */
