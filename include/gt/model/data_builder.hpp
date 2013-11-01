#ifndef __GT_MODEL_DATA_BUILDER_HPP__
#define __GT_MODEL_DATA_BUILDER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Helper used to create data for Games.
 *
 * <p>Intended to be used recursively with clone method:</p>
 *
 * <p><pre>
 * DataBuilderPtr builder1 = dataBuilder->clone();
 *     builder1->addNextPositions(position11);
 *     builder->clone()->addNextPositions(positions21).setParams(param11_21); // payoff(p1=s1, p2=s1)
 *     builder->clone()->addNextPositions(positions22).setParams(param11_22); // payoff(p1=s1, p2=s2)
 * DataBuilderPtr builder2 = dataBuilder->clone();
 *     builder2->addNextPositions(position12);
 *     builder->clone()->addNextPositions(positions21).setParams(param12_21); // payoff(p1=s2, p2=s1)
 *     builder->clone()->addNextPositions(positions22).setParams(param12_22); // payoff(p1=s2, p2=s2)
 * </pre></p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Data
 * @see GameBuilder
 */
class DataBuilder : public virtual Root {
public:
    /**
     * @brief Sets Players defined for Game.
     *
     * @param players           Players
     * @return                  reference to itself
     * @throw IllegalInnerState thrown when Players are already set
     */
    virtual DataBuilder& setPlayers(
        PlayersPtr players
    ) = 0;

    /**
     * @brief Adds next positions to Data.
     *
     * @param positions         Positions
     * @return                  reference to itself
     * @throw IllegalInnerState thrown when some of positions are already set
     * @throw InvalidCoordinate thrown when some of values are not valid strategies names
     */
    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    ) = 0;

    /**
     * @brief Sets Params with values.
     *
     * @param params            Params
     * @return                  reference to itself
     * @throw IllegalInnerState thrown when attempting to set params when
     *                          not all coordinates are known
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null DataBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataBuilder : public DataBuilder {
public:
    virtual DataBuilder& setPlayers(
        PlayersPtr
    ) {
        return *this;
    }

    virtual DataBuilder& addNextPositions(
        PositionsPtr
    ) {
        return *this;
    }

    virtual DataBuilder& setParams(
        NumbersPtr
    ) {
        return *this;
    }

    virtual DataBuilderPtr clone() {
        return NullFactory::getInstance().createDataBuilder();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullDataBuilder");
    }
}; /* END class NullDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_BUILDER_HPP__ */
