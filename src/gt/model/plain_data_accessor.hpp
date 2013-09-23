#ifndef __GT_MODEL_PLAIN_DATA_ACCESSOR_HPP__
#define __GT_MODEL_PLAIN_DATA_ACCESSOR_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PlainDataAccessor : public DataAccessor {
    DataPtr data;

public:
    PlainDataAccessor(
        DataPtr gameData
    );

    virtual DataPiecePtr operator[](
        Index positionInStorage
    );

    virtual DataPiecePtr operator[](
        Positions& positions
    );

    virtual DataPiecePtr operator[](
        PositionsPtr positions
    );

    virtual PlayersPtr getPlayers();

    virtual DataPiecePtr getValues(
        Index positionInStorage
    );

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

#endif /* #ifndef __GT_MODEL_PLAIN_DATA_ACCESSOR_HPP__ */
