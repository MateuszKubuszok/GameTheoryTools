#ifndef GT_GTL_CONTEXT_HPP_INCLUDED
#define GT_GTL_CONTEXT_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/context.hpp
 * @brief     Defines GT::GTL::Context interface.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::container::map;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Context
 * @brief Context containing identifiers and values befind then.
 *
 * Has the ability to dynamically inherit parent Context filling it with data specific to itself.
 *
 * Used by Drivers to store Params under some name. They can be later accessed by their names.
 *
 * Example of code recognized by Parsr that would use Context undernath:
 *
 * @code
   LET game1 BE [game definition];
   FIND mixed_equilibrium FOR game1;
   @endcode
 *
 * @author Mateusz Kubuszok
 *
 * @see Definition
 * @see Param
 * @see ParamFactory
 */
class Context : public virtual Root {
    /**
     * @brief Possible parent Context.
     */
    ContextPtr parentContext;

    /**
     * @brief Registerd Objects.
     */
    map<Identifier, ParamPtr> knownObjects;

public:
    /**
     * @brief Known objects map.
     */
    typedef map<Identifier, ParamPtr> KnownObjects;

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
        const IdentifierPtr identifier,
        const ParamPtr      param
    );

    /**
     * @brief Adds/overrides identifier with value.
     *
     * @param definition definition of an Object with name
     * @return           reference to context for chaining
     */
    virtual Context& registerParam(
        const DefinitionPtr definition
    );

    /**
     * @brief Returns true if Identifier has been registed.
     *
     * @return true if Identifier has been registerd
     */
    virtual bool hasRegistered(
        const Identifier& identifier
    ) const;

    /**
     * @brief Obtains value from context by identifer.
     *
     * @param identifier identifier to obtain
     * @return           value to retur
     */
    virtual const NumberPtr getNumber(
        const Identifier& identifier
    ) const;

    /**
     * @brief Obtains value from context by identifer.
     *
     * @param identifier identifier to obtain
     * @return           value to retur
     */
    virtual const ObjectPtr getObject(
        const Identifier& identifier
    ) const;

    /**
     * @brief Obtains param from context by identifer.
     *
     * If Object is not a Param then exception will be thrown.
     *
     * @param identifier param to obtain
     * @return           value to retur
     */
    virtual const ParamPtr getParam(
        const Identifier& identifier
    ) const;

    /**
     * @brief Returns map of KnownObjects.
     *
     * @return KnownObjects map
     */
    virtual const KnownObjects getKnownObjects() const;

    /**
     * @brief Returns serialized Message for a Context.
     *
     * @return serialization result
     */
    virtual Message serialize() const;

    /**
     * @brief Returns Message about Context.
     *
     * @return Context's Message
     */
    virtual Message toString() const override;
}; /* END class Context */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullContext
 * @brief Null Context for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullContext final : public Context {
public:
    virtual Context& registerParam(
        const IdentifierPtr,
        const ParamPtr
    ) override {
        return *this;
    }

    virtual Context& registerParam(
        const DefinitionPtr
    ) override {
        return *this;
    }

    virtual const NumberPtr getNumber(
        const Identifier&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual const ObjectPtr getObject(
        const Identifier&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const ParamPtr getParam(
        const Identifier&
    ) const override {
        return NullFactory::getInstance().createParam();
    }

    virtual Message serialize() const override {
        return Message();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullContext");
    }
}; /* END class NullContext */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_CONTEXT_HPP_INCLUDED */
