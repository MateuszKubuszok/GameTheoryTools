#ifndef __GT_GTL_PARAM_VALUE_PROPERTY_HPP__
#define __GT_GTL_PARAM_VALUE_PROPERTY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ParamValueProperty : public ObjectProperty {
    /**
     * @brief Described Param.
     */
    Param* param;

public:
    /**
     * @brief Initiates Property with Param it's describing.
     *
     * @param describedParam described Param
     */
    ParamValueProperty(
        Param* describedParam
    );

    /**
     * @brief Finds Params's value.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class ParamValueProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PARAM_VALUE_PROPERTY_HPP__ */
