#ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__
#define __GT_MODEL_PLAIN_DATA_PIECE_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PlainDataPiece : public DataPiece {
    IdentifierMap playersMap;
    NumbersPtr    numbers;

public:
    PlainDataPiece(
        IdentifierMap players,
        NumbersPtr    params
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
