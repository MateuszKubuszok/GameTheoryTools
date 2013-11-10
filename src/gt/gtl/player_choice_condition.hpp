#ifndef __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__
#define __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Condition used for selecting strategy for a Player.
 *
 * @author Mateusz Kubuszok
 */
class PlayerChoiceCondition : public Condition {
    /**
     * @brief Param with Player's name.
     */
    const ObjectPtr player;
    /**
     * @brief Param with Player's choice.
     */
    const ObjectPtr strategy;

public:
    /**
     * @brief Initiates Condition with a Player's name and choice.
     *
     * @param Param with Player's name
     * @param Param with Player's choice
     */
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
    ) const override;

    /**
     * @brief Returns Message about Condition.
     *
     * @return Condition's Message
     */
    virtual Message toString() const override;
}; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__ */
