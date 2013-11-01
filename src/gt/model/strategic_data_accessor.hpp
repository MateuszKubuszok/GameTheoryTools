#ifndef __GT_MODEL_STRATEGIC_DATA_ACCESSOR_HPP__
#define __GT_MODEL_STRATEGIC_DATA_ACCESSOR_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Allows to access data specific for Game in a strategic form.
 *
 * <p>Games in this form should have all coordinates filled with payoffs. Since all Players and their
 * strategies are known beforehand, positions can also be hashed to Indexes with PositionsHelper.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see Data
 * @see DataPiece
 * @see StrategicData
 * @see StrategicDataPiece
 * @see StrategicDataBuilder
 * @see PositionsHelper
 */
class StrategicDataAccessor : public DataAccessor {
    StrategicDataPtr data;

public:
    /**
     * @brief Initiates accessor with a StrategicData.
     *
     * @param gameData StrategicData
     */
    explicit StrategicDataAccessor(
        StrategicDataPtr gameData
    );

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual PlayersPtr getPlayers();

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to PositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr getValues(
        Index positionInStorage
    );

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr getValues(
        PositionsPtr positions
    );

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr getValues(
        Positions& positions
    );

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to PositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr operator[](
        Index positionInStorage
    );

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr operator[](
        Positions& positions
    );

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr operator[](
        PositionsPtr positions
    );

    /**
     * @brief Returns StrategicDataAccessor Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class StrategicDataAccessor*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_ACCESSOR_HPP__ */
