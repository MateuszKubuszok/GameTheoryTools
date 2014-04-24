#ifndef GT_GTL_ERROR_FACTORY_HPP_INCLUDED
#define GT_GTL_ERROR_FACTORY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/error_factory.hpp
 * @brief     Defines GT::GTL::ErrorFactory class.
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
 * @class ErrorFactory
 * @brief Used for creation of Error instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class ErrorFactory final {
public:
    /**
     * @brief Returns the instance of a ErrorFactory.
     *
     * @return ErrorFactory instance
     */
    static ErrorFactory& getInstance();

    /**
     * @brief Creates ErrorCondition.
     *
     * @param errorMessage message describing error
     * @result             ErrorCondition
     */
    ConditionPtr createCondition(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorCoordinate.
     *
     * @param errorMessage message describing error
     * @result             ErrorCoordinate
     */
    CoordinatePtr createCoordinate(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorDefinition.
     *
     * @param errorMessage message describing error
     * @result             ErrorDefinition
     */
    DefinitionPtr createDefinition(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorDetails.
     *
     * @param errorMessage message describing error
     * @result             ErrorDetails
     */
    DetailsPtr createDetails(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorGame.
     *
     * @param errorMessage message describing error
     * @result             ErrorGame
     */
    GamePtr createGame(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorObject.
     *
     * @param errorMessage message describing error
     * @result             ErrorObject
     */
    ObjectPtr createObject(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorParam.
     *
     * @param errorMessage message describing error
     * @result             ErrorParam
     */
    ParamPtr createParam(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorPlayer.
     *
     * @param errorMessage message describing error
     * @result             ErrorPlayer
     */
    PlayerPtr createPlayer(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorQuery.
     *
     * @param errorMessage message describing error
     * @result             ErrorQuery
     */
    QueryPtr createQuery(
        const Message errorMessage
    ) const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    ErrorFactory() = default;

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param errorFactory object to copy
     */
    ErrorFactory(
        const ErrorFactory& errorFactory
    ) = delete;

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ErrorFactory() = default;
}; /* END class ErrorFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_ERROR_FACTORY_HPP_INCLUDED */
