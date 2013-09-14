#ifndef __GT_MODEL_DATA_BUILDER_HPP__
#define __GT_MODEL_DATA_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Helper used to create data for Games.
 *
 * @author Mateusz Kubuszok
 */
class DataBuilder : public virtual Root {
public:
    /**
     * @brief Sets Players defined for Game. 
     *
     * @param players Players
     * @return        reference to itself
     */
    virtual DataBuilder& setPlayers(
        PlayersPtr players
    ) = 0;

    /**
     * @brief Adds next positions to Data. 
     *
     * @param positions Positions
     * @return          reference to itself
     */
    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    ) = 0;

    /**
     * @brief Sets Params with values. 
     *
     * @param params Params
     * @return       reference to itself
     */
    virtual DataBuilder& setParams(
        NumbersPtr params
    ) = 0;

    /**
     * @brief Clones DataBuilder for recursive building.
     *
     * @return DataBuilder clone
     */
    virtual DataBuilderPtr clone() = 0;

    /**
     * @brief DataBuilder's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class DataBuilder */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null DataBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataBuilder : public DataBuilder {
public:
    virtual DataBuilder& setPlayers(
        PlayersPtr players
    ) {
        return *this;
    }

    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    ) {
        return *this;
    }

    virtual DataBuilder& setParams(
        NumbersPtr params
    ) {
        return *this;
    }

    virtual DataBuilderPtr clone() {
        return NullFactory::getInstance().createDataBuilder();
    }

    virtual Message toString() {
        return Message("NullDataBuilder");
    }
}; /* END class NullDataBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_BUILDER_HPP__ */