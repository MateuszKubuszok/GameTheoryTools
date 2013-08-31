#ifndef __GT_GTL_QUERY_HPP__
#define __GT_GTL_QUERY_HPP__

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Defines Game.
 *
 * @author Mateusz Kubuszok
 */
class Query {
public:
	/**
	 * @brief Execute query in a defined context.
	 *
	 * @param context Context with definitions
	 */
	virtual Result execute(
		Context& context
	);
} /* END class Game */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_QUERY_HPP__ */
