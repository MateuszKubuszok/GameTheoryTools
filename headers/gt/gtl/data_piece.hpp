#ifndef __GT_GTL_DATA_PIECE_HPP__
#define __GT_GTL_DATA_PIECE_HPP__ 1

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {
    
class DataPiece {
public:
    DataPiece(
    	Identifier& playerName,
    	Param&      param
    ) :
    	player(playerName),
    	dataPiecesMap(),
    	param(param);

    DataPiece(
    	Identifier& playerName
    	DataPieces& dataPieces
    ) :
    	player(playerName),
    	dataPiecesMap(dataPieces),
    	param();

    DataPiece& getDataPiece(
    	Context&    context,
    	Identifier& strategy
    );

    Number& getValue(Context& context);

private:
	Identifier player;

	DataPieces dataPieceMap;

	Param param;
} /* END class DataPiece */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_DATA_PIECE_HPP__ */
