#ifndef __GT_GTL_DETAILS_HPP__
#define __GT_GTL_DETAILS_HPP__

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Contains coordinates as well as defined players.
 *
 * @author Mateusz Kubuszok
 */
class Details {
public:
	/**
	 * @brief Constructor for players with data.
	 *
	 * @param playersDetails     declared players
	 * @param coordinatesDetails declared data
	 */
	 Details(
		const Objects&     playersDetails,
		const Coordinates& coordinatesDetails
	) :
		players(playersDetails),
		coordinates(coordinatesDetails);

	/**
	 * @brief Returns context with both general declarations and local ones.
	 *
	 * @param  parentContext parental context
	 * @return               subcontext filled with players
	 */
	Context createSubContext(
		const Context& parentContext
	);

	/**
	 * @brief Returns Coordinates with data.
	 *
	 * @return Coordinates wit data
	 */
	Coordinates getCoordinates();

	/**
	 * @brief Returns Players definitions.
	 *
	 * @return Players definitions
	 */
	Objects getPlayers();

private:
	/**
	 * @brief Players' collection.
	 */
	const Objects players;

	/**
	 * @brief Coordinates' collection.
	 */
	const Coordinates coordinates; 
} /* END class Details */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_DETAILS_HPP__ */
