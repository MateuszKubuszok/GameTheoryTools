#ifndef __GT_GTL_GAME_HPP__
#define __GT_GTL_GAME_HPP__

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Defines Game.
 *
 * @author Mateusz Kubuszok
 */
class Game : public Object {
public:
    /**
     * @brief Search Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual CoordinatePtr findEquilibrium(
        const Context&      context,
        const ConditionsPtr conditions
    ) = 0;
}; /* END class Game */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_HPP__ */
