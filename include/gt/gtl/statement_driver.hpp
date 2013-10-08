#ifndef __GT_GTL_STATEMENT_DRIVER_HPP__
#define __GT_GTL_STATEMENT_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for handling Games via Driver.
 *
 * @author Mateusz Kubuszok
 */
class StatementDriver : public virtual Root {
public:
    /**
     * @brief Executes Definition saving Object under defined name.
     *
     * @param definition definition to execute
     */
    virtual void executeDefinition(
        DefinitionPtr* definition
    ) = 0;

    /**
     * @brief Executes Query saving Object under defined name.
     *
     * @param query query to execute
     */
    virtual void executeQuery(
        QueryPtr* query
    ) = 0;

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
    ) = 0;

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
    ) = 0;

    /**
     * @brief StatementDriver's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class StatementDriver */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null StatementDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullStatementDriver : public StatementDriver {
public:
    NullStatementDriver() :
        StatementDriver()
        {}

    virtual void executeDefinition(
        DefinitionPtr* definition
    ) {}

    virtual void executeQuery(
        QueryPtr* query
    ) {}

    virtual DefinitionPtr* createDefinition(
        IdentifierPtr* identifier,
        ObjectPtr*     object
    ) {
        return new DefinitionPtr(NullFactory::getInstance().createDefinition());
    }

    virtual QueryPtr* createQuery(
        IdentifiersPtr* identifiers,
        ObjectsPtr*     objects,
        ConditionsPtr*  conditions
    ) {
        return new QueryPtr(NullFactory::getInstance().createQuery());
    }

    virtual bool isNotNull() {
        return false;
    }
    
    virtual Message toString() {
        return Message("NullStatementDriver");
    }
}; /* END class NullStatementDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_STATEMENT_DRIVER_HPP__ */
