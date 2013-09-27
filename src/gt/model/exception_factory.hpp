#ifndef __GT_MODEL_EXCEPTION_FACTORY_HPP__
#define __GT_MODEL_EXCEPTION_FACTORY_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class ExceptionFactory {
    /**
     * @brief Contains pointer to a ExceptionFactory instance.
     */
    static ExceptionFactory* volatile instance;

public:
    /**
     * @brief Returns the instance of a ExceptionFactory.
     *
     * @return ConditionFactory instance
     */
    static ExceptionFactory& getInstance();

    InvalidCoordinate coordinatesAlreadySet(
        Positions& positions
    );

    IllegalInnerState incompleteCoordinates();

    InvalidCoordinate invalidCoordinateFormat(
        Positions& position
    );

    InvalidCoordinate invalidTreeCoordinateFormat(
        Positions& position
    );

    InvalidCoordinate noParamsForPositions(
        Index positionInStorage,
        Index maxPosition
    );

    InvalidCoordinate invalidPlayer(
        Identifier& playerName
    );

    InvalidCoordinate invalidStrategy(
        Identifier& strategyName
    );

    IllegalInnerState playersAlreadySet();

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

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXCEPTION_FACTORY_HPP__ */
