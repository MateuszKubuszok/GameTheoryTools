#ifndef __GT_GTL_EXECUTION_STATEMENT_DRIVER_HPP__
#define __GT_GTL_EXECUTION_STATEMENT_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling statements via ExecutionDriver.
 *
 * <p>Performs actual execution of instructions for statements.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see StatementDriver
 */
class ExecutionStatementDriver : public StatementDriver {
    /**
     * @brief Driver for error handling.
     */
    CheckingStatementDriver checkingStatementDriver;
    /**
     * @brief Implementation of a main Driver.
     */
    Driver*                 driver;
    /**
     * @brief Contains Context.
     */
    Context*                context;

public:
    /**
     * @brief Initiates ExecutionStatementDriver with its parent.
     *
     * @param parentDriver parent Driver
     * @param context      Context data
     */
    ExecutionStatementDriver(
        Driver*  parentDriver,
        Context* context
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
     * @brief ExecutionStatementDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class ExecutionStatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_STATEMENT_DRIVER_HPP__ */
