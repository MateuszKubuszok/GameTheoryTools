#ifndef __GT_GTL_EXCEPTIONS_HPP__
#define __GT_GTL_EXCEPTIONS_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when accessing non-existing Objects' property.
 *
 * @author Mateusz Kubuszok
 */
class InvalidProperty : public std::invalid_argument {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidProperty(const Message& message) :
        std::invalid_argument(message)
        {}
}; /* END class InvalidCoordinate */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXCEPTIONS_HPP__ */
