#ifndef __GT_MODEL_STRATEGIC_DATA_HPP__
#define __GT_MODEL_STRATEGIC_DATA_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class StrategicData : public Data {
    PositionsHelper positionsHelper;

    boost::container::vector<NumbersPtr> payoffStorage;
    boost::container::vector<bool>       payoffStorageAllocation;
    
public:
    StrategicData(
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
}; /* END class StrategicData */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_Strategic_DATA_HPP__ */
