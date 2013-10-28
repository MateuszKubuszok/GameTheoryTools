#ifndef __GT_GTL_COORDINATE_HPP__
#define __GT_GTL_COORDINATE_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contains some coordinate as well as data boind to it.
 *
 * @author Mateusz Kubuszok
 */
class Coordinate : public virtual ValidableSymbol {
    /**
     * @brief Merges two Coordinates into one.
     *
     * @param coordinate1 first coordinate
     * @param coordinate2 second coordinate
     * @return            merged coordinates
     */
    friend Coordinate operator+(
        Coordinate& coordinate1,
        Coordinate& coordinate2
    );

    /**
     * @brief Defined Positions.
     */
    const PositionsPtr positions;

    /**
     * @brief Defined Params.
     */
    const ParamsPtr params;

    /**
     * @brief Defined subcoordinetes.
     */
    const CoordinatesPtr subCoordinates;

public:
    /**
     * @brief Default constructor.
     */
    Coordinate();

    /**
     * @brief Constructor for initial strategies.
     *
     * @param player   player   identifier
     * @param strategy strategy identifier
     */
    Coordinate(
        const IdentifierPtr player,
        const IdentifierPtr strategy
    );

    /**
     * @brief Adds Param to the list.
     *
     * @param param single Param
     * @return      reference to itself
     */
    virtual Coordinate& addParam(
        const ParamPtr param
    );

     /**
     * @brief Adds Params to the list.
     *
     * @param params Params' vector
     * @return       reference to itself
     */
    virtual Coordinate& addParams(
        const ParamsPtr params
    );

    /**
     * @brief Add Position to known Coordinates.
     *
     * @param player   player (dimension)
     * @param strategy strategy (position on dimension)
     * @return         reference to itself
     */
    virtual Coordinate& addPosition(
        const IdentifierPtr player,
        const IdentifierPtr strategy
    );

    /**
     * @brief Adds SubCoordinate.
     *
     * @param subCoordinate SubCoordinate
     * @return              reference to itself
     */
    virtual Coordinate& addSubCoordinate(
        const CoordinatePtr subCoordinate
    );

    /**
     * @brief Adds SubCoordinates.
     *
     * @param subCoordinates SubCoordinate
     * @return               reference to itself
     */
    virtual Coordinate& addSubCoordinates(
        const CoordinatesPtr subCoordinates
    );

    /**
     * @brief Obtains params.
     *
     * @return Params
     */
    virtual ParamsPtr getParams();

     /**
     * @brief Obtains Positions.
     *
     * @return Positions
     */
    virtual PositionsPtr getPositions();

    /**
     * @brief Obtain SubCoordinates.
     *
     * @return SubCoordinates
     */
    virtual CoordinatesPtr getSubCoordinates();

    /**
     * @brief Fill DataBuilder with its data.
     *
     * @param context               Context with params
     * @param dataBuilder           DataBuilder to fill
     * @throw CyclicIdentifiers     thrown when some Identfiers create the cycle
     * @throw InvalidContentRequest thrown when some Param does not contain Number
     * @throw NotDefinedParam       thrown when some Param cannot find value inside Context
     * @throw IllegalInnerState     thrown when some of positions are already set
     * @throw InvalidCoordinate     thrown when some of values are not valid strategies names
     * @throw IllegalInnerState     thrown when attempting to set params when
     *                              not all coordinates are known
     */
    virtual void fillDataBuilder(
        Context&               context,
        Model::DataBuilderPtr& dataBuilder
    );

    /**
     * @brief Returns Coordinate Message
     *
     * @return Message
     */
    virtual GT::Message toString();
}; /* END class Coordinate */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Coordinate for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCoordinate : public Coordinate {
public:
    virtual Coordinate& addParams(
        const ParamPtr
    ) {
        return *this;
    }

    virtual Coordinate& addParams(
        const ParamsPtr
    ) {
        return *this;
    }

    virtual Coordinate& addPosition(
        const IdentifierPtr,
        const IdentifierPtr
    ) {
        return *this;
    }

    virtual Coordinate& addSubCoordinates(
        const CoordinatePtr
    ) {
        return *this;
    }

    virtual Coordinate& addSubCoordinates(
        const CoordinatesPtr
    ) {
        return *this;
    }

    virtual ParamsPtr getParams() {
        return NullFactory::getInstance().createParams();
    }

    virtual PositionsPtr getPositions() {
        return NullFactory::getInstance().createPositions();
    }

    virtual CoordinatesPtr getSubCoordinates() {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullCoordinate");
    }
}; /* END class NullCoordinate */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Coordinate for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorCoordinate : public Coordinate {
    Message message;

public:
    ErrorCoordinate(
        Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual Coordinate& addParams(
        const ParamPtr
    ) {
        return *this;
    }

    virtual Coordinate& addParams(
        const ParamsPtr
    ) {
        return *this;
    }

    virtual Coordinate& addPosition(
        const IdentifierPtr,
        const IdentifierPtr
    ) {
        return *this;
    }

    virtual Coordinate& addSubCoordinates(
        const CoordinatePtr
    ) {
        return *this;
    }

    virtual Coordinate& addSubCoordinates(
        const CoordinatesPtr
    ) {
        return *this;
    }

    virtual ParamsPtr getParams() {
        return NullFactory::getInstance().createParams();
    }

    virtual PositionsPtr getPositions() {
        return NullFactory::getInstance().createPositions();
    }

    virtual CoordinatesPtr getSubCoordinates() {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual bool isValid() const {
        return false;
    }

    virtual Message toString() {
        return message;
    }
}; /* END class ErrorCoordinate */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_COORDINATE_HPP__ */
