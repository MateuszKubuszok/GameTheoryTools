#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Game {
// public:

ResultPtr Game::pureEquilibrium(
    const Context&    context,
    const Conditions& conditions
) {
    return Model::NullFactory::getInstance().createResult();
}

ResultPtr Game::mixedEquilibrium(
    const Context&    context,
    const Conditions& conditions
) {
    return Model::NullFactory::getInstance().createResult();
}

Message Game::toString() {
    return Message("NullGame");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
