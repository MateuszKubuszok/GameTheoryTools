#ifndef __GT_MODEL_STRATEGIC_DATA_BUILDER_HPP__
#define __GT_MODEL_STRATEGIC_DATA_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating StrategicGame's Data.
 *
 * <p>Games in this form should have all coordinates filled with payoffs. Since
 * all Players and their strategies are known beforehand, positions can also
 * be hashed to Indexes with PositionsHelper.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see StrategicData
 */
class StrategicDataBuilder : public DataBuilder {
    typedef boost::container::map<Identifier, bool> KnownPositions;

    StrategicDataPtr data;

    PlayersPtr players;

    Positions      currentPositions;
    KnownPositions currentlyKnownPositions;

public:
    /**
     * @brief Defalt constructor.
     */
    StrategicDataBuilder();

    /**
     * @brief Returns set up Data.
     *
     * @return built Data
     */
    StrategicDataPtr build();

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    PlayersPtr getPlayers();

    /**
     * @brief Sets Players' definitions.
     *
     * @param newPlayers Players' definitions
     * @return           reference to itself for chanining
     */
    virtual DataBuilder& setPlayers(
        PlayersPtr newPlayers
    );

    /**
     * @brief Specifies next Positions.
     *
     * @param positions next Positions to specify
     * @return          reference to itself for chanining
     */
    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    );

    /**
     * @brief Sets payoffs values.
     *
     * @param params values of payoffs 
     * @return       reference to itself for chanining
     */
    virtual DataBuilder& setParams(
        NumbersPtr params
    );

    /**
     * @brief Returns copy of itsef with shared content and frozen values of already set Positions. 
     *
     * @return copy with frozem Positions and content common to parent
     */
    virtual DataBuilderPtr clone();

    /**
     * @brief StrategicDataBuilder Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class StrategicDataBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_BUILDER_HPP__ */
