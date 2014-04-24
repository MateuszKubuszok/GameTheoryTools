#ifndef GT_GTL_PLAYER_NAME_PROPERTY_HPP_INCLUDED
#define GT_GTL_PLAYER_NAME_PROPERTY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/player_name_property.hpp
 * @brief     Defines GT::GTL::PlayerNameProperty class.
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
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class PlayerNameProperty
 * @brief Describes Player's name.
 *
 * @author Mateusz Kubuszok
 *
 * @see Player
 */
class PlayerNameProperty final : public ObjectProperty {
    /**
     * @brief Described Player.
     */
    const Player* player;

public:
    /**
     * @brief Initiates ObjectProperty with Player it's describing.
     *
     * @param describedPlayer described Player
     */
    explicit PlayerNameProperty(
        const Player* describedPlayer
    );

    /**
     * @brief Returns ObjectProperty's description.
     *
     * @return description
     */
    virtual ResultPtr getDescription() const override;

    /**
     * @brief Finds Player's strategies.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const override;
}; /* END class PlayerNameProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef GT_GTL_PLAYER_NAME_PROPERTY_HPP_INCLUDED */
