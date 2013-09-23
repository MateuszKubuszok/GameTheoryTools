#ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__
#define __GT_MODEL_PLAIN_DATA_PIECE_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PlainDataPiece : public DataPiece {
    PositionsHelper positionsHelper;
    NumbersPtr      numbers;

public:
    PlainDataPiece(
        PlayersPtr players,
        NumbersPtr params
    );

    virtual NumberPtr& getValue(
        Identifier& playerName
    );

    virtual Message toString();
}; /* END class PlainDataPiece */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__ */
