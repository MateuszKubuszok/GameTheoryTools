/**
 * @file      gt/routines/player_choice_routine_config.cpp
 * @brief     Defines GT::Routines::PlayerChoiceRoutineConfig methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::find_if;
using std::remove_if;

using boost::adaptors::map_keys;
using boost::adaptors::map_values;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerChoiceRoutineConfig : public virtual RoutineConfig {
// public:

PlayerChoiceRoutineConfig::PlayerChoiceRoutineConfig(
    const PlayersPtr players
) :
    availableForPlayers()
{
    for (const Identifier player : *players | map_keys)
        availableForPlayers.insert(
            AvailableForPlayers::value_type( player, Identifiers(*players->at(player)->getStrategies()) )
        );
}

PlayerChoiceRoutineConfig& PlayerChoiceRoutineConfig::requireChoiceExactly(
    const Identifier& player,
    const Identifier& chosenStrategy
) {
    Identifiers& availableStrategies = const_cast<Identifiers&>(getAvailableStrategies(player));

    // removes all strategies not equal to the chosen
    availableStrategies.erase(
        remove_if(
            availableStrategies.begin(),
            availableStrategies.end(),
            [chosenStrategy](const IdentifierPtr& checkedStrategy) {
                return (*checkedStrategy) != chosenStrategy;
            }
        )
    );

    return *this;
}

PlayerChoiceRoutineConfig& PlayerChoiceRoutineConfig::requireChoiceWithin(
    const Identifier&  player,
    const Identifiers& allowedStrategies
) {
    Identifiers& availableStrategies = const_cast<Identifiers&>(getAvailableStrategies(player));

    // removes all not allowed
    availableStrategies.erase(
        remove_if(
            availableStrategies.begin(),
            availableStrategies.end(),
            [allowedStrategies](const IdentifierPtr& checkedStrategy) {
                // check if such strategy is NOT present among allowedStrategies and thus can be removed
                bool result = allowedStrategies.empty() || allowedStrategies.end() == find_if(
                    allowedStrategies.begin(),
                    allowedStrategies.end(),
                    [checkedStrategy](const IdentifierPtr& allowedStrategy) {
                        return *checkedStrategy == *allowedStrategy;
                    }
                );
                return result;
            }
        ),
        availableStrategies.end()
    );

    return *this;
}

const Identifiers& PlayerChoiceRoutineConfig::getAvailableStrategies(
    const Identifier& player
) const {
    if (!availableForPlayers.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);

    return availableForPlayers.at(player);
}

bool PlayerChoiceRoutineConfig::isValid() const {
    for (const Identifiers strategies : availableForPlayers | map_values)
            if (strategies.empty())
                return false;
    return true;
}

// }; /* END class PlayerChoiceRoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
