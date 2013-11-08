#ifndef __GT_GTL_DETAILS_HPP__
#define __GT_GTL_DETAILS_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contains Coordinates as well as defined Players.
 *
 * <p>Contains information about Players and Coordinates that will be used to build data.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see GameDriver
 * @see Parser
 */
class Details : public virtual ValidableSymbol {
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
     * @brief Returns Coordinates with data.
     *
     * @return Coordinates wit data
     */
    virtual CoordinatesPtr getCoordinates();

    /**
     * @brief Returns Players definitions.
     *
     * @return Players definitions
     */
    virtual ObjectsPtr getPlayers();

    /**
     * @brief Returns Message about Game details.
     *
     * @return Game Details Message
     */
    virtual Message toString();
}; /* END class Details */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Details for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDetails : public Details {
public:
    NullDetails() :
        Details(
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createCoordinates()
        )
        {}

    virtual CoordinatesPtr getCoordinates() {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual ObjectsPtr getPlayers() {
        return NullFactory::getInstance().createObjects();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullDetails");
    }
}; /* END class NullDetails */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Details for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorDetails : public Details {
    /**
     * @brief Error message.
     */
    Message message;

public:
    ErrorDetails(
        Message errorMessage
    ) :
        Details(
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createCoordinates()
        ),
        message(errorMessage)
        {}

    virtual CoordinatesPtr getCoordinates() {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual ObjectsPtr getPlayers() {
        return NullFactory::getInstance().createObjects();
    }

    virtual bool isValid() const {
        return false;
    }

    virtual Message toString() {
        return message;
    }
}; /* END class ErrorDetails */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_DETAILS_HPP__ */
