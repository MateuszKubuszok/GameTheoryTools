#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Player {
// public:

Player::Player(
    const IdentifierPtr  playerName,
    const IdentifiersPtr playerStrategies
) :
    Object(),
    Model::Player(playerName, playerStrategies)
    {}

GT::Message Player::toString() {
    return Model::Player::toString();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
