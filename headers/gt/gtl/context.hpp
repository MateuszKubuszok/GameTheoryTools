#ifndef __GT_GTL_CONTEXT_HPP__
#define __GT_GTL_CONTEXT_HPP__ 1

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Context containing identifiers and values befind then.
 *
 * Has the ability to dynamically inherit parent context filling it with data specific to itself.   
 *
 * @author Mateusz Kubuszok
 */
class Context {
public:
    /**
     * @brief Default constructor.
     */
    Context() :
        knownObjects();

    /**
     * @brief Constructor with parental context inheritance. 
     */
    Context(
        Context& parentContext
    ) :
        knownObjects();

    /**
     * @brief Default destructor.
     */
    ~Context();

    /**
     * @brief Adds/overrides identifier with value.
     *
     * @param identifier identifer to register
     * @param object     new value to register
     * @return           reference to context for chaining
     */
    Context& registerObject(
        Identifier identifier,
        Object     object
    );

    /**
     * @brief Obtains value from context by identifer.
     *
     * @param identifier identifier to obtain
     * @return           value to retur
     */
    Object& getObject(
        Identifier& identifier
    );

    /**
     * @brief Obtains param from context by identifer.
     *
     * If Object is not a Param then exception will be thrown.
     *
     * @param param param to obtain
     * @return      value to retur
     */
    Param& getParam(
        Param& param
    );
    
private:
    Context* parentContext = 0;

    boost::container::map<Identifier, Object> knownObjects;
} /* END class Context */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_CONTEXT_HPP__ */
