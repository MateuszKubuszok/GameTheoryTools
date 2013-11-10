#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class GameMixedEquilibriumProperty : public ObjectProperty {
// public:

GameMixedEquilibriumProperty::GameMixedEquilibriumProperty(
    const Game* describedGame
) :
    game(describedGame)
    {}

ResultPtr GameMixedEquilibriumProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) const {
    return game->mixedEquilibrium(context, conditions);
}

// }; /* END class GameMixedEquilibriumProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
