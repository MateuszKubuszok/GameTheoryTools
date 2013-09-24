#ifndef __GT_MODEL_PLAIN_DATA_HPP__
#define __GT_MODEL_PLAIN_DATA_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PlainData : public Data {
    PositionsHelper positionsHelper;

    boost::container::vector<NumbersPtr> paramsStorage;
    boost::container::vector<bool>       paramsStorageAllocation;
    
public:
    PlainData(
        PlayersPtr playersDefinitions
    );

    virtual PlayersPtr getPlayers();

    virtual DataPiecePtr getValues(
        Index positionInStorage
    );

    virtual DataPiecePtr getValues(
        Positions& positions
    );

    virtual DataPiecePtr getValues(
        PositionsPtr positions
    );

    virtual Data& setValues(
        Index      positionInStorage,
        NumbersPtr numbers
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
        Index positionInStorage
    );

    virtual DataPiecePtr operator[](
        Positions& positions
    );

    virtual DataPiecePtr operator[](
        PositionsPtr positions
    );

    virtual Message toString();
}; /* END class PlainData */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_DATA_HPP__ */
