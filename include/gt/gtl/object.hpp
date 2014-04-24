#ifndef GT_GTL_OBJECT_HPP_INCLUDED
#define GT_GTL_OBJECT_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/object.hpp
 * @brief     Defines GT::GTL::Object class.
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

/**
 * @class Object
 * @brief Root of all Objects used as a data in parsed by GTL.
 *
 * Common ancestor of all types of data (besides Numbers) that can be used within language.
 *
 * @author Mateusz Kubuszok
 *
 * @see Param
 * @see Context
 * @see Parser
 */
class Object : public virtual ValidableSymbol {
    /**
     * @brief Returned when Object cannot be casted to Game.
     */
    static const GamePtr noGame;

    /**
     * @brief Returned when Object cannot be casted to Param.
     */
    static const ParamPtr noParam;

    /**
     * @brief Returned when Object cannot be casted to Player.
     */
    static const PlayerPtr noPlayer;

    /**
     * @brief Map containing ObjectProperties bound to their name.
     */
    ObjectPropertyMap registeredProperties;

    /**
     * @brief Object's type name.
     */
    const IdentifierPtr typeName;

public:
    /**
     * @brief Default constructor.
     */
    Object();

    /**
     * @brief Constructor initiated with Object's type.
     *
     * @param type Object's type
     */
    explicit Object(
        const Identifier type
    );

    /**
     * @brief Object's destructor.
     *
     * Removes the properties' register.
     */
    virtual ~Object();

    /**
     * @brief Whether Object responds to some property.
     *
     * @param  propertyName property's name
     * @return              true if Object responds to such property
     */
    virtual bool respondsTo(
        const Identifier& propertyName
    ) const;

    /**
     * @brief Returns property's description.
     *
     * @param  propertyName   property's name
     * @return                property's description
     * @throw InvalidProperty thrown when property is not available for an Object
     */
    virtual ResultPtr describeProperty(
        const Identifier& propertyName
    ) const;

    /**
     * @brief Finds Objects' property and returns it as a Result.
     *
     * @param  context          Context with values
     * @param  propertyName     property's name
     * @return                  Result for sought property
     * @throw CyclicIdentifiers thrown when there is Param with cyclic references
     * @throw InvalidProperty   thrown when property is not available for an Object
     */
    virtual ResultPtr findProperty(
        const Context&    context,
        const Identifier& propertyName
    ) const;

    /**
     * @brief Finds Objects' property for giver Conditions and returns it as a Result.
     *
     * @param context           Context with values
     * @param propertyName      property's name
     * @param conditions        Conditions to consider
     * @return                  Result for sought property
     * @throw CyclicIdentifiers thrown when there is Param with cyclic references
     * @throw InvalidProperty   thrown when property is not available for an Object
     */
    virtual ResultPtr findPropertyWithConditions(
        const Context&    context,
        const Identifier& propertyName,
        const Conditions& conditions
    ) const;

    /**
     * @brief Returns list of available properties.
     *
     * @return properties list
     */
    virtual IdentifiersPtr listProperties() const;

    /**
     * @brief Returns type of an Object.
     *
     * @return type name
     */
    virtual const IdentifierPtr type() const;

    /**
     * @brief Returns message about object.
     *
     * @return generic Message
     */
    virtual Message toString() const override;

    /**
     * @brief Explicit cast to Game type.
     *
     * @return Game
     */
    virtual const Game& toGame() const;

    /**
     * @brief Explicit cast to Param type.
     *
     * @return Param
     */
    virtual const Param& toParam() const;

    /**
     * @brief Explicit cast to Player type.
     *
     * @return Player
     */
    virtual const Player& toPlayer() const;

protected:
    /**
     * @brief Whether property is registered or not.
     *
     * @param propertyName name of a checked property
     * @return             true if property is registered
     */
    bool isPropertyRegistered(
        const Identifier& propertyName
    ) const;

    /**
     * @brief Obtains ObjectProperty by name under which it was registered.
     *
     * @param propertyName     name of a required property
     * @return                 required ObjectProperty
     * @throws InvalidProperty thrown when property is not available for an Object
     */
    const ObjectPropertyPtr getProperty(
        const Identifier& propertyName
    ) const;

    /**
     * @brief Registers property together with its name.
     *
     * @param propertyName property's name
     * @param property     property instance
     */
    void registerProperty(
        const Identifier        propertyName,
        const ObjectPropertyPtr property
    );
}; /* END class Object */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullObject
 * @brief Null Object for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullObject final : public Object {
public:
    virtual bool respondsTo(
        const Identifier&
    ) const override {
        return false;
    }

    virtual ResultPtr describeProperty(
        const Identifier&
    ) const override {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr findProperty(
        const Context&,
        const Identifier&
    ) const override {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr findPropertyWithConditions(
        const Context&,
        const Identifier&,
        const Conditions&
    ) const override {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullObject");
    }
}; /* END class NullObject */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ErrorObject
 * @brief Error Object for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorObject final : public Object {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorObject(
        const Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual bool respondsTo(
        const Identifier&
    ) const override {
        return false;
    }

    virtual ResultPtr describeProperty(
        const Identifier&
    ) const override {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr findProperty(
        const Context&,
        const Identifier&
    ) const override {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr findPropertyWithConditions(
        const Context&,
        const Identifier&,
        const Conditions&
    ) const override {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorObject */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_OBJECT_HPP_INCLUDED */
