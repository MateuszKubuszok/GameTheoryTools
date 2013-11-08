#ifndef __GT_ROUTINES_PLAYER_CHOICE_CONDITION_ROUTINE_HPP__
#define __GT_ROUTINES_PLAYER_CHOICE_CONDITION_ROUTINE_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Condition that configures Routine to allow only one choice from some Player.
 *
 * @author Mateusz Kubuszok
 *
 * @see SelectableStrategiesRoutine
 */
class PlayerChoiceCondition : public Condition {
    /**
     * @brief Player's name.
     */
    IdentifierPtr player;
    /**
     * @brief Chosen strategy.
     */
    IdentifierPtr strategy;

public:
    /**
     * @brief Initiates Condition with Player's name and chosen strategy.
     *
     * @param player   Player that chooses strategy
     * @param strategy chosen strategy
     */
    PlayerChoiceCondition(
        IdentifierPtr player,
        IdentifierPtr strategy
    );

    /**
     * @brief Configureg given Routine.
     *
     * @param routine          Routine to configure
     * @throw InvalidCondition thrown when Condition is invalid
     */
    virtual void configureRoutine(
        RoutinePtr routine
    ) override;

    /**
     * @brief Returns Condition's Message.
     *
     * @return Condition's Message
     */
    virtual Message toString() override;
}; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_PLAYER_CHOICE_CONDITION_ROUTINE_HPP__ */
