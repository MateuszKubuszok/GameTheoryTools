#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class GameBehavioralEquilibriumProperty {
// public:

GameBehavioralEquilibriumProperty::GameBehavioralEquilibriumProperty(
    Game* describedGame
) :
    game(describedGame)
    {}

ResultPtr GameBehavioralEquilibriumProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) {
    return game->behavioralEquilibrium(context, conditions);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
