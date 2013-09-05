#ifndef __GT_GTL_CONTEXT_HPP__
#define __GT_GTL_CONTEXT_HPP__

namespace GT {
namespace GTL {

/**
 * @brief Context containing identifiers and values befind then.
 *
 * Has the ability to dynamically inherit parent context filling it with data specific to itself.   
 *
 * @author Mateusz Kubuszok
 */
class Context : public virtual Root {
    /**
     * @brief Possible parent Context.
     */
    Context* parentContext;

    /**
     * @brief Registerd Objects.
     */
    boost::container::map<Identifier, Object> knownObjects;

public:
    /**
     * @brief Default constructor.
     */
    Context();

    /**
     * @brief Constructor with parental context inheritance. 
     */
    Context(
        const Context& parentContext
    );

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
        IdentifierPtr identifier,
        ObjectPtr     object
    );

    /**
     * @brief Adds/overrides identifier with value.
     *
     * @param definition definition of an Object with name
     * @return           reference to context for chaining
     */
    Context& registerObject(
        Definition& definition
    );

    /**
     * @brief Obtains value from context by identifer.
     *
     * @param identifier identifier to obtain
     * @return           value to retur
     */
    ObjectPtr getObject(
        Identifier& identifier
    );

    /**
     * @brief Obtains param from context by identifer.
     *
     * If Object is not a Param then exception will be thrown.
     *
     * @param identifier param to obtain
     * @return           value to retur
     */
    ParamPtr getParam(
        Identifier& identifier
    );

    /**
     * @brief Returns Message about Context.
     *
     * @return Context's Message
     */
    virtual Message toString();
}; /* END class Context */

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CONTEXT_HPP__ */
