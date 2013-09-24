#ifndef __GT_MODEL_STRATEGIC_DATA_PIECE_HPP__
#define __GT_MODEL_Strategic_DATA_PIECE_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class StrategicDataPiece : public DataPiece {
    PositionsHelper positionsHelper;
    NumbersPtr      numbers;

public:
    StrategicDataPiece(
        PlayersPtr players,
        NumbersPtr params
    );

    virtual NumberPtr& getValue(
        Identifier& playerName
    );

    virtual Message toString();
}; /* END class StrategicDataPiece */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_PIECE_HPP__ */
