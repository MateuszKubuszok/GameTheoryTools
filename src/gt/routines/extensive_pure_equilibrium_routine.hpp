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
class ExtensivePureEquilibriumRoutine : public SelectableStrategiesRoutine {
public:
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
    ) override;

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString() const override;
}; /* END class ExtensivePureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_HPP__ */
