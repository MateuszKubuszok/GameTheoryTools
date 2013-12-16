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
        const DefinitionPtr* definition
    ) = 0;

    /**
     * @brief Executes Query saving Object under defined name.
     *
     * @param query query to execute
     */
    virtual bool executeQuery(
        const QueryPtr* query
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
        const InputLocation& inputLocation,
        const IdentifierPtr* identifier,
        const ObjectPtr*     object
    ) const = 0;

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
    ) const = 0;

    /**
     * @brief StatementDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;
}; /* END class StatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null StatementDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullStatementDriver final : public StatementDriver {
public:
    NullStatementDriver() :
        StatementDriver()
        {}

    virtual bool executeDefinition(
        const DefinitionPtr*
    ) override {
        return true;
    }

    virtual bool executeQuery(
        const QueryPtr*
    ) override {
        return true;
    }

    virtual DefinitionPtr* createDefinition(
        const InputLocation& inputLocation,
        const IdentifierPtr*,
        const ObjectPtr*
    ) const override {
        return new DefinitionPtr(
            setupLocation<Definition>(
                NullFactory::getInstance().createDefinition(),
                inputLocation
            )
        );
    }

    virtual QueryPtr* createQuery(
        const InputLocation& inputLocation,
        const IdentifiersPtr*,
        const ObjectsPtr*,
        const ConditionsPtr*
    ) const override {
        return new QueryPtr(
            setupLocation<Query>(
                NullFactory::getInstance().createQuery(),
                inputLocation
            )
        );
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullStatementDriver");
    }
}; /* END class NullStatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_STATEMENT_DRIVER_HPP__ */
