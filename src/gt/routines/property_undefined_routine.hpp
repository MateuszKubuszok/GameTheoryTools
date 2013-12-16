#ifndef __GT_ROUTINES_PROPERTY_UNDEFINED_ROUTINE_HPP__
#define __GT_ROUTINES_PROPERTY_UNDEFINED_ROUTINE_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Routune returning "Property not defined for this kind of Game" Message.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class PropertyUndefinedRoutine final : public Routine {
public:
    /**
     * @brief Returns "Property not defined for this kind of Game" Message.
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
}; /* END class PropertyUndefinedRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_PROPERTY_UNDEFINED_ROUTINE_HPP__ */
