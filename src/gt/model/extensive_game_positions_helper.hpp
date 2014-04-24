#ifndef GT_MODEL_EXTENSIVE_GAME_POSITIONS_HELPER_HPP_INCLUDED
#define GT_MODEL_EXTENSIVE_GAME_POSITIONS_HELPER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/extensive_game_positions_helper.hpp
 * @brief     Defines GT::Model::ExtensiveGamePositionsHelper class.
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
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::bimaps::bimap;
using boost::container::map;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ExtensiveGamePositionsHelper
 * @brief Helper used for calculating information sets for ExtensiveGames.
 *
 * @author Mateusz Kubuszok
 */
class ExtensiveGamePositionsHelper final : public Root {
    /**
     * @brief Root of Data tree.
     */
    const ExtensiveDataNodePtr root;

    /**
     * @brief PlayersInformationSets.
     */
    map<Identifier, bimap<Identifier, ExtensiveDataNode*>> playersInformationSets;

public:
    /**
     * @brief Contains single element information set for one Player.
     */
    typedef bimap<Identifier, ExtensiveDataNode*>  PlayerInformationSets;

    /**
     * @brief Contains information sets' collections for each Player.
     */
    typedef map<Identifier, PlayerInformationSets> PlayersInformationSets;

    /**
     * @brief Inititiates helper with ExtensiveGame tree's root.
     *
     * @param extensiveGameRoot root of Game's tree
     */
    explicit ExtensiveGamePositionsHelper(
        const ExtensiveDataNodePtr extensiveGameRoot
    );

    /**
     * @brief Returns list of available Players.
     *
     * @return list of available Players
     */
    IdentifiersPtr getPossiblePlayers() const;

    /**
     * @brief Returns whether Player is available.
     *
     * @param player Player's name
     * @return       true if Player is available
     */
    bool isPlayerPossible(
        const Identifier& player
    ) const;

    /**
     * @brief Returns list of available information sets.
     *
     * @param player            Player's name
     * @return                  list of available information sets for a Player
     * @throw InvalidCoordinate thrown when no such Player available
     */
    IdentifiersPtr getPossibleInformationSetsForPlayer(
        const Identifier& player
    ) const;

    /**
     * @brief Returns available information sets.
     *
     * @param player            Player's name
     * @return                  information sets for a Player
     * @throw InvalidCoordinate thrown when no such Player available
     */
    const PlayerInformationSets& getInformationSetsForPlayer(
        const Identifier& player
    ) const;

    /**
     * @brief Returns list of available information sets.
     *
     * @param player            Player's name
     * @param setName           information set's name
     * @return                  list of available information sets for a Player
     * @throw InvalidCoordinate thrown when no such Player or information set available
     */
    const ExtensiveDataNode& getInformationSetForPlayer(
        const Identifier& player,
        const Identifier& setName
    ) const;

    /**
     * @brief Retuns ExtensiveGamePositionsHelper's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ExtensiveGamePositionsHelper */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_EXTENSIVE_GAME_POSITIONS_HELPER_HPP_INCLUDED */
