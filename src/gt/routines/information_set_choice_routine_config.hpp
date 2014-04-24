#ifndef GT_ROUTINES_INFORMATION_SET_CHOICE_ROUTINE_CONFIG_HPP_INCLUDED
#define GT_ROUTINES_INFORMATION_SET_CHOICE_ROUTINE_CONFIG_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/information_set_choice_routine_config.hpp
 * @brief     Defines GT::Routines::InformationSetChoiceRoutineConfig class.
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

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::container::map;

using Model::ExtensiveDataNodePtr;
using Model::ExtensiveGamePositionsHelper;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class InformationSetChoiceRoutineConfig
 * @brief Contains information about available choices for each information set.
 *
 * @author Mateusz Kubuszok
 *
 * @see InformationSetChoiceCondition
 * @see InformationSetRangeCondition
 */
class InformationSetChoiceRoutineConfig : public virtual RoutineConfig {
    /**
     * @brief Contains information about strategies available for each set.
     */
    typedef map<Identifier, Identifiers>      AvailableForSets;

    /**
     * @brief Contains information about strategies/information sets available for each Player.
     */
    typedef map<Identifier, AvailableForSets> AvailableForPlayersAndSets;

    /**
     * @brief Available strategies for information sets of each Player.
     */
    AvailableForPlayersAndSets                availableForPlayersAndSets;

public:
    /**
     * @brief Initiates config with ExtensiveData's tree root.
     *
     * @param extensiveGameRoot root of Data tree
     */
    explicit InformationSetChoiceRoutineConfig(
        const ExtensiveDataNodePtr extensiveGameRoot
    );

    /**
     * @brief Trims availabe choices for information set for just one.
     *
     * @param  player             Player's name
     * @param  informationSet     information set's name
     * @param  chosenStrategy     chosen strategy
     * @return                    reference to itself for chainging
     * @throw InvalidPlayerChoice thrown if Player's or information set's name is invalid
     */
    InformationSetChoiceRoutineConfig& requireChoiceExactly(
        const Identifier& player,
        const Identifier& informationSet,
        const Identifier& chosenStrategy
    );

    /**
     * @brief Trims availabe choices for information set to passed ones.
     *
     * @param  player             Player's name
     * @param  informationSet     information set's name
     * @param  allowedStrategies  allowed strategies
     * @return                    reference to itself for chainging
     * @throw InvalidPlayerChoice thrown if Player's or information set's name is invalid
     */
    InformationSetChoiceRoutineConfig& requireChoiceWithin(
        const Identifier&  player,
        const Identifier&  informationSet,
        const Identifiers& allowedStrategies
    );

    /**
     * @brief Returns available choices for given Player and information set.
     *
     * @param player              Player's name
     * @param informationSet      information set's name
     * @return                    available strategies
     * @throw InvalidPlayerChoice thrown if Player's or information set's name is invalid
     */
    const Identifiers& getAvailableStrategies(
        const Identifier& player,
        const Identifier& informationSet
    ) const;

    /**
     * @brief Whether current configuration is valid.
     *
     * @return true if current configuration is valid
     */
    virtual bool isValid() const override = 0;
}; /* END class InformationSetChoiceRoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef GT_ROUTINES_INFORMATION_SET_CHOICE_ROUTINE_CONFIG_HPP_INCLUDED */
