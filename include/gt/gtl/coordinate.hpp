#ifndef __GT_GTL_COORDINATE_HPP__
#define __GT_GTL_COORDINATE_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contains some Coordinate as well as data bound to it.
 *
 * <p>They can be considered pieces from which sets of pure strategies will be built. For strategic-form
 * games it means putting together all player-strategy pairs as to create whole vector for payoff function.
 * For extensive-form games it means going from root to leafs, one node at a time.</p>
 *
 * <p>Example of piece of code recognized by Parser:</p>
 *
 * <p><pre>
 * {
 *    p1 = p1s1 :
 *    { p2 = p2s1 : 10, 20 },
 *    { p2 = p2s2 : 30, 40 }
 * },
 * {
 *    p1 = p1s2 :
 *    { p2 = p2s1 : 50, 60 },
 *    { p2 = p2s2 : 70, 80 }
 * }
 * </pre></p>
 *
 * @author Mateusz Kubuszok
 *
 * @see CoordinateDriver
 * @see Parser
 */
class Coordinate : public virtual ValidableSymbol {

    /**
     * @brief Defined Positions.
     */
    const PositionsPtr positions;

    /**
     * @brief Defined Params.
     */
    const ParamsPtr params;

    /**
     * @brief Defined subCoordinetes.
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
     * @brief Obtains Params.
     *
     * @return Params
     */
    virtual const ParamsPtr getParams() const;

     /**
     * @brief Obtains Positions.
     *
     * @return Positions
     */
    virtual const PositionsPtr getPositions() const;

    /**
     * @brief Obtain SubCoordinates.
     *
     * @return SubCoordinates
     */
    virtual const CoordinatesPtr getSubCoordinates() const;

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
        const Context&         context,
        Model::DataBuilderPtr& dataBuilder
    ) const;

    /**
     * @brief Returns Coordinate Message
     *
     * @return Message
     */
    virtual GT::Message toString() const override;

    /**
     * @brief Merges two Coordinates into one.
     *
     * @param coordinate1 first Coordinate
     * @param coordinate2 second Coordinate
     * @return            merged Coordinates
     */
    friend Coordinate operator+(
        const Coordinate& coordinate1,
        const Coordinate& coordinate2
    );
}; /* END class Coordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Coordinate for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCoordinate final : public Coordinate {
public:
    virtual Coordinate& addParam(
        const ParamPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addParams(
        const ParamsPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addPosition(
        const IdentifierPtr,
        const IdentifierPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addSubCoordinate(
        const CoordinatePtr
    ) override {
        return *this;
    }

    virtual Coordinate& addSubCoordinates(
        const CoordinatesPtr
    ) override {
        return *this;
    }

    virtual const ParamsPtr getParams() const override {
        return NullFactory::getInstance().createParams();
    }

    virtual const PositionsPtr getPositions() const override {
        return NullFactory::getInstance().createPositions();
    }

    virtual const CoordinatesPtr getSubCoordinates() const override {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullCoordinate");
    }
}; /* END class NullCoordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Coordinate for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorCoordinate final : public Coordinate {
    /**
     * @brief Error message.
     */
    Message message;

public:
    ErrorCoordinate(
        Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual Coordinate& addParam(
        const ParamPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addParams(
        const ParamsPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addPosition(
        const IdentifierPtr,
        const IdentifierPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addSubCoordinate(
        const CoordinatePtr
    ) override {
        return *this;
    }

    virtual Coordinate& addSubCoordinates(
        const CoordinatesPtr
    ) override {
        return *this;
    }

    virtual const ParamsPtr getParams() const override {
        return NullFactory::getInstance().createParams();
    }

    virtual const PositionsPtr getPositions() const override {
        return NullFactory::getInstance().createPositions();
    }

    virtual const CoordinatesPtr getSubCoordinates() const override {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorCoordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_COORDINATE_HPP__ */
