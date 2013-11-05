#ifndef __GT_ROUTINES_NOT_YET_IMPLEMENTED_ROUTINE_HPP__
#define __GT_ROUTINES_NOT_YET_IMPLEMENTED_ROUTINE_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Routune returning "Not yet implemented" Message.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class NotYetImplementedRoutine : public Routine {
public:
    /**
     * @brief Returns "Not yet implemented" Message.
     *
     * @param game       Game definition
     * @param conditions Conditions for this Routine
     * @return           Result for fiven Game and Conditions
     */
    virtual ResultPtr findResultFor(
        GamePtr       game,
        ConditionsPtr conditions
    );

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString();
}; /* END class NotYetImplementedRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_NOT_YET_IMPLEMENTED_ROUTINE_HPP__ */
