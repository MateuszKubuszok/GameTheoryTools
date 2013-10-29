#ifndef __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__
#define __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Condition used for selecting strategy for a player.
 *
 * @author Mateusz Kubuszok
 */
class PlayerChoiceCondition : public Condition {
    ObjectPtr player;
    ObjectPtr strategy;

public:
    PlayerChoiceCondition(
        const ObjectPtr player,
        const ObjectPtr strategy
    );

    /**
     * @brief Parametrizes query using the inversion of control.
     *
     * @param query query to parametrize
     */
    virtual void conditionQuery(
        Query& query
    );

    /**
     * @brief Returns Message about Condition.
     *
     * @return Condition's Message
     */
    virtual Message toString();
}; /* END class PlayerChoiceCondition */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__ */
