#ifndef __GT_MODEL_DATA_HPP__
#define __GT_MODEL_DATA_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Custom interface for all Data containers for Games.
 *
 * <p>Extends DataAccessor interface.</p>
 *
 * <p>Used to store all information necessary to calculate Nash equlibria for each type of Games.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see DataBuilder
 */
class Data : public DataAccessor {
public:
    /**
     * @brief Returns map of Players available in this DataAccessor.
     *
     * @return Players
     */
    virtual const PlayersPtr getPlayers() const = 0;

    /**
     * @brief Returns values handler for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when coordinates are invalid
     */
    virtual const DataPiecePtr getValues(
        const PositionsPtr positions
    ) const = 0;

    /**
     * @brief Returns values handler for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when coordinates are invalid
     */
    virtual const DataPiecePtr getValues(
        const Positions& positions
    ) const = 0;

    /**
     * @brief Sets values for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setValues(
        const Positions& positions,
        const NumbersPtr numbers
    ) = 0;

    /**
     * @brief Sets values for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setValues(
        const PositionsPtr positions,
        const NumbersPtr   numbers
    ) = 0;

    /**
     * @brief Returns Data's message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;

    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual const DataPiecePtr operator[](
        const Positions& positions
    ) const = 0;

    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual const DataPiecePtr operator[](
        const PositionsPtr positions
    ) const = 0;
}; /* END class Data */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Data for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullData : public Data {
public:
    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual const DataPiecePtr getValues(
        const Positions&
    )  const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr getValues(
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual Data& setValues(
        const Positions&,
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual Data& setValues(
        const PositionsPtr,
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullData");
    }

    virtual const DataPiecePtr operator[](
        const Positions&
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr operator[](
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }
}; /* END class NullData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_HPP__ */
