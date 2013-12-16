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
    virtual const CoordinatesPtr getCoordinates() const;

    /**
     * @brief Returns Players definitions.
     *
     * @return Players definitions
     */
    virtual const ObjectsPtr getPlayers() const;

    /**
     * @brief Returns Message about Game details.
     *
     * @return Game Details Message
     */
    virtual Message toString() const override;
}; /* END class Details */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Details for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDetails final : public Details {
public:
    NullDetails() :
        Details(
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createCoordinates()
        )
        {}

    virtual const CoordinatesPtr getCoordinates() const override {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual const ObjectsPtr getPlayers() const override {
        return NullFactory::getInstance().createObjects();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullDetails");
    }
}; /* END class NullDetails */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Details for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorDetails final : public Details {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorDetails(
        const Message errorMessage
    ) :
        Details(
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createCoordinates()
        ),
        message(errorMessage)
        {}

    virtual const CoordinatesPtr getCoordinates() const override {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual const ObjectsPtr getPlayers() const override {
        return NullFactory::getInstance().createObjects();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorDetails */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_DETAILS_HPP__ */
