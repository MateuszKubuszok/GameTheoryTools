#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class SelectableStrategiesRoutine : virtual public Routine {
// public:

SelectableStrategiesRoutine::SelectableStrategiesRoutine(
    PlayersPtr definedPlayers
) :
    players(definedPlayers),
    availableStrategies()
{
    for (Model::Players::value_type& playerPair : *players) {
        Identifier   playerName = playerPair.first;
        Identifiers& strategies = *playerPair.second->getStrategies();

        IdentifiersPtr availableStrategiesForPlayer(new Identifiers(strategies));

        availableStrategies.insert( AvailableStrategies::value_type(
            playerName,
            availableStrategiesForPlayer
        ) );
    }
}


Model::PlayersPtr SelectableStrategiesRoutine::getAvailablePlayers() {
    return players;
}


IdentifiersPtr SelectableStrategiesRoutine::getAvailableStrategiesForPlayer(
    Identifier& player
) {
    if (!availableStrategies.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);

    return availableStrategies[player];
}


void SelectableStrategiesRoutine::setAvailableStrategiesForPlayer(
    Identifier&    player,
    IdentifiersPtr strategies
) {
    if (!availableStrategies.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);

    availableStrategies[player] = strategies;
}

// }; /* END class SelectableStrategiesRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
