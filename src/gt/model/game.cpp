#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class Game {
// public:

bool Game::isEqual(
    Root& root
) {
    Game* game = dynamic_cast<Game*>(&root);
    if (!game)
        return false;
    if (game == this)
        return true;
    PlayersPtr foreignPlayers = game->getPlayers();
    PlayersPtr localPlayers   = getPlayers();
    if (foreignPlayers->size() != localPlayers->size())
        return false;
    BOOST_FOREACH(Identifier playerName, (*localPlayers) | boost::adaptors::map_keys) {
        if (!foreignPlayers->count(playerName))
            return false;
        if ((*foreignPlayers)[playerName] != (*localPlayers)[playerName])
            return false;
    }
    if (game->getData() != getData())
        return false;
    return true;
}

// }

////////////////////////////////////////////////////////////////////////////////

bool operator==(
    GamePtr game1,
    GamePtr game2
) {
    return (*game1) == (*game2);
}

bool operator!=(
    GamePtr game1,
    GamePtr game2
) {
    return (*game1) != (*game2);
}

OutputStream& operator<<(
    OutputStream& stream,
    GamePtr       game
) {
    return stream << game->toString();
}

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
