#ifndef __GT_GTL_CHECKING_STATEMENT_DRIVER_HPP__
#define __GT_GTL_CHECKING_STATEMENT_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling statements via CheckingDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see StatementDriver
 */
class CheckingStatementDriver : public StatementDriver {
public:
    /**
     * @brief Executes Definition saving Object under defined name.
     *
     * @param definition definition to execute
     */
    virtual void executeDefinition(
        DefinitionPtr* definition
    );

    /**
     * @brief Executes Query saving Object under defined name.
     *
     * @param query query to execute
     */
    virtual void executeQuery(
        QueryPtr* query
    );

    /**
     * @brief Creates Definition saving Object under defined name.
     *
     * @param identifier name of defined Object
     * @param object     defined Object
     * @return           Definition
     */
    virtual DefinitionPtr* createDefinition(
        IdentifierPtr* identifier,
        ObjectPtr*     object
    );

    /**
     * @brief Creates Query for given properties.
     *
     * @param identifiers queried properties
     * @param objects     queried Object
     * @param conditions  Conditions
     * @return            Query
     */
    virtual QueryPtr* createQuery(
        IdentifiersPtr* identifiers,
        ObjectsPtr*     objects,
        ConditionsPtr*  conditions
    );

    /**
     * @brief CheckingStatementDriver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class CheckingStatementDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_STATEMENT_DRIVER_HPP__ */
