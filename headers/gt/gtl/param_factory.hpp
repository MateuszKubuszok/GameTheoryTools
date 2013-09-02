#ifndef __GT_GTL_PARAM_FACTORY_HPP__
#define __GT_GTL_PARAM_FACTORY_HPP__

#include "gt/gtl/param_factory.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Used for creation of params that may differs in behaviour.
 *
 * @author Mateusz Kubuszok
 */
class ParamFactory {
    /**
     * @brief Contains pointer to a ParamFactory instance.
     */
    static ParamFactory volatile *instance = 0;

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
    ParamPtr createParam(
        const IdentifierPtr identifier
    );

    /**
     * @brief Creates Param by value contained by it.
     *
     * @param number value of a Param
     * @return       Param instance
     */
    ParamPtr createParam(
        const NumberPtr number
    );
private:
    /**
     * @biref Private constructor.
     */
    ParamFactory();

    /**
     * @brief Private copy constructor.
     */
    ParamFactory(
        const ParamFactory& paramFactory
    );

    /**
     * @brief Private destructor.
     */
    ~ParamFactory();
}; /* END class ParamFactory */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PARAM_FACTORY_HPP__ */
