#ifndef __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_HPP__
#define __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Routune returning pure strategy equilibrium for Extensive Game.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class ExtensivePureEquilibriumRoutine final : public SelectableStrategiesRoutine {
public:
    /**
     * @brief Initiates Routine with available Players.
     *
     * @param players Players definitions
     */
    explicit ExtensivePureEquilibriumRoutine(
        const PlayersPtr players
    );

    /**
     * @brief Returns pure strategy equilibrium for Extensive Game.
     *
     * @param game       Game definition
     * @param conditions Conditions for this Routine
     * @return           Result for fiven Game and Conditions
     */
    virtual ResultPtr findResultFor(
        const GamePtr       game,
        const ConditionsPtr conditions
    ) const override;

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString() const override;

private:
    /**
     * @brief Continas bottom-top best payoff partial results.
     */
    typedef boost::container::map<Identifier, const NumbersPtr> CalculatedPayoffs;

    /**
     * @brief Returns best payoff for Player in checkedNode and adds that choice to optimalChoices.
     *
     * @param strategicPositionsHelper positions helper that calculates position of compared payoff
     * @param extensivePositionsHelper positions helper that calculates the information set of checkedNode
     * @param checkedNode              node that should its best payoff calculated
     * @param optimalChoices           contains all optimal choices of already checked decisions
     * @return                         value of optimal Payoff for current Player in checkedNode
     */
    NumbersPtr getBestPayoffWhen(
        const Model::StrategicGamePositionsHelper& strategicPositionsHelper,
        const Model::ExtensiveGamePositionsHelper& extensivePositionsHelper,
        const Model::ExtensiveDataNode&            checkedNode,
        ExtensivePureStrategyPath&                 optimalChoices
    ) const;
}; /* END class ExtensivePureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_HPP__ */
