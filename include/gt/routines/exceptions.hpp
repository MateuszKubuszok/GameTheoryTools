#ifndef __GT_ROUTINES_EXCEPTIONS_HPP__
#define __GT_ROUTINES_EXCEPTIONS_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when non existing Player or strategy is chosen.
 *
 * @author Mateusz Kubuszok
 */
class InvalidPlayerChoice : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidPlayerChoice(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidPlayerChoice */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when Condition is in some way invalid.
 *
 * @author Mateusz Kubuszok
 */
class InvalidCondition : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidCondition(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_EXCEPTIONS_HPP__ */
