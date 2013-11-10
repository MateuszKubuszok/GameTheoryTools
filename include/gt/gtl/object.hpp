#ifndef __GT_GTL_OBJECT_HPP__
#define __GT_GTL_OBJECT_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Root of all Objects used as a data in parsed by GTL.
 *
 * <p>Common ancestor of all types of data (besides Numbers) that can be used within language.</p>
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
     * <p>Removes the properties' register.</p>
     */
    virtual ~Object();

    /**
     * @brief Whether Object responds to some property.
     *
     * @param  property property's name
     * @return          true if Object responds to such property
     */
    virtual bool respondsTo(
        const Identifier& propertyName
    ) const;

    /**
     * @brief Finds Objects' property and returns it as a result.
     *
     * @param  context               context with values
     * @param  propertyName          property's name
     * @return                       Result for sought property
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    virtual ResultPtr findProperty(
        const Context&    context,
        const Identifier& propertyName
    ) const;

    /**
     * @brief Finds Objects' property for giver conditions and returns it as a result.
     *
     * @param context                context with values
     * @param conditions             conditions to consider
     * @return                       Result for sought property
     * @throws std::invalid_argument thrown when property is not available for an Object
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
    IdentifiersPtr listProperties() const;

    /**
     * @brief Returns type of an Object.
     *
     * @return type name
     */
    const IdentifierPtr type() const ;

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
    virtual operator const Game&() const;

    /**
     * @brief Explicit cast to Param type.
     *
     * @return Param
     */
    virtual operator const Param&() const;

    /**
     * @brief Explicit cast to Player type.
     *
     * @return Player
     */
    virtual operator const Player&() const;

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
     * @param propertyName           name of a required property
     * @return                       required ObjectProperty
     * @throws std::invalid_argument thrown when property is not available for an Object
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
 * @brief Root of all Object's properties that can be registered.
 *
 * @author Mateusz Kubuszok
 */
class ObjectProperty {
public:
    /**
     * @brief Finds results for given Conditions.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const = 0;
}; /* END class ObjectProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Object for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullObject : public Object {
public:
    virtual bool respondsTo(
        const Identifier&
    ) const override {
        return false;
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
 * @brief Error Object for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorObject : public Object {
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

#endif /* END #ifndef __GTL_OBJECT_HPP__ */
