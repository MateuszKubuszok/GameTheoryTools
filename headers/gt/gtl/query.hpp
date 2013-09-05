#ifndef __GT_GTL_QUERY_HPP__
#define __GT_GTL_QUERY_HPP__

namespace GT {
namespace GTL {

/**
 * @brief Defines Game.
 *
 * @author Mateusz Kubuszok
 */
class Query : public virtual Root {
public:
    /**
     * @brief Execute Query in a defined Context.
     *
     * @param context Context with definitions
     */
    virtual ResultPtr execute(
        Context& context
    );

    /**
     * @brief Returns Query results.
     *
     * @result Query results
     */
    virtual Message getResult();
}; /* END class Game */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_QUERY_HPP__ */
