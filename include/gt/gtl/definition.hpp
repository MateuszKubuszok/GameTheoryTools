#ifndef __GT_GTL_DEFINITION_HPP__
#define __GT_GTL_DEFINITION_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Definition used to define Context.
 *
 * <p>Contains pair Identifier-Param which will be insterted into current Context in the next step.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see StatementDriver
 * @see Parser
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
        const IdentifierPtr definedName,
        const ParamPtr      definedValue
    );

    /**
     * @brief Returns name of the property.
     *
     * @return value of the property
     */
    virtual const IdentifierPtr getName() const;

    /**
     * @brief Returns value of the property.
     *
     * @return value of the property
     */
    virtual const ParamPtr getValue() const;

    /**
     * @brief Returns Message about Definition.
     *
     * @return Definition's Message
     */
    virtual Message toString() const override;
}; /* END class Definition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Definition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDefinition final : public Definition {
public:
    NullDefinition() :
        Definition(
            Model::NullFactory::getInstance().createIdentifier(),
            NullFactory::getInstance().createParam()
        )
        {}

    virtual const IdentifierPtr getName() const override {
        return Model::NullFactory::getInstance().createIdentifier();
    }

    virtual const ParamPtr getValue() const override {
        return NullFactory::getInstance().createParam();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullDefinition");
    }
}; /* END class NullDefinition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Definition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorDefinition final : public Definition {
    /**
     * @brief Error message.
     */
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

    virtual const IdentifierPtr getName() const override {
        return Model::NullFactory::getInstance().createIdentifier();
    }

    virtual const ParamPtr getValue() const override {
        return NullFactory::getInstance().createParam();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorDefinition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_DEFINITION_HPP__ */
