#ifndef __GT_GTL_CHECKING_STATEMENT_DRIVER_HPP__
#define __GT_GTL_CHECKING_STATEMENT_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/checking_statement_driver.hpp
 * @brief     Defines GT::GTL::CheckingStatementDriver class.
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
 * @class CheckingStatementDriver
 * @brief Implementation used for handling statements via CheckingDriver.
 *
 * Performs only syntax/type checking on statements' tokens.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see StatementDriver
 */
class CheckingStatementDriver final : public StatementDriver {
    /**
     * @brief Implementation of a main Driver.
     */
    Driver* driver;

public:
    /**
     * @brief Initiates CheckingStatementDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit CheckingStatementDriver(
        Driver* parentDriver
    );

    /**
     * @brief Executes Definition saving Object under defined name.
     *
     * @param definition definition to execute
     */
    virtual bool executeDefinition(
        const DefinitionPtr* definition
    ) override;

    /**
     * @brief Executes Query saving Object under defined name.
     *
     * @param query query to execute
     */
    virtual bool executeQuery(
        const QueryPtr* query
    ) override;

    /**
     * @brief Creates Definition saving Object under defined name.
     *
     * @param inputLocation input location of created Definition
     * @param identifier    name of defined Object
     * @param object        defined Object
     * @return              Definition
     */
    virtual DefinitionPtr* createDefinition(
        const InputLocation& inputLocation,
        const IdentifierPtr* identifier,
        const ObjectPtr*     object
    ) const override;

    /**
     * @brief Creates Query for given properties.
     *
     * @param inputLocation input location of created Definition
     * @param identifiers   queried properties
     * @param objects       queried Object
     * @param conditions    Conditions
     * @return              Query
     */
    virtual QueryPtr* createQuery(
        const InputLocation&  inputLocation,
        const IdentifiersPtr* identifiers,
        const ObjectsPtr*     objects,
        const ConditionsPtr*  conditions
    ) const override;

    /**
     * @brief CheckingStatementDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class CheckingStatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_STATEMENT_DRIVER_HPP__ */
