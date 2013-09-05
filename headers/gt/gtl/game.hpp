#ifndef __GT_GTL_GAME_HPP__
#define __GT_GTL_GAME_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Game.
 *
 * @author Mateusz Kubuszok
 */
class Game : public virtual Object {
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

    /**
     * @brief Returns Message about Game.
     *
     * @return Game's state
     */
    virtual Message toString();
}; /* END class Game */

////////////////////////////////////////////////////////////////////////////////

class NullGame : public virtual Game {
public:
    virtual CoordinatePtr findEquilibrium(
        const Context&      context,
        const ConditionsPtr conditions
    ) {
        return NullFactory::getInstance().createCoordinate();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullGame");
    }
}; /* END class NullGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_HPP__ */
