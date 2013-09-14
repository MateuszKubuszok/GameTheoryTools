#ifndef __GT_MODEL_EXCEPTIONS_HPP__
#define __GT_MODEL_EXCEPTIONS_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when inner state of an object is not allowed.
 *
 * @author Mateusz Kubuszok
 */
class IllegalInnerState : std::runtime_error {
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

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_EXCEPTIONS_HPP__ */
