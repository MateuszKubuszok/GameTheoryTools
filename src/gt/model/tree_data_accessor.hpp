#ifndef __GT_MODEL_TREE_DATA_ACCESSOR_HPP__
#define __GT_MODEL_TREE_DATA_ACCESSOR_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class TreeDataAccessor : public DataAccessor {
    TreeDataPtr data;

public:
    explicit TreeDataAccessor(
        TreeDataPtr gameData
    );

    virtual DataPiecePtr operator[](
        Positions& positions
    );

    virtual DataPiecePtr operator[](
        PositionsPtr positions
    );

    virtual PlayersPtr getPlayers();

    virtual DataPiecePtr getValues(
        PositionsPtr positions
    );

    virtual DataPiecePtr getValues(
        Positions& positions
    );

    virtual Message toString();
};

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_TREE_DATA_ACCESSOR_HPP__ */
