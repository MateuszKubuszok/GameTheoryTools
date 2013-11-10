#ifndef __GT_MODEL_DATA_ACCESSOR_HPP__
#define __GT_MODEL_DATA_ACCESSOR_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Custom interface for all Data accessing instances for Games.
 *
 * <p>Is extended by Data interface.</p>
 *
 * <p>Used to restrict access to Data to ensure that ontent can only be read.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Data
 */
class DataAccessor : public virtual Root {
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
 * @brief Null DataAccessor for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataAccessor : public DataAccessor {
public:
    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual const DataPiecePtr getValues(
        const Positions&
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr getValues(
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createDataPiece();
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
}; /* END class NullDataAccessor */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_ACCESSOR_HPP__ */
