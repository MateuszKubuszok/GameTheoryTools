#ifndef __GT_GTL_DEFINITION_HPP__
#define __GT_GTL_DEFINITION_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/definition.hpp
 * @brief     Defines GT::GTL::Definition class.
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
 * @class Definition
 * @brief Definition used to define Context.
 *
 * Contains pair Identifier-Param which will be insterted into current Context in the next step.
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
 * @class NullDefinition
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
 * @class ErrorDefinition
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
