#ifndef __GT_GTL_OBJECT_PROPERTY_HPP__
#define __GT_GTL_OBJECT_PROPERTY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Root of all Object's properties that can be registered.
 *
 * @author Mateusz Kubuszok
 */
class ObjectProperty {
public:
    /**
     * @brief Finds results for given Conditions.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const = 0;
}; /* END class ObjectProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_OBJECT_PROPERTY_HPP__ */
