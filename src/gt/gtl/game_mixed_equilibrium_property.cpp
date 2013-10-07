#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class GameMixedEquilibriumProperty {
// public:

GameMixedEquilibriumProperty::GameMixedEquilibriumProperty(
    Game* describedGame
) :
    game(describedGame)
    {}

ResultPtr GameMixedEquilibriumProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) {
    return game->mixedEquilibrium(context, conditions);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
