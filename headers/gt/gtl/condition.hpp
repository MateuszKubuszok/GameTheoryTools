#ifndef __GT_GTL_CONDITION_HPP__
#define __GT_GTL_CONDITION_HPP__

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Condition used for querying objects with some requirements.
 *
 * @author Mateusz Kubuszok
 */
class Condition {
public:
    /**
     * @brief Default Destructor.
     */
    virtual ~Condition();

    /**
     * @brief Parametrizes query using the Injection of Control.
     *
     * @param query query to parametrize
     */
    // virtual void conditionQuery(Query &query) = 0;
}; /* END class Condition */

} /* END namepsace GTL */
} /* END namspace GT */

#endif /* END #ifndef __GT_GTL_CONDITION_HPP__ */
