#ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ExtensiveDataNode : public virtual Root {
    PlayerPtr             player;
    NumbersPtr            payoff;
    ExtensiveDataNodesPtr nodes;
    unsigned int          depthValue;
    Identifier            depthName;

public:
    ExtensiveDataNode();

    explicit ExtensiveDataNode(
        unsigned int depth
    );

    ExtensiveDataNode(
        NumbersPtr values
    );

    PlayerPtr getPlayer();

    PlayerPtr getPlayer(
        Positions& positions
    );

    ExtensiveDataNode& setPlayer(
        PlayerPtr player
    );

    ExtensiveDataNode& setPlayer(
        Positions& positions,
        PlayerPtr  player
    );

    NumbersPtr getValues(
        Positions& positions
    );

    ExtensiveDataNode& setValues(
        Positions& positions,
        NumbersPtr values
    );

    Message toString();

private:
    bool isPositionOfCurrentNodePlayer(
        Positions& positions
    );

    bool checkPositions(
        Positions& positions
    );

    bool checkPlayerPositions(
        Positions& positions
    );
}; /* END class ExtensiveDataNode */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__ */
