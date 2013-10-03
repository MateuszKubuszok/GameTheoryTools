#ifndef __GT_MODEL_TREE_DATA_HPP__
#define __GT_MODEL_TREE_DATA_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contins data specific for Game in a tree form.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree.
 * Each level of that tree has assigned Player and for this level. As such
 * coordinates are mapping from turn into choosen strategy instead of
 * Player to strategy mapping.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see Data
 * @see DataPiece
 * @see TreeDataAccessor
 * @see TreeDataPiece
 * @see TreeDataBuilder
 */
class TreeData : public Data {
    PlayersPtr        players;
    TreeDataNodePtr   root;
    PlayersInTurnsPtr playersInTurns;
    
public:
    /**
     * @brief Initiates Data with Players' definitions.
     *
     * @param playersDefinitions Players' definitions
     */
    explicit TreeData(
        PlayersPtr playersDefinitions
    );

    /**
     * @brief Returns Players' definitions.
     * 
     * @return Players' definitions
     */
    virtual PlayersPtr getPlayers();

    /**
     * @brief Returns PlayersInTurns definitions.
     *
     * @return PlayersInTurns
     */
    virtual PlayersInTurnsPtr getPlayersInTurns();

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
     * @throw InvalidCoordinate thrown when Positions does not specify all depths
     *                          continously ("1", "2", ...) or some strategies do not
     *                          match assigned for each turn Players
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
     * @throw InvalidCoordinate thrown when Positions does not specify all depths
     *                          continously ("1", "2", ...) or some strategies do not
     *                          match assigned for each turn Players
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
     * @brief Returns TreeData Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class TreeData */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null TreeData for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullTreeData : public TreeData {
public:
    NullTreeData() :
        TreeData(NullFactory::getInstance().createPlayers())
        {}

    virtual PlayersPtr getPlayers() {
        return NullFactory::getInstance().createPlayers();
    }

    virtual PlayersInTurnsPtr getPlayersInTurns() {
        return PlayersInTurnsPtr(new PlayersInTurns());
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
        Positions& positions
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[](
        PositionsPtr positions
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullTreeData");
    }
}; /* END class NullTreeData */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_TREE_DATA_HPP__ */
