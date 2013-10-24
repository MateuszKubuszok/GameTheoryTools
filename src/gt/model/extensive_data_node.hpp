#ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class ExtensiveDataNode : public virtual Root {
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

    NumbersPtr getValues(
        Positions& positions
    );

    ExtensiveDataNode& setValues(
    	Positions& positions,
    	NumbersPtr values
    );

    Message toString();

private:
	bool checkPositions(
		Positions& positions
	);
};

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__ */
