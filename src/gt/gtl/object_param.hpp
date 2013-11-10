#ifndef __GT_GTL_OBJECT_PARAM_HPP__
#define __GT_GTL_OBJECT_PARAM_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Param containing Object value.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Param
 * @see ParamFactory
 */
class ObjectParam : public Param {
    /**
     * @brief Value stored by this Param.
     */
    const ObjectPtr value;

public:
    /**
     * @brief Initiates Param with Object.
     *
     * @param number Number
     */
    explicit ObjectParam(
        const ObjectPtr object
    );

    /**
     * @brief Returns Object for Context.
     *
     * @param context            Context with values
     * @param visitedIdentifiers already visited Identifiers
     * @return                   Object
     */
    virtual const ObjectPtr getObject(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief Returns Number for context.
     *
     * @param context                Context with values
     * @param visitedIdentifiers     already visited Identifiers
     * @return                       Number
     * @thrown InvalidContentRequest thrown always for this implementation
     */
    virtual const NumberPtr getNumber(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief ObjectParam's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ObjectParam */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_OBJECT_PARAM_HPP__ */
