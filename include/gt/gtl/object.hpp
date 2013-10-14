#ifndef __GT_GTL_OBJECT_HPP__
#define __GT_GTL_OBJECT_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Root of all Objects used as a data in parsed by GTL.
 *
 * @author Mateusz Kubuszok
 */
class Object : public virtual Root, public virtual ValidableSymbol {
    /**
     * @brief Map containing ObjectProperties bound to their name.
     */
    ObjectPropertyMap registeredProperties;

    /**
     * @brief Object's type name.
     */
    IdentifierPtr typeName;

public:
    /**
     * @brief Default constructor.
     */
    Object();

    /**
     * @brief Default constructor.
     */
    explicit Object(Identifier type);

    /**
     * @brief Object's destructor.
     *
     * Removes the properties' register.
     */
    virtual ~Object();

    /**
     * @brief Whether Object responds to some property.
     *
     * @param  property property's name
     * @return          true if Object responds to such property 
     */
    virtual bool respondsTo(
        Identifier& propertyName
    );

    /**
     * @brief Finds Objects' property and returns it as a result.
     *
     * @param  context               context with values
     * @param  propertyName          property's name
     * @return                       Result for sought property
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    virtual ResultPtr findProperty(
        const Context& context,
        Identifier&    propertyName
    );

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
        Identifier&       propertyName,
        const Conditions& conditions
    );

    /**
     * @brief Returns list of available properties.
     *
     * @return properties list
     */
    IdentifiersPtr listProperties();

    /**
     * @brief Returns type of an Object.
     *
     * @return type name
     */
    IdentifierPtr type();

    /**
     * @brief Returns message about object.
     *
     * @return generic Message
     */
    virtual Message toString();

protected:
    /**
     * @brief Whether property is registered or not.
     *
     * @param propertyName name of a checked property
     * @return             true if property is registered
     */
    bool isPropertyRegistered(
        Identifier& propertyName
    );

    /**
     * @brief Obtains ObjectProperty by name under which it was registered.
     *
     * @param propertyName           name of a required property
     * @return                       required ObjectProperty
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    ObjectPropertyPtr getProperty(
        Identifier& propertyName
    );

    /**
     * @brief Registers property together with its name.
     *
     * @param propertyName property's name
     * @param property     property instance
     */
    void registerProperty(
        Identifier        propertyName,
        ObjectPropertyPtr property
    );
}; /* END class Object */

////////////////////////////////////////////////////////////////////////////////

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
    ) = 0;
}; /* END class ObjectProperty */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Object for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullObject : public Object {
public:
    virtual bool respondsTo(
        Identifier&
    ) {
        return false;
    }

    virtual ResultPtr findProperty(
        const Context&,
        Identifier&
    ) {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr findPropertyWithConditions(
        const Context&,
        Identifier&,
        const Conditions&
    ) {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullObject");
    }
}; /* END class NullObject */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Object for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorObject : public Object {
    Message message;
    
public:
    ErrorObject(
        Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual bool respondsTo(
        Identifier&
    ) {
        return false;
    }

    virtual ResultPtr findProperty(
        const Context&,
        Identifier&
    ) {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr findPropertyWithConditions(
        const Context&,
        Identifier&,
        const Conditions&
    ) {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isValid() {
        return false;
    }

    virtual Message toString() {
        return message;
    }
}; /* END class ErrorObject */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GTL_OBJECT_HPP__ */
