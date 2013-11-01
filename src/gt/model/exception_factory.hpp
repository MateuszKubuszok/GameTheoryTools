#ifndef __GT_MODEL_EXCEPTION_FACTORY_HPP__
#define __GT_MODEL_EXCEPTION_FACTORY_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of exceptions with predefined message format.
 *
 * @author Mateusz Kubuszok
 */
class ExceptionFactory {
    SINGLETON_DECLARATION(ExceptionFactory)

public:
    /**
     * @brief Returns the instance of a ExceptionFactory.
     *
     * @return ConditionFactory instance
     */
    static ExceptionFactory& getInstance();

    /**
     * @brief Thrown when values for given positions are already set.
     *
     * @param position invalid Positions
     * @return         InvalidCoordinate exception to throw
     */
    InvalidCoordinate coordinatesAlreadySet(
        Positions& positions
    );

    /**
     * @brief Thrown when some coordinates are uknown yet attept to store values is made.
     *
     * @return IllegalInnerState exception to throw
     */
    IllegalInnerState incompleteCoordinates();

    /**
     * @brief Thrown when some of the Players' names or strategies are invalid.
     *
     * @param position invalid Positions
     * @return         InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidCoordinateFormat(
        Positions& position
    );

    /**
     * @brief Thrown when there are colliding definitions of Player's playing in some turn.
     *
     * @param position invalid Positions
     * @return         InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidExtensiveCoordinateFormat(
        Positions& position
    );

    /**
     * @brief Thrown when ettepting to read from position that has not values defined.
     *
     * @param positionInStorage invalid position in storage
     * @param maxPosition       maximal position
     * @return                  InvalidCoordinate exception to throw
     */
    InvalidCoordinate noParamsForPositions(
        Index positionInStorage,
        Index maxPosition
    );

    /**
     * @brief Thrown when no Player with given name has been defined.
     *
     * @param playerName invalid Player's name
     * @return           InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidPlayer(
        Identifier& playerName
    );

    /**
     * @brief @brief Thrown when no strategy with given name has been defined.
     *
     * @param strategyName invalid strategy's name
     * @return             InvalidCoordinate exception to throw
     */
    InvalidCoordinate invalidStrategy(
        Identifier& strategyName
    );

    /**
     * @brief Thrown when attempt to redefine Players is made.
     *
     * @return IllegalInnerState exception to throw
     */
    IllegalInnerState playersAlreadySet();

    /**
     * @brief Thrown during attempt to build Result with properties' names and results not matching in size.
     *
     * @param propertiesSize properties' size
     * @param resultsSize    results' size
     * @return               IllegalInnerState exception to throw
     */
    IllegalInnerState propertiesAndResultsDontMatchInSize(
        Index propertiesSize,
        Index resultsSize
    );

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

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXCEPTION_FACTORY_HPP__ */
