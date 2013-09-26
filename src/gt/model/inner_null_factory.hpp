#ifndef __GT_MODEL_INNER_NULL_FACTORY_HPP__
#define __GT_MODEL_INNER_NULL_FACTORY_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for Model inner classes.
 *
 * @author Mateusz Kubuszok
 */
class InnerNullFactory {
    /**
     * @brief Contains pointer to a NullFactory instance.
     */
    static InnerNullFactory* volatile instance;

public:
    /**
     * @brief Returns the instance of a InnerNullFactory.
     *
     * @return InnerNullFactory instance
     */
    static InnerNullFactory& getInstance();

    StrategicDataPtr createStrategicData();

    TreeDataPtr createTreeData();

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    InnerNullFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    InnerNullFactory(
        const InnerNullFactory& innerNullFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~InnerNullFactory();
}; /* END class InnerNullFactory */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_INNER_NULL_FACTORY_HPP__ */
