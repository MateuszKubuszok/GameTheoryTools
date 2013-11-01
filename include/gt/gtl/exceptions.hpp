#ifndef __GT_GTL_EXCEPTIONS_HPP__
#define __GT_GTL_EXCEPTIONS_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when Params create the cycle.
 *
 * @author Mateusz Kubuszok
 */
class CyclicIdentifiers : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit CyclicIdentifiers(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class CyclicIdentifiers */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when attempting to access content in invalid way.
 *
 * <p>By invalid it should be understand e.g. accessing Object for ValueParam,
 * or Value for ObjectParam.</p>
 *
 * @author Mateusz Kubuszok
 */
class InvalidContentRequest : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidContentRequest(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidContentRequest */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
}; /* END class InvalidProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when casting Object to invalid type.
 *
 * @author Mateusz Kubuszok
 */
class InvalidType : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidType(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidType */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Intened to be thrown when attempting to access not defined Param.
 *
 * <p>By invalid it should be understand e.g. accessing Object for ValueParam,
 * or Value for ObjectParam.</p>
 *
 * @author Mateusz Kubuszok
 */
class NotDefinedParam : public std::invalid_argument {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit NotDefinedParam(const Message& message) :
        std::invalid_argument(message)
        {}
}; /* END class NotDefinedParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXCEPTIONS_HPP__ */
