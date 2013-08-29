#ifndef __GT_GTL_PARAM_FACTORY_HPP__
#define __GT_GTL_PARAM_FACTORY_HPP__ 1

#include "gt/gtl/param_factory.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Used for creation of params that may differs in behaviour.
 *
 * @author Mateusz Kubuszok
 */
class ParamFactory {
public:
    /**
     * @brief Returns the instance of a ParamFactory.
     *
     * @return ParamFactory instance
     */
    static ParamFactory& getInstance();

    /**
     * @brief Creates Param by identifier attatched to it.
     *
     * @param identifier identifier of a Param
     * @return           Param instance
     */
    Param createParam(
        const Identifier& identifier
    );

    /**
     * @brief Creates Param by value contained by it.
     *
     * @param number value of a Param
     * @return       Param instance
     */
    Param createParam(
        const Number& number
    );
private:
    /**
     * @brief Contains pointer to a ParamFactory instance.
     */
    static ParamFactory volatile *instance = 0;

    /**
     * @biref Private constructor.
     */
    ParamFactory();

    /**
     * @brief Private copy constructor.
     */
    ParamFactory(
        const ParamFactory &paramFactory
    );

    /**
     * @brief Private destructor.
     */
    ~ParamFactory();
} /* END class ParamFactory */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_PARAM_FACTORY_HPP__ */
