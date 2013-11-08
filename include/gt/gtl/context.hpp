#ifndef __GT_GTL_CONTEXT_HPP__
#define __GT_GTL_CONTEXT_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Context containing identifiers and values befind then.
 *
 * <p>Has the ability to dynamically inherit parent Context filling it with data specific to itself.</p>
 *
 * <p>Used by Drivers to store Params under some name. They can be later accessed by their names.</p>
 *
 * <p>Example of code recognized by Parsr that would use Context undernath:</p>
 *
 * <p><pre>
 * LET game1 BE [game definition];
 * FIND mixed_equilibrium FOR game1;
 * </pre></p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Definition
 * @see Param
 * @see ParamFactory
 */
class Context : public virtual Root {
    /**
     * @brief Known objects map.
     */
    typedef boost::container::map<Identifier, ParamPtr> KnownObjects;

    /**
     * @brief Possible parent Context.
     */
    ContextPtr parentContext;

    /**
     * @brief Registerd Objects.
     */
    KnownObjects knownObjects;

public:
    /**
     * @brief Default constructor.
     */
    Context();

    /**
     * @brief Constructor with parental context inheritance.
     *
     * @param parentContext parental Context
     */
    explicit Context(
        const ContextPtr parentContext
    );

    /**
     * @brief Default destructor.
     */
    virtual ~Context();

    /**
     * @brief Adds/overrides identifier with value.
     *
     * @param identifier identifer to register
     * @param param      new value to register
     * @return           reference to context for chaining
     */
    virtual Context& registerParam(
        IdentifierPtr identifier,
        ParamPtr      param
    );

    /**
     * @brief Adds/overrides identifier with value.
     *
     * @param definition definition of an Object with name
     * @return           reference to context for chaining
     */
    virtual Context& registerParam(
        DefinitionPtr definition
    );

    /**
     * @brief Returns true if Identifier has been registed.
     *
     * @return true if Identifier has been registerd
     */
    virtual bool hasRegistered(
        Identifier& identifier
    );

    /**
     * @brief Obtains value from context by identifer.
     *
     * @param identifier identifier to obtain
     * @return           value to retur
     */
    virtual NumberPtr getNumber(
        Identifier& identifier
    );

    /**
     * @brief Obtains value from context by identifer.
     *
     * @param identifier identifier to obtain
     * @return           value to retur
     */
    virtual ObjectPtr getObject(
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
    virtual ParamPtr getParam(
        Identifier& identifier
    );

    /**
     * @brief Returns Message about Context.
     *
     * @return Context's Message
     */
    virtual Message toString() override;
}; /* END class Context */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Context for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullContext : public Context {
public:
    virtual Context& registerParam(
        IdentifierPtr,
        ParamPtr
    ) override {
        return *this;
    }

    virtual Context& registerParam(
        DefinitionPtr
    ) override {
        return *this;
    }

    virtual NumberPtr getNumber(
        Identifier&
    ) override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual ObjectPtr getObject(
        Identifier&
    ) override {
        return NullFactory::getInstance().createObject();
    }

    virtual ParamPtr getParam(
        Identifier&
    ) override {
        return NullFactory::getInstance().createParam();
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullContext");
    }
}; /* END class NullContext */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CONTEXT_HPP__ */
