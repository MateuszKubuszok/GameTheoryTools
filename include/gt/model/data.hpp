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
     * @brief Sets values for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setValues(
        Positions& positions,
        NumbersPtr numbers
    ) = 0;

    /**
     * @brief Sets values for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) = 0;

    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual DataPiecePtr operator[] (
        Positions& positions
    ) = 0;

    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual DataPiecePtr operator[] (
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
 * @brief Null Data for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullData : public Data {
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

    virtual Data& setValues(
        Positions&,
        NumbersPtr
    ) override {
        return *this;
    }

    virtual Data& setValues(
        PositionsPtr,
        NumbersPtr
    ) override {
        return *this;
    }

    virtual DataPiecePtr operator[] (
        Positions&
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[] (
        PositionsPtr
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() {
        return Message("NullData");
    }
}; /* END class NullData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_HPP__ */
