#ifndef __GT_MODEL_EXTENSIVE_DATA_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contins data specific for Game in a tree form.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree. Each level of that tree has assigned
 * Player and for this level. As such coordinates are mapping from turn into choosen strategy instead of
 * Player to strategy mapping.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see Data
 * @see DataPiece
 * @see ExtensiveDataAccessor
 * @see ExtensiveDataPiece
 * @see ExtensiveDataBuilder
 * @see ExtensiveDataNode
 */
class ExtensiveData : public Data {
    /**
     * @brief Players.
     */
    PlayersPtr           players;
    /**
     * @brief Root of Data tree.
     */
    ExtensiveDataNodePtr root;

public:
    /**
     * @brief Initiates Data with Players' definitions.
     *
     * @param playersDefinitions Players' definitions
     */
    explicit ExtensiveData(
        PlayersPtr playersDefinitions
    );

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual PlayersPtr getPlayers();

    /**
     * @brief Returns Player that plays for given position.
     *
     * @param positions Positions in payoff storage
     * @return          Player that plays given position
     */
    virtual PlayerPtr getPlayerInTurn(
        Positions& positions
    );

    /**
     * @brief Returns Player that plays for given position.
     *
     * @param positions Positions in payoff storage
     * @return          Player that plays given position
     */
    virtual PlayerPtr getPlayerInTurn(
        PositionsPtr positions
    );

    /**
     * @brief Sets Player that plays for given position.
     *
     * @param positions Positions for which player Player
     * @param player    Player that plays given position
     * @return          reference ot itdelf for chaining
     */
    virtual ExtensiveData& setPlayerInTurn(
        Positions& positions,
        PlayerPtr  player
    );

    /**
     * @brief Sets Player that plays for given position.
     *
     * @param positions Positions for which player Player
     * @param player    Player that plays given position
     * @return          reference ot itdelf for chaining
     */
    virtual ExtensiveData& setPlayerInTurn(
        PositionsPtr positions,
        PlayerPtr    player
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
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     * @throw InvalidCoordinate thrown when Positions does not specify all depths continously ("1", "2", ...)
     *                          or some strategies do not match assigned for each turn Players
     */
    virtual Data& setValues(
        Positions& positions,
        NumbersPtr numbers
    );

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     * @throw InvalidCoordinate thrown when Positions does not specify all depths continously ("1", "2", ...)
     *                          or some strategies do not match assigned for each turn Players
     */
    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
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
     * @brief Returns ExtensiveData Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class ExtensiveData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null ExtensiveData for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullExtensiveData : public ExtensiveData {
public:
    NullExtensiveData() :
        ExtensiveData(NullFactory::getInstance().createPlayers())
        {}

    virtual PlayersPtr getPlayers() {
        return NullFactory::getInstance().createPlayers();
    }

    virtual PlayerPtr getPlayerInTurn(
        Positions&
    ) {
        return NullFactory::getInstance().createPlayer();
    }

    virtual PlayerPtr getPlayerInTurn(
        PositionsPtr
    ) {
        return NullFactory::getInstance().createPlayer();
    }

    virtual ExtensiveData& setPlayerInTurn(
        Positions&,
        PlayerPtr
    ) {
        return *this;
    }

    virtual ExtensiveData& setPlayerInTurn(
        PositionsPtr,
        PlayerPtr
    ) {
        return *this;
    }

    virtual DataPiecePtr getValues(
        Positions&
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr getValues(
        PositionsPtr
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual Data& setValues(
        Positions&,
        NumbersPtr
    ) {
        return *this;
    }

    virtual Data& setValues(
        PositionsPtr,
        NumbersPtr
    ) {
        return *this;
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
        return Message("NullExtensiveData");
    }
}; /* END class NullExtensiveData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_HPP__ */
