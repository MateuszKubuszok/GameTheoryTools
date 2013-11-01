#ifndef __GT_MODEL_EXCEPTIONS_HPP__
#define __GT_MODEL_EXCEPTIONS_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when inner state of an object is not allowed.
 *
 * @author Mateusz Kubuszok
 */
class IllegalInnerState : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit IllegalInnerState(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class IllegalInnerState */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when coordinates to some value are invalid.
 *
 * @author Mateusz Kubuszok
 */
class InvalidCoordinate : public std::invalid_argument {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidCoordinate(const Message& message) :
        std::invalid_argument(message)
        {}
}; /* END class InvalidCoordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_EXCEPTIONS_HPP__ */
