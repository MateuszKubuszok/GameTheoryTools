#ifndef __GT_GTL_PARAM_HPP__
#define __GT_GTL_PARAM_HPP__

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {
 
/**
 * @brief Abstract class that defines interface for Params. 
 *
 * @author Mateusz Kubuszok
 */   
class Param : public virtual Object {
public:
    /**
     * @brief Returns value for context.
     *
     * @param context context with values
     */
    virtual ObjectPtr getObject(
        const Context& context
    ) = 0;

    /**
     * @brief Returns value for context.
     *
     * @param context context with values
     */
    virtual NumberPtr getValue(
        const Context& context
    ) = 0;
}; /* END class Param */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_PARAM_HPP__ */
