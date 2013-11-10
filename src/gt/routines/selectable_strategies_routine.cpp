#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class SelectableStrategiesRoutine : virtual public Routine {
// public:

SelectableStrategiesRoutine::SelectableStrategiesRoutine(
    const PlayersPtr definedPlayers
) :
    players(definedPlayers),
    availableStrategies()
{
    for (const Model::Players::value_type& playerPair : *players) {
        const Identifier   playerName = playerPair.first;
        const Identifiers& strategies = *playerPair.second->getStrategies();

        IdentifiersPtr availableStrategiesForPlayer(new Identifiers(strategies));

        availableStrategies.insert( AvailableStrategies::value_type(
            playerName,
            availableStrategiesForPlayer
        ) );
    }
}


const Model::PlayersPtr SelectableStrategiesRoutine::getAvailablePlayers() const {
    return players;
}


IdentifiersPtr SelectableStrategiesRoutine::getAvailableStrategiesForPlayer(
    const Identifier& player
) const {
    if (!availableStrategies.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);

    return availableStrategies.at(player);
}


void SelectableStrategiesRoutine::setAvailableStrategiesForPlayer(
    const Identifier& player,
    IdentifiersPtr    strategies
) {
    if (!availableStrategies.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);

    availableStrategies[player] = strategies;
}

// }; /* END class SelectableStrategiesRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
