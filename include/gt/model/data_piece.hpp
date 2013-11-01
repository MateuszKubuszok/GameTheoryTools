#ifndef __GT_MODEL_DATA_PIECE_HPP__
#define __GT_MODEL_DATA_PIECE_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        Identifier&
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_PIECE_HPP__ */
