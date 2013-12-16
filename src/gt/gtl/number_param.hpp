#ifndef __GT_GTL_NUMBER_PARAM_HPP__
#define __GT_GTL_NUMBER_PARAM_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Param containing Number value.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Param
 * @see ParamFactory
 */
class NumberParam final : public Param {
    /**
     * @brief Number stored by this Param.
     */
    const NumberPtr value;

public:
    /**
     * @brief Initiates Param with Number.
     *
     * @param number Number
     */
    explicit NumberParam(
        const NumberPtr number
    );

    /**
     * @brief Returns Object for Context.
     *
     * @param context                Context with values
     * @param visitedIdentifiers     already visited Identifiers
     * @return                       Object
     * @thrown InvalidContentRequest thrown always for this implementation
     */
    virtual const ObjectPtr getObject(
        const Context&      context,
        VisitedIdentifiers& visitiedIdentifiers
    ) const override;

    /**
     * @brief Returns Number for context.
     *
     * @param context            Context with values
     * @param visitedIdentifiers already visited Identifiers
     * @return                   Number
     */
    virtual const NumberPtr getNumber(
        const Context&      context,
        VisitedIdentifiers& visitiedIdentifiers
    ) const override;

    /**
     * @brief NumberParam's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class NumberParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_NUMBER_PARAM_HPP__ */
