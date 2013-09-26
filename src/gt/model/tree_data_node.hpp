#ifndef __GT_MODEL_TREE_DATA_NODE_HPP__
#define __GT_MODEL_TREE_DATA_NODE_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class TreeDataNode : public virtual Root {
    NumbersPtr       payoff;
    TreeDataNodesPtr nodes;
    unsigned int     depthValue;
    Identifier       depthName;

public:
	TreeDataNode();

    explicit TreeDataNode(
        unsigned int depth
    );

    TreeDataNode(
        NumbersPtr values
    );

    NumbersPtr getValues(
        Positions& positions
    );

    TreeDataNode& setValues(
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

#endif /* #ifndef __GT_MODEL_TREE_DATA_NODE_HPP__ */
