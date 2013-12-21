#ifndef __GT_GTL_NULL_FACTORY_HPP__
#define __GT_GTL_NULL_FACTORY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/null_factory.hpp
 * @brief     Defines GT::GTL::NullFactory class.
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
 * @class NullFactory
 * @brief Used for creation of Null instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class NullFactory final {
public:
    /**
     * @brief Returns the instance of a NullFactory.
     *
     * @return NullFactory instance
     */
    static NullFactory& getInstance();

    /**
     * @brief Creates NullCondition.
     *
     * @result NullCondition
     */
    ConditionPtr createCondition() const;

    /**
     * @brief Creates NullConditions.
     *
     * @result NullConditions
     */
    ConditionsPtr createConditions() const;

    /**
     * @brief Creates NullContext.
     *
     * @result NullContext
     */
    ContextPtr createContext() const;

    /**
     * @brief Creates NullCoordinate.
     *
     * @result NullCoordinate
     */
    CoordinatePtr createCoordinate() const;

    /**
     * @brief Creates NullCoordinates.
     *
     * @result NullCoordinates
     */
    CoordinatesPtr createCoordinates() const;

    /**
     * @brief Creates NullDefinition.
     *
     * @result NullDefinition
     */
    DefinitionPtr createDefinition() const;

    /**
     * @brief Creates NullDetails.
     *
     * @result NullDetails
     */
    DetailsPtr createDetails() const;

    /**
     * @brief Creates NullGame.
     *
     * @result NullGame
     */
    GamePtr createGame() const;

    /**
     * @brief Creates NullObject.
     *
     * @result NullObject
     */
    ObjectPtr createObject() const;

    /**
     * @brief Creates NullObjects.
     *
     * @result NullObjects
     */
    ObjectsPtr createObjects() const;

    /**
     * @brief Creates NullParam.
     *
     * @result NullParam
     */
    ParamPtr createParam() const;

    /**
     * @brief Creates NullParams.
     *
     * @result NullParams
     */
    ParamsPtr createParams() const;

    /**
     * @brief Creates NullPlayer.
     *
     * @result NullPlayer
     */
    PlayerPtr createPlayer() const;

    /**
     * @brief Creates NullPositions.
     *
     * @result NullPositions
     */
    PositionsPtr createPositions() const;

    /**
     * @brief Creates NullResult.
     *
     * @result NullResult
     */
    ResultPtr createResult() const;

    /**
     * @brief Creates NullQuery.
     *
     * @result NullQuery
     */
    QueryPtr createQuery() const;

    /**
     * @brief Creates NullDriver.
     *
     * @result NullDriver
     */
    DriverPtr createDriver() const;

    /**
     * @brief Creates NullConditionDriver.
     *
     * @result NullConditionDriver
     */
    ConditionDriverPtr createConditionDriver() const;

    /**
     * @brief Creates NullCoordinateDriver.
     *
     * @result NullCooridnateDriver
     */
    CoordinateDriverPtr createCoordinateDriver() const;

    /**
     * @brief Creates NullGameDriver.
     *
     * @result NullGameDriver
     */
    GameDriverPtr createGameDriver() const;

    /**
     * @brief Creates NullValueDriver.
     *
     * @result NullValueDriver
     */
    ValueDriverPtr createValueDriver() const;

    /**
     * @brief Creates NullStatementDriver.
     *
     * @result NullStatementDriver
     */
    StatementDriverPtr createStatementDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Coordinate>.
     *
     * @result NullCollectionsDriver<Coordinate>
     */
    CollectionsDriverPtr<Coordinate> createCoordinatesDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Condition>.
     *
     * @result NullCollectionsDriver<Condition>
     */
    CollectionsDriverPtr<Condition> createConditionsDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Identifier>.
     *
     * @result NullCollectionsDriver<Identifier>
     */
    CollectionsDriverPtr<Identifier> createIdentifiersDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Object>.
     *
     * @result NullCollectionsDriver<Object>
     */
    CollectionsDriverPtr<Object> createObjectsDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Param>.
     *
     * @result NullCollectionsDriver<Param>
     */
    CollectionsDriverPtr<Param> createParamsDriver() const;

    /**
     * @brief Creates null InputLocation.
     *
     * @return InputLocation
     */
    InputLocationPtr createInputLocation() const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    NullFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    NullFactory(
        const NullFactory& nullFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~NullFactory();
}; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_NULL_FACTORY_HPP__ */
