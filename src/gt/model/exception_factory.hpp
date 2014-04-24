#ifndef GT_MODEL_EXCEPTION_FACTORY_HPP_INCLUDED
#define GT_MODEL_EXCEPTION_FACTORY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/exception_factory.hpp
 * @brief     Defines GT::Model::ExceptionFactory class.
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

/**
 * @class ExceptionFactory
 * @brief Used for creation of exceptions with predefined message format.
 *
 * @author Mateusz Kubuszok
 */
class ExceptionFactory final {
public:
    /**
     * @brief Returns the instance of an ExceptionFactory.
     *
     * @return ConditionFactory instance
     */
    static ExceptionFactory& getInstance();

    /**
     * @brief Thrown when values for given Positions are already set.
     *
     * @param positions invalid Positions
     * @return          InvalidCoordinate exception to throw
     */
    InvalidCoordinate coordinatesAlreadySet(
        const Positions& positions
    ) const;

    /**
     * @brief Thrown when some coordinates are uknown yet attept to store values is made.
     *
     * @return IllegalInnerState exception to throw
     */
    IllegalInnerState incompleteCoordinates() const;

    /**
     * @brief Thrown when some of the Players' names or strategies are invalid.
     *
     * @param position invalid Positions
     * @return         InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidCoordinateFormat(
        const Positions& position
    ) const;

    /**
     * @brief Thrown when there are colliding definitions of Player's playing in some turn.
     *
     * @param position invalid Positions
     * @return         InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidExtensiveCoordinateFormat(
        const Positions& position
    ) const;

    /**
     * @brief Thrown when ettepting to read from position that has not values defined.
     *
     * @param positionInStorage invalid position in storage
     * @param maxPosition       maximal position
     * @return                  InvalidCoordinate exception to throw
     */
    InvalidCoordinate noParamsForPositions(
        const Index positionInStorage,
        const Index maxPosition
    ) const;

    /**
     * @brief Thrown when no Player with given name has been defined.
     *
     * @param playerName invalid Player's name
     * @return           InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidPlayer(
        const Identifier& playerName
    ) const;

    /**
     * @brief @brief Thrown when no strategy with given name has been defined.
     *
     * @param strategyName invalid strategy's name
     * @return             InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidStrategy(
        const Identifier& strategyName
    ) const;

    /**
     * @brief @brief Thrown when no information set with given name has been defined.
     *
     * @param informationSetName invalid strategy's name
     * @return                   InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidInformationSet(
        const Identifier& informationSetName
    ) const;

    /**
     * @brief Thrown when attempt to redefine Players is made.
     *
     * @return IllegalInnerState exception to throw
     */
    IllegalInnerState playersAlreadySet() const;

    /**
     * @brief Thrown during attempt to build Result with properties' names and results not matching in size.
     *
     * @param propertiesSize properties' size
     * @param resultsSize    results' size
     * @return               IllegalInnerState exception to throw
     */
    IllegalInnerState propertiesAndResultsDontMatchInSize(
        const Index propertiesSize,
        const Index resultsSize
    ) const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    ExceptionFactory() = default;

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param exceptionFactory object to copy
     */
    ExceptionFactory(
        const ExceptionFactory& exceptionFactory
    ) = delete;

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ExceptionFactory() = default;
}; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_EXCEPTION_FACTORY_HPP_INCLUDED */
