#ifndef __GT_GTL_EXCEPTION_FACTORY_HPP__
#define __GT_GTL_EXCEPTION_FACTORY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of exception instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class ExceptionFactory {
    SINGLETON_DECLARATION(ExceptionFactory)

public:
    /**
     * @brief Returns the instance of a ExceptionFactory.
     *
     * @return ExceptionFactory instance
     */
    static ExceptionFactory& getInstance();

    /**
     * @brief Thrown when Identfiers create the cycle.
     *
     * @param visitedIdentifiers already visited Identifiers
     * @param currentIdentifier  current Identifier
     * @return                   CyclicIdentifiers exception to throw
     */
    CyclicIdentifiers cyclicIdentifiersFound(
        Param::VisitedIdentifiers& visitedIdentifiers,
        Identifier&                currentIdentifier
    );

    /**
     * @brief Thrown when attepting to obtain nonexisting property from Object.
     *
     * @param propertyName invalid property name
     * @return             InvalidProperty exception to throw
     */
    InvalidProperty invalidObjectProperty(
        Identifier& propertyName
    );

    /**
     * @brief Thrown when attepting to obtain not defined Param.
     *
     * @param paramName invalid Param name
     * @return          NotDefinedParam exception to throw
     */
    NotDefinedParam notDefinedParam(
        Identifier& paramName
    );

    /**
     * @brief Thrown when attemting to obtain Number from ObjectParam.
     *
     * @return InvalidContentRequest exception to throw
     */
    InvalidContentRequest requiredUnavailableNumberFromParam();

    /**
     * @brief Thrown when attemting to obtain Object from NumberParam.
     *
     * @return InvalidContentRequest exception to throw
     */
    InvalidContentRequest requiredUnavailableObjectFromParam();

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

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXCEPTION_FACTORY_HPP__ */
