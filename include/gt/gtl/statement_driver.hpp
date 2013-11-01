#ifndef __GT_GTL_STATEMENT_DRIVER_HPP__
#define __GT_GTL_STATEMENT_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for handling statements via Driver.
 *
 * @author Mateusz Kubuszok
 *
 * @see Driver
 * @see Definition
 * @see Query
 * @see Parser
 */
class StatementDriver : public virtual Root {
public:
    /**
     * @brief Executes Definition saving Object under defined name.
     *
     * @param definition definition to execute
     */
    virtual bool executeDefinition(
        DefinitionPtr* definition
    ) = 0;

    /**
     * @brief Executes Query saving Object under defined name.
     *
     * @param query query to execute
     */
    virtual bool executeQuery(
        QueryPtr* query
    ) = 0;

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
    ) = 0;

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
    ) = 0;

    /**
     * @brief StatementDriver's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class StatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    virtual bool executeDefinition(
        DefinitionPtr*
    ) {
        return true;
    }

    virtual bool executeQuery(
        QueryPtr*
    ) {
        return true;
    }

    virtual DefinitionPtr* createDefinition(
        InputLocation&,
        IdentifierPtr*,
        ObjectPtr*
    ) {
        return new DefinitionPtr(NullFactory::getInstance().createDefinition());
    }

    virtual QueryPtr* createQuery(
        InputLocation&,
        IdentifiersPtr*,
        ObjectsPtr*,
        ConditionsPtr*
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_STATEMENT_DRIVER_HPP__ */
