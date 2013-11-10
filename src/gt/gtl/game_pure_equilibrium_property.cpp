#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class GamePureEquilibriumProperty : public ObjectProperty {
// public:

GamePureEquilibriumProperty::GamePureEquilibriumProperty(
    const Game* describedGame
) :
    game(describedGame)
    {}

ResultPtr GamePureEquilibriumProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) const {
    return game->pureEquilibrium(context, conditions);
}

// }; /* END class GamePureEquilibriumProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
