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
    virtual const NumberPtr& getValue(
        const Identifier& playerName
    ) const = 0;

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    const NumberPtr& getValue(
        const IdentifierPtr playerName
    ) const;

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    const NumberPtr& operator[](
        const Identifier& playerName
    ) const;

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    const NumberPtr& operator[](
        const IdentifierPtr playerName
    ) const;

    /**
     * @brief Returns DataPiece's message.
     *
     * @return message
     */
    virtual Message toString() const = 0;
}; /* END class DataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null DataPiece for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataPiece : public DataPiece {
    /**
     * @brief NullNumber to return.
     */
    const NumberPtr nullNumber;

public:
    NullDataPiece() :
        nullNumber(NullFactory::getInstance().createNumber())
        {}

    virtual const NumberPtr& getValue(
        const Identifier&
    ) const override {
        return nullNumber;
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullDataPiece");
    }
}; /* END class NullDataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_PIECE_HPP__ */
