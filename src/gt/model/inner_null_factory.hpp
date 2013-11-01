#ifndef __GT_MODEL_INNER_NULL_FACTORY_HPP__
#define __GT_MODEL_INNER_NULL_FACTORY_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for Model inner classes.
 *
 * @author Mateusz Kubuszok
 *
 * @see NullFactory
 */
class InnerNullFactory {
    SINGLETON_DECLARATION(InnerNullFactory)

public:
    /**
     * @brief Returns the instance of a InnerNullFactory.
     *
     * @return InnerNullFactory instance
     */
    static InnerNullFactory& getInstance();

    /**
     * @brief Creates null StrategicData.
     *
     * @result null StrategicData
     */
    StrategicDataPtr createStrategicData();

    /**
     * @brief Creates null ExtensiveData.
     *
     * @result null ExtensiveData
     */
    ExtensiveDataPtr createExtensiveData();

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_INNER_NULL_FACTORY_HPP__ */
