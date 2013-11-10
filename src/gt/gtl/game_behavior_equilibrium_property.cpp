#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class GameBehaviorEquilibriumProperty : public ObjectProperty {
// public:

GameBehaviorEquilibriumProperty::GameBehaviorEquilibriumProperty(
    const Game* describedGame
) :
    game(describedGame)
    {}

ResultPtr GameBehaviorEquilibriumProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) const {
    return game->behaviorEquilibrium(context, conditions);
}

// }; /* END class GameBehaviorEquilibriumProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
