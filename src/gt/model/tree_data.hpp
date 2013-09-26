#ifndef __GT_MODEL_TREE_DATA_HPP__
#define __GT_MODEL_TREE_DATA_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class TreeData : public Data {
    PlayersPtr        players;
    TreeDataNodePtr   root;
    PlayersInTurnsPtr playersInTurns;
    
public:
    TreeData(
        PlayersPtr playersDefinitions
    );

    virtual PlayersPtr getPlayers();

    virtual PlayersInTurnsPtr getPlayersInTurns();

    virtual DataPiecePtr getValues(
        Positions& positions
    );

    virtual DataPiecePtr getValues(
        PositionsPtr positions
    );

    virtual Data& setValues(
        Positions& positions,
        NumbersPtr numbers
    );

    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    );

    virtual DataPiecePtr operator[](
        Positions& positions
    );

    virtual DataPiecePtr operator[](
        PositionsPtr positions
    );

    virtual Message toString();
}; /* END class TreeData */

////////////////////////////////////////////////////////////////////////////////

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
