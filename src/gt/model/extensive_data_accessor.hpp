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
class ExtensiveDataAccessor : public DataAccessor {
    /**
     * @brief Actual data.
     */
    ExtensiveDataPtr data;

public:
    /**
     * @brief Initiates accessor with a ExtensiveData.
     *
     * @param gameData ExtensiveData
     */
    explicit ExtensiveDataAccessor(
        ExtensiveDataPtr gameData
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
     * @brief Returns ExtensiveDataAccessor Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class ExtensiveDataAccessor */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_ACCESSOR_HPP__ */
