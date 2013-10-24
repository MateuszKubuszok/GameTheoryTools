#ifndef __GT_GTL_EXECUTION_STATEMENT_DRIVER_HPP__
#define __GT_GTL_EXECUTION_STATEMENT_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling statements via ExecutionDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see StatementDriver
 */
class ExecutionStatementDriver : public StatementDriver {
    Driver* driver;

public:
    /**
     * @brief Initiates ExecutionStatementDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    ExecutionStatementDriver(
        Driver* parentDriver
    );

    /**
     * @brief Executes Definition saving Object under defined name.
     *
     * @param definition definition to execute
     */
    virtual bool executeDefinition(
        DefinitionPtr* definition
    );

    /**
     * @brief Executes Query saving Object under defined name.
     *
     * @param query query to execute
     */
    virtual bool executeQuery(
        QueryPtr* query
    );

    /**
     * @brief Creates Definition saving Object under defined name.
     *
     * @param inputLocation input location of created Definition
     * @param identifier    name of defined Object
     * @param object        defined Object
     * @return              Definition
     */
    virtual DefinitionPtr* createDefinition(
        InputLocation& inputLocation,
        IdentifierPtr* identifier,
        ObjectPtr*     object
    );

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
        InputLocation&  inputLocation,
        IdentifiersPtr* identifiers,
        ObjectsPtr*     objects,
        ConditionsPtr*  conditions
    );

    /**
     * @brief ExecutionStatementDriver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class ExecutionStatementDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_STATEMENT_DRIVER_HPP__ */
