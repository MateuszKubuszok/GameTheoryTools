/**
 * @file      gt/routines/information_set_choice_routine_config.cpp
 * @brief     Defines GT::Routines::InformationSetChoiceRoutineConfig methods.
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

using boost::adaptors::map_values;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class InformationSetChoiceRoutineConfig : public virtual RoutineConfig {
// public:

InformationSetChoiceRoutineConfig::InformationSetChoiceRoutineConfig(
    const ExtensiveDataNodePtr extensiveGameRoot
) :
    positionsHelper(extensiveGameRoot),
    availableForPlayersAndSets()
{
    const IdentifiersPtr possiblePlayers = positionsHelper.getPossiblePlayers();
    for (const IdentifierPtr& playerPtr : *possiblePlayers) {
        const Identifier& player = *playerPtr;

        AvailableForSets     availableForSets;
        const IdentifiersPtr informationSets = positionsHelper.getPossibleInformationSetsForPlayer(player);
        for (const IdentifierPtr& informationSetPtr : *informationSets) {
            const Identifier& informationSet = *informationSetPtr;

            Identifiers choicesForSet(
                *positionsHelper.getInformationSetForPlayer(player, informationSet).getChoices()
            );

            availableForSets.insert( AvailableForSets::value_type(informationSet, choicesForSet) );
        }

        availableForPlayersAndSets.insert( AvailableForPlayersAndSets::value_type(player, availableForSets) );
    }
}

InformationSetChoiceRoutineConfig& InformationSetChoiceRoutineConfig::requireChoiceExactly(
    const Identifier& player,
    const Identifier& informationSet,
    const Identifier& chosenStrategy
) {
    Identifiers& availableStrategies =
        const_cast<Identifiers&>(getAvailableStrategies(player, informationSet));

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

InformationSetChoiceRoutineConfig& InformationSetChoiceRoutineConfig::requireChoiceWithin(
    const Identifier&  player,
    const Identifier&  informationSet,
    const Identifiers& allowedStrategies
) {
    Identifiers& availableStrategies =
        const_cast<Identifiers&>(getAvailableStrategies(player, informationSet));

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

const Identifiers& InformationSetChoiceRoutineConfig::getAvailableStrategies(
    const Identifier& player,
    const Identifier& informationSet
) const {
    if (!availableForPlayersAndSets.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);

    const AvailableForSets& informationSets = availableForPlayersAndSets.at(player);
    if (!informationSets.count(informationSet))
        throw ExceptionFactory::getInstance().informationSetNotFound(player, informationSet);

    return informationSets.at(informationSet);
}

bool InformationSetChoiceRoutineConfig::isValid() const {
    for (const AvailableForSets availableForSets : availableForPlayersAndSets | map_values)
        for (const Identifiers strategies : availableForSets | map_values)
            if (strategies.empty())
                return false;
    return true;
}

// }; /* END class InformationSetChoiceRoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
