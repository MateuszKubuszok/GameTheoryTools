#ifndef __GT_MODEL_MIXED_DATA_ACCESSOR_HPP__
#define __GT_MODEL_MIXED_DATA_ACCESSOR_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class MixedDataAccessor : public DataAccessor {
    DataPtr         pureData;
    DataPtr         expectedData;
    PositionsHelper positionsHelper;

public:
    MixedDataAccessor(
        DataPtr data
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

private:
    NumbersPtr calculateExpectedValues(
        Positions& positions
    );
};

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_MIXED_DATA_ACCESSOR_HPP__ */
