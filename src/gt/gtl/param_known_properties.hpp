#ifndef __GT_GTL_PARAM_KNOWN_PROPERTIES_HPP__
#define __GT_GTL_PARAM_KNOWN_PROPERTIES_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Describes referred Object's known properties.
 *
 * @author Mateusz Kubuszok
 *
 * @see Param
 */
class ParamKnownProperties final : public ObjectProperty {
    /**
     * @brief Described Param.
     */
    const Param* param;

public:
    /**
     * @brief Initiates Property with Param it's describing.
     *
     * @param describedObject described Object
     */
    explicit ParamKnownProperties(
        const Param* describedParam
    );

    /**
     * @brief Finds Param's known propertes.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const override;
}; /* END class ParamKnownProperties */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PARAM_KNOWN_PROPERTIES_HPP__ */
