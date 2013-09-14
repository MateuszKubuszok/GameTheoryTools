#ifndef __GT_MODEL_DATA_HPP__
#define __GT_MODEL_DATA_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Custom interface for all Data containers for Games.
 *
 * @author Mateusz Kubuszok
 */
class Data : public virtual Root {
public:
    /**
     * @brief Returns value for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @param playerName        name of Player which payoff shall be obtained
     * @return                  value of payoff
     * @throw InvalidCoordinate thrown when coordinates or player's name
     *                          are invalid
     */
    virtual NumberPtr getValue(
        PositionsPtr  positions, 
        IdentifierPtr playerName
    ) = 0;

    /**
     * @brief Returns values for mapped coordiantes.
     *
     * @param positionInStorage calculated position in an inner Map
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */    
    virtual NumbersPtr getValues(
        int positionInStorage
    ) = 0;

    /**
     * @brief Returns values for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when coordinates are invalid
     */
    virtual NumbersPtr getValues(
        PositionsPtr positions
    ) = 0;

    /**
     * @brief Sets values for mapped coordiantes.
     *
     * @param positionInStorage calculated position in an inner Map
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setValues(
        int        positionInStorage, 
        NumbersPtr numbers
    ) = 0;

    /**
     * @brief Sets values for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) = 0;

    /**
     * @brief Returns Data's message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class Data */

////////////////////////////////////////////////////////////////////////////////

class NullData : public Data {
public:
    virtual NumberPtr getValue(
        PositionsPtr  positions, 
        IdentifierPtr playerName
    ) {
        return NullFactory::getInstance().createNumber();
    }
    
    virtual NumbersPtr getValues(
        int positionInStorage
    ) {
        return NullFactory::getInstance().createNumbers();
    }

    virtual NumbersPtr getValues(
        PositionsPtr positions
    ) {
        return NullFactory::getInstance().createNumbers();
    }

    virtual Data& setValues(
        int        positionInStorage, 
        NumbersPtr numbers
    ) {
        return *this;
    }

    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) {
        return *this;
    }

    virtual Message toString() {
        return Message("NullData");
    }
}; /* END class Data */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_HPP__ */
