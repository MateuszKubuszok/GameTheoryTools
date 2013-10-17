#ifndef __GT_GTL_DEFINITION_HPP__
#define __GT_GTL_DEFINITION_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Definition used to define Context. 
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Param
 */
class Definition : public virtual ValidableSymbol {
    /**
     * @brief Name of the property
     */
    const IdentifierPtr name;

    /**
     * @brief Value of the property.
     */
    const ParamPtr value;

public:
    /**
     * @brief Constructor for name and value.
     *
     * @param definedName  name of the defined property
     * @param definedValue value of the defined property
     */
    Definition(
        IdentifierPtr definedName,
        ParamPtr      definedValue
    );

    /**
     * @brief Returns name of the property.
     *
     * @return value of the property
     */
    virtual IdentifierPtr getName();

    /**
     * @brief Returns value of the property.
     *
     * @return value of the property
     */
    virtual ParamPtr getValue();

    /**
     * @brief Returns Message about Definition.
     *
     * @return Definition's Message
     */
    virtual Message toString();
}; /* END class Definition */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Definition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDefinition : public Definition {
public:
    NullDefinition() :
        Definition(
            Model::NullFactory::getInstance().createIdentifier(),
            NullFactory::getInstance().createParam()
        )
        {}

    virtual IdentifierPtr getName() {
        return Model::NullFactory::getInstance().createIdentifier();
    }

    virtual ParamPtr getValue() {
        return NullFactory::getInstance().createParam();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullDefinition");
    }
}; /* END class NullDefinition */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Definition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorDefinition : public Definition {
    Message message;

public:
    ErrorDefinition(
        Message errorMessage
    ) :
        Definition(
            Model::NullFactory::getInstance().createIdentifier(),
            NullFactory::getInstance().createParam()
        ),
        message(errorMessage)
        {}

    virtual IdentifierPtr getName() {
        return Model::NullFactory::getInstance().createIdentifier();
    }

    virtual ParamPtr getValue() {
        return NullFactory::getInstance().createParam();
    }

    virtual bool isValid() const {
        return false;
    }

    virtual Message toString() {
        return message;
    }
}; /* END class ErrorDefinition */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_DEFINITION_HPP__ */
