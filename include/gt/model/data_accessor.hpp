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
    virtual PlayersPtr getPlayers() = 0;

    /**
     * @brief Returns values handler for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when coordinates are invalid
     */
    virtual DataPiecePtr getValues(
        PositionsPtr positions
    ) = 0;

    /**
     * @brief Returns values handler for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when coordinates are invalid
     */
    virtual DataPiecePtr getValues(
        Positions& positions
    ) = 0;

    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual DataPiecePtr operator[](
        Positions& positions
    ) = 0;

    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual DataPiecePtr operator[](
        PositionsPtr positions
    ) = 0;

    /**
     * @brief Returns Data's message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class Data */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null DataAccessor for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataAccessor : public DataAccessor {
public:
    virtual DataPiecePtr getValues(
        Positions&
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr getValues(
        PositionsPtr
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual PlayersPtr getPlayers() override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual DataPiecePtr operator[](
        Positions&
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[](
        PositionsPtr
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullData");
    }
}; /* END class NullDataAccessor */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_ACCESSOR_HPP__ */
