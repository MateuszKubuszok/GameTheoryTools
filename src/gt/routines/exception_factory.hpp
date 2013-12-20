#ifndef __GT_ROUTINES_EXCEPTION_FACTORY_HPP__
#define __GT_ROUTINES_EXCEPTION_FACTORY_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of exception instances for Routines classes.
 *
 * @author Mateusz Kubuszok
 */
class ExceptionFactory {
public:
    /**
     * @brief Returns the instance of a ExceptionFactory.
     *
     * @return ExceptionFactory instance
     */
    static ExceptionFactory& getInstance();

    /**
     * @brief Thrown when Condition is invalid for some Routine.
     *
     * @param exception exception to pass
     * @return          InvalidCondition exception to throw
     */
    InvalidCondition invalidCondition(
        const std::exception& exception
    ) const;

    /**
     * @brief Thrown when Condition is invalid for some Routine.
     *
     * @param expectedGame expected Game type
     * @return             InvalidGameType exception to throw
     */
    InvalidGameType invalidGameType(
        const Identifier& expectedGame
    ) const;

    /**
     * @brief Thrown when non existing Player is chosen.
     *
     * @param playerName name of sought Player
     * @return           InvalidPlayerChoice exception to throw
     */
    InvalidPlayerChoice playerNotFound(
        const Identifier& playerName
    ) const;

    /**
     * @brief Thrown when non existing strategy is chosen.
     *
     * @param playerName name of Player
     * @param strategy   name of strategy
     * @return           InvalidPlayerChoice exception to throw
     */
    InvalidPlayerChoice strategyNotFound(
        const Identifier& playerName,
        const Identifier& strategy
    ) const;

    /**
     * @brief Thrown when payoff is not available for some Player's strategy.
     *
     * @param playerName name of Player
     * @param strategy   name of strategy
     * @return           IncompletePayoffInformation exception to throw
     */
    IncompletePayoffInformation incompletePayoffInformation(
        const Identifier& playerName,
        const Identifier& strategy
    ) const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    ExceptionFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    ExceptionFactory(
        const ExceptionFactory& exceptionFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ExceptionFactory();
}; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_EXCEPTION_FACTORY_HPP__ */
