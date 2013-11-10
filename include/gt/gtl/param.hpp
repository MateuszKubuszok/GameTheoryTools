#ifndef __GT_GTL_PARAM_HPP__
#define __GT_GTL_PARAM_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Abstract class that defines interface for Params.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Definition
 * @see ParamFactory
 */
class Param : public Object {
public:
    /**
     * @brief Contains visited Identifiers to prevent cycles.
     */
    typedef boost::container::set<Identifier> VisitedIdentifiers;

    /**
     * @brief Default constructor.
     */
    Param();

    /**
     * @brief Returns Object for Context.
     *
     * @param context               Context with values
     * @return                      Object
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Object
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual const ObjectPtr getObject(
        const Context& context
    ) const;

    /**
     * @brief Returns Object for Context.
     *
     * @param context               Context with values
     * @param visitedIdentifiers    already visited Identifiers
     * @return                      Object
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Object
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual const ObjectPtr getObject(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const = 0;

    /**
     * @brief Returns Number for context.
     *
     * @param context               Context with values
     * @return                      Number
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Number
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual const NumberPtr getNumber(
        const Context& context
    ) const;

    /**
     * @brief Returns Number for context.
     *
     * @param context               Context with values
     * @param visitedIdentifiers    already visited Identifiers
     * @return                      Number
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Number
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual const NumberPtr getNumber(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const = 0;

    /**
     * @brief Explicit cast to Param type.
     *
     * @return Param
     */
    virtual operator const Param&() const override;

protected:
    /**
     * @brief Checks whether visited Identifiers contain current one.
     *
     * @param visitedIdentifiers already cisited Identifiers
     * @param currentIdentifier  currently visited Identifier
     * @throw CyclicIdentifiers  thrown when Identifiers create the cycle
     */
    void checkVisitedIdentifiers(
        const VisitedIdentifiers& visitedIdentifiers,
        const Identifier&         currentIdentifier
    ) const;
}; /* END class Param */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Param for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullParam : public Param {
public:
    virtual const ObjectPtr getObject(
        const Context&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const ObjectPtr getObject(
        const Context&,
        VisitedIdentifiers&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const NumberPtr getNumber(
        const Context&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual const NumberPtr getNumber(
        const Context&,
        VisitedIdentifiers&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullParam");
    }
}; /* END class NullParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Param for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorParam : public Param {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorParam(
        const Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual const ObjectPtr getObject(
        const Context&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const ObjectPtr getObject(
        const Context&,
        VisitedIdentifiers&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const NumberPtr getNumber(
        const Context&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual const NumberPtr getNumber(
        const Context&,
        VisitedIdentifiers&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_PARAM_HPP__ */
