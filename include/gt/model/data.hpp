#ifndef __GT_MODEL_DATA_HPP__
#define __GT_MODEL_DATA_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Custom interface for all Data containers for Games.
 *
 * @author Mateusz Kubuszok
 */
class Data : public virtual Root {
public:
    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positionInStorage  coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when storage position is invalid
     */
    virtual DataPiecePtr operator[](
        Index positionInStorage
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
     * @brief Returns values handler for mapped coordiantes.
     *
     * @param positionInStorage calculated position in an inner Map
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */    
    virtual DataPiecePtr getValues(
        Index positionInStorage
    ) = 0;

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
     * @brief Sets values for mapped coordiantes.
     *
     * @param positionInStorage calculated position in an inner Map
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setValues(
        Index      positionInStorage, 
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
     * @brief Returns Data's message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class Data */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Data for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullData : public Data {
public:    
    virtual DataPiecePtr getValues(
        Index positionInStorage
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr getValues(
        Positions& positions
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr getValues(
        PositionsPtr positions
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual Data& setValues(
        Index      positionInStorage, 
        NumbersPtr numbers
    ) {
        return *this;
    }

    virtual Data& setValues(
        Positions& positions,
        NumbersPtr numbers
    ) {
        return *this;
    }

    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) {
        return *this;
    }

    virtual DataPiecePtr operator[](
        Index positionInStorage
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[](
        Positions&
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[](
        PositionsPtr
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullData");
    }
}; /* END class Data */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Interface for accessing Data coordinates for better access to values.
 *
 * @author Mateusz Kubuszok
 */
class DataPiece : public virtual Root {
public:
    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    NumberPtr& operator[](
        Identifier& playerName
    );

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    NumberPtr& operator[](
        IdentifierPtr playerName
    );

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    virtual NumberPtr& getValue(
        Identifier& playerName
    ) = 0;

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    NumberPtr& getValue(
        IdentifierPtr playerName
    );

    /**
     * @brief Returns DataPiece's message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class DataPiece */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null DataPiece for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataPiece : public DataPiece {
    NumberPtr nullNumber;
public:
    NullDataPiece() :
        nullNumber(NullFactory::getInstance().createNumber())
        {}

    virtual NumberPtr& getValue(
        Identifier& playerName
    ) {
        return nullNumber;
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullDataPiece");
    }
}; /* END class NullDataPiece */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_HPP__ */
