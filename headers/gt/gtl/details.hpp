#ifndef __GT_GTL_DETAILS_HPP__
#define __GT_GTL_DETAILS_HPP__

namespace GT {
namespace GTL {

/**
 * @brief Contains Coordinates as well as defined Players.
 *
 * @author Mateusz Kubuszok
 */
class Details : public virtual Root {
    /**
     * @brief Players' collection.
     */
    const ObjectsPtr players;

    /**
     * @brief Coordinates' collection.
     */
    const CoordinatesPtr coordinates; 

public:
    /**
     * @brief Constructor for Players with data.
     *
     * @param playersDetails     declared players
     * @param coordinatesDetails declared data
     */
     Details(
        const ObjectsPtr     playersDetails,
        const CoordinatesPtr coordinatesDetails
    );

    /**
     * @brief Returns Context with both general declarations and local ones.
     *
     * @param  parentContext parental Context
     * @return               subcontext filled with Players
     */
    Context createSubContext(
        const Context& parentContext
    );

    /**
     * @brief Returns Coordinates with data.
     *
     * @return Coordinates wit data
     */
    CoordinatesPtr getCoordinates();

    /**
     * @brief Returns Players definitions.
     *
     * @return Players definitions
     */
    ObjectsPtr getPlayers();

    /**
     * @brief Returns Message about Game details.
     *
     * @return Game Details Message
     */
    virtual Message toString();
}; /* END class Details */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_DETAILS_HPP__ */
