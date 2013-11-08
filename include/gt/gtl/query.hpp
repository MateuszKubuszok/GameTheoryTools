#ifndef __GT_GTL_QUERY_HPP__
#define __GT_GTL_QUERY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Query.
 *
 * <p>Each Query is created within parser with:</p>
 *
 * <p><pre>
 * FIND [propertiesNames]
 * FOR  [objects]
 * [WITH condition1[, condition2[, ...]]]
 * </pre></p>
 *
 * @author Mateusz Kubuszok
 *
 * @see StatementDriver
 * @see Condition
 * @see Parser
 */
class Query : public virtual ValidableSymbol {
    /**
     * @brief Names of properties that Oject will be queried for.
     */
    IdentifiersPtr propertiesNames;

    /**
     * @brief Objects that will be queried.
     */
    ObjectsPtr     objects;

    /**
     * @brief Conditions of Query.
     */
    ConditionsPtr  conditions;

public:
    /**
     * @brief Initiates Query with properties, Objects and Conditions.
     *
     * @param propertiesName properties for which Cbjects will be queried,
     * @param objects        Objects to query for properties
     * @param conditions     Conditions for queries
     */
    Query(
        IdentifiersPtr propertiesName,
        ObjectsPtr     objects,
        ConditionsPtr  conditions
    );

    /**
     * @brief Execute Query in a defined Context.
     *
     * @param context Context with definitions
     */
    virtual ResultPtr execute(
        Context& context
    );

    /**
     * @brief Returns Query's Message.
     *
     * @return Message
     */
    virtual Message toString() override;
}; /* END class Query */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Query for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullQuery : public Query {
public:
    NullQuery() :
        Query(
            Model::NullFactory::getInstance().createIdentifiers(),
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createConditions()
        )
        {}

    virtual ResultPtr execute(
        Context&
    ) override {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullQuery");
    }
}; /* END class NullQuery */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Query for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorQuery : public Query {
    /**
     * @brief Error message.
     */
    Message message;

public:
    ErrorQuery(
        Message errorMessage
    ) :
        Query(
            Model::NullFactory::getInstance().createIdentifiers(),
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createConditions()
        ),
        message(errorMessage)
        {}

    virtual ResultPtr execute(
        Context&
    ) override {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() override {
        return message;
    }
}; /* END class ErrorQuery */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_QUERY_HPP__ */
