#ifndef __GT_GTL_CONDITION_HPP__
#define __GT_GTL_CONDITION_HPP__ 1

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Condition used for 
 *
 * @author Mateusz Kubuszok
 */
class Condition {
public:
    /**
     * @brief Default constructor.
     */
    Condition();

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
} /* END class Condition */

} /* END namepsace GTL */
} /* END namspace GT */

#endif /* #ifndef __GT_GTL_CONDITION_HPP__ */
