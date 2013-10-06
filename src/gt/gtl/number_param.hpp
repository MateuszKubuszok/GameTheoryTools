#ifndef __GT_GTL_NUMBER_PARAM_HPP__
#define __GT_GTL_NUMBER_PARAM_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Param containing Number value. 
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Param
 * @see ParamFactory
 */   
class NumberParam : public Param {
    NumberPtr value;

public:
    /**
     * @brief Initiates Param with Number.
     *
     * @param number Number
     */
    explicit NumberParam(
        NumberPtr number
    );

    /**
     * @brief Returns Object for Context.
     *
     * @param context                Context with values
     * @param visitedIdentifiers     already visited Identifiers
     * @return                       Object
     * @thrown InvalidContentRequest thrown always for this implementation
     */
    virtual ObjectPtr getObject(
        Context&            context,
        VisitedIdentifiers& visitiedIdentifiers
    );

    /**
     * @brief Returns Number for context.
     *
     * @param context            Context with values
     * @param visitedIdentifiers already visited Identifiers
     * @return                   Number
     */
    virtual NumberPtr getNumber(
        Context&            context,
        VisitedIdentifiers& visitiedIdentifiers
    );

    /**
     * @brief IdntifierParam's Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class NumberParam */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_NUMBER_PARAM_HPP__ */
