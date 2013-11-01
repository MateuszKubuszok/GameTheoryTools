#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class GameBehavioralEquilibriumProperty : public ObjectProperty {
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

// }; /* END class GameBehavioralEquilibriumProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
