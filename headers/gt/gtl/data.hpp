#ifndef __GT_GTL_DATA_HPP__
#define __GT_GTL_DATA_HPP__

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Contains coordinates.
 *
 * @author Mateusz Kubuszok
 */
class Data {
public:
    Data(
    	const Coordinates& data
    ) :
    	coordinates(data);


    Coordinates getData();
private:
	Coordinates coordinates;
) /* END class Data */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_DATA_HPP__ */
