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
class PlayerChoiceCondition final : public Condition {
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
     * @brief Returns Condition applicable to Route.
     *
     * @param             Context
     * @return            Condition applicable to Route
     * @throw InvalidType thrown when either player or strategy are not IdentifierParams
     */
    virtual Routines::ConditionPtr getCondition(
        const Context& context
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
