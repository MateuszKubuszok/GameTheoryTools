#ifndef __GT_GTL_PARAM_HPP__
#define __GT_GTL_PARAM_HPP__

namespace GT {
namespace GTL {
 
////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Abstract class that defines interface for Params. 
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Definition
 * @see ParamFactory
 */   
class Param : public virtual Object {
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
    virtual ObjectPtr getObject(
        Context& context
    );

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
    virtual ObjectPtr getObject(
        Context&            context,
        VisitedIdentifiers& visitedIdentifiers
    ) = 0;

    /**
     * @brief Returns Number for context.
     *
     * @param context               Context with values
     * @return                      Number
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Number
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual NumberPtr getNumber(
        Context& context
    );

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
    virtual NumberPtr getNumber(
        Context&            context,
        VisitedIdentifiers& visitedIdentifiers
    ) = 0;

protected:
    /**
     * @brief Checks whether visited Identifiers contain current one.
     *
     * @param visitedIdentifiers already cisited Identifiers
     * @param currentIdentifier  currently visited Identifier
     * @throw CyclicIdentifiers  thrown when Identifiers create the cycle 
     */
    void checkVisitedIdentifiers(
        VisitedIdentifiers& visitedIdentifiers,
        Identifier&         currentIdentifier
    );
}; /* END class Param */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Param for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullParam : public Param {
public:
    virtual ObjectPtr getObject(
        Context&
    ) {
        return NullFactory::getInstance().createObject();
    }

    virtual ObjectPtr getObject(
        Context&,
        VisitedIdentifiers&
    ) {
        return NullFactory::getInstance().createObject();
    }

    virtual NumberPtr getNumber(
        Context&
    ) {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual NumberPtr getNumber(
        Context&,
        VisitedIdentifiers&
    ) {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullParam");
    }
}; /* END class NullParam */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Param for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorParam : public Param {
    Message message;
    
public:
    ErrorParam(
        Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual ObjectPtr getObject(
        Context&
    ) {
        return NullFactory::getInstance().createObject();
    }

    virtual ObjectPtr getObject(
        Context&,
        VisitedIdentifiers&
    ) {
        return NullFactory::getInstance().createObject();
    }

    virtual NumberPtr getNumber(
        Context&
    ) {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual NumberPtr getNumber(
        Context&,
        VisitedIdentifiers&
    ) {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual bool isValid() const {
        return false;
    }

    virtual Message toString() {
        return message;
    }
}; /* END class ErrorParam */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_PARAM_HPP__ */
