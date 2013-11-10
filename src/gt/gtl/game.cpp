#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Game : public Object {
// public:

Game::Game(
    const Model::GamePtr gameImplementation
) :
    Object(createIdentifier("Game")),
    game(gameImplementation)
{
    registerProperty(
        Identifier("pure_equilibrium"),     ObjectPropertyPtr(new GamePureEquilibriumProperty(this))
    );
    registerProperty(
        Identifier("mixed_equilibrium"),    ObjectPropertyPtr(new GameMixedEquilibriumProperty(this))
    );
    registerProperty(
        Identifier("behavior_equilibrium"), ObjectPropertyPtr(new GameBehaviorEquilibriumProperty(this))
    );
}

ResultPtr Game::pureEquilibrium(
    const Context&,
    const Conditions&
) const {
    return ResultFactory::getInstance().constResult("Not yet implemented");
}

ResultPtr Game::mixedEquilibrium(
    const Context&,
    const Conditions&
) const {
    return ResultFactory::getInstance().constResult("Not yet implemented");
}

ResultPtr Game::behaviorEquilibrium(
    const Context&,
    const Conditions&
) const {
    return ResultFactory::getInstance().constResult("Not yet implemented");
}

Message Game::toString() const {
    return game->toString();
}

Game::operator const Game&() const {
    return *this;
}

// }; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
