#ifndef __GT_MODEL_EXTENSIVE_DATA_ACCESSOR_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_ACCESSOR_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Allows to access data specific for Game in a tree form.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree. Each node of that tree has assigned
 * Player. As such each SubCoordinates is mapped to strategy of the same Player.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see Data
 * @see DataPiece
 * @see ExtensiveData
 * @see ExtensiveDataPiece
 * @see ExtensiveDataBuilder
 */
class ExtensiveDataAccessor final : public DataAccessor {
    /**
     * @brief Actual data.
     */
    const ExtensiveDataPtr data;

public:
    /**
     * @brief Initiates accessor with a ExtensiveData.
     *
     * @param gameData ExtensiveData
     */
    explicit ExtensiveDataAccessor(
        const ExtensiveDataPtr gameData
    );

    /**
     * @brief Returns root of ExtensiveData tree.
     *
     * @return root
     */
    virtual const ExtensiveDataNodePtr getRoot() const;

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual const PlayersPtr getPlayers() const override;

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
     * @brief Returns ExtensiveDataAccessor Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ExtensiveDataAccessor */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_ACCESSOR_HPP__ */
