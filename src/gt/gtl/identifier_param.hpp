#ifndef __GT_GTL_IDENTIFIER_PARAM_HPP__
#define __GT_GTL_IDENTIFIER_PARAM_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Param containing reference to other Param.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Param
 * @see ParamFactory
 */
class IdentifierParam final : public Param {
    /**
     * @brief Identifier that this Param points to.
     */
    const Identifier identifier;

public:
    /**
     * @brief Initiates Param with Identifier.
     *
     * @param id identifier
     */
    explicit IdentifierParam(
        const Identifier& id
    );

    /**
     * @brief Returns Identifier.
     *
     * @return Identifier
     */
    const Identifier& getIdentifier() const;

    /**
     * @brief Returns Object for Context.
     *
     * @param context            Context with values
     * @param visitedIdentifiers already visited Identifiers
     * @return                   Object
     * @throw CyclicIdentifiers  thrown when Identfiers create the cycle
     * @throw NotDefinedParam    thrown when Param cannot find value inside Context
     */
    virtual const ObjectPtr getObject(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief Returns Number for context.
     *
     * @param context            Context with values
     * @param visitedIdentifiers already visited Identifiers
     * @return                   Number
     * @throw CyclicIdentifiers  thrown when Identfiers create the cycle
     * @throw NotDefinedParam    thrown when Param cannot find value inside Context
     */
    virtual const NumberPtr getNumber(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief IdentifierParam's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class IdentifierParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_IDENTIFIER_PARAM_HPP__ */
