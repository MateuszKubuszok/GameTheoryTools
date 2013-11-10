#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Game : public virtual Root {
// public:

bool Game::isEqual(
    const Root& root
) const {
    const Game* game = dynamic_cast<const Game*>(&root);
    if (!game)
        return false;
    if (game == this)
        return true;
    if (*game->getPlayers() != *getPlayers())
        return false;
    if (*game->getData() != *getData())
        return false;
    return true;
}

// }; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool operator==(
    const GamePtr& game1,
    const GamePtr& game2
) {
    return (*game1) == (*game2);
}

bool operator!=(
    const GamePtr& game1,
    const GamePtr& game2
) {
    return (*game1) != (*game2);
}

OutputStream& operator<<(
    OutputStream&  stream,
    const GamePtr& game
) {
    return stream << game->toString();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
