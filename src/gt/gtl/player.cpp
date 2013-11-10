#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Player : public Object, public Model::Player {
// public:

Player::Player(
    const IdentifierPtr  playerName,
    const IdentifiersPtr playerStrategies
) :
    Object(createIdentifier("Player")),
    Model::Player(playerName, playerStrategies)
{
    registerProperty(createIdentifier("name"),       ObjectPropertyPtr(new PlayerNameProperty(this)));
    registerProperty(createIdentifier("strategies"), ObjectPropertyPtr(new PlayerStrategiesProperty(this)));
}

Message Player::toString() const {
    return Model::Player::toString();
}

Player::operator const Player&() const {
    return *this;
}

// }; /* END class Player */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
