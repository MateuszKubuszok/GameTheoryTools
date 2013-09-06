#ifndef __GT_GTL_DETAILS_HPP__
#define __GT_GTL_DETAILS_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

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
        const Objects     playersDetails,
        const Coordinates coordinatesDetails
    );

    /**
     * @brief Returns Context with both general declarations and local ones.
     *
     * @param  parentContext parental Context
     * @return               subcontext filled with Players
     */
    virtual ContextPtr createSubContext(
        const Context& parentContext
    );

    /**
     * @brief Returns Coordinates with data.
     *
     * @return Coordinates wit data
     */
    virtual Coordinates getCoordinates();

    /**
     * @brief Returns Players definitions.
     *
     * @return Players definitions
     */
    virtual Objects getPlayers();

    /**
     * @brief Returns Message about Game details.
     *
     * @return Game Details Message
     */
    virtual Message toString();
}; /* END class Details */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Definition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDetails : public virtual Details {
public:
    NullDetails() :
        Details(
            Objects(),
            Coordinates()
        )
        {}

    ContextPtr createSubContext(
        const Context& parentContext
    ) {
        return NullFactory::getInstance().createContext();
    }

    Coordinates getCoordinates() {
        return Coordinates();
    }

    Objects getPlayers() {
        return Objects();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullDetails");
    }
}; /* END class NullDetails */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_DETAILS_HPP__ */
