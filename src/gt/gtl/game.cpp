#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Game {
// public:

Game::Game(
    Model::GamePtr gameImplementation
) :
    Object(createIdentifier("Game")),
    game(gameImplementation)
{
    registerProperty(Identifier("pure_equilibrium"),  ObjectPropertyPtr(new GamePureEquilibriumProperty(this)));
    registerProperty(Identifier("mixed_equilibrium"), ObjectPropertyPtr(new GameMixedEquilibriumProperty(this)));
}

ResultPtr Game::pureEquilibrium(
    const Context&    context,
    const Conditions& conditions
) {
    return ResultFactory::getInstance().constResult("Not yet implemented");
}

ResultPtr Game::mixedEquilibrium(
    const Context&    context,
    const Conditions& conditions
) {
    return ResultFactory::getInstance().constResult("Not yet implemented");
}

Message Game::toString() {
    return game->toString();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
