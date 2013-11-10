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
    /**
     * @brief Actual data.
     */
    StrategicDataPtr data;

public:
    /**
     * @brief Initiates accessor with a StrategicData.
     *
     * @param gameData StrategicData
     */
    explicit StrategicDataAccessor(
        const StrategicDataPtr gameData
    );

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual const PlayersPtr getPlayers() const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to PositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getValues(
        const Index positionInStorage
    ) const;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getValues(
        const PositionsPtr positions
    ) const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getValues(
        const Positions& positions
    ) const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to PositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const Index positionInStorage
    ) const;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const Positions& positions
    ) const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const PositionsPtr positions
    ) const override;

    /**
     * @brief Returns StrategicDataAccessor Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class StrategicDataAccessor*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_ACCESSOR_HPP__ */
