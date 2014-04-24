#ifndef GT_GTL_CONDITION_HPP_INCLUDED
#define GT_GTL_CONDITION_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/condition.hpp
 * @brief     Defines GT::GTL::Condition interface.
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
 * @class Condition
 * @brief Condition used for querying Objects with some requirements.
 *
 * Each kind of Condition should have its own representation recognized by Parser. It should be then
 * created by ConditionDriver (which in turn would use ConditionFactory). Conditions would be used e.g.
 * like that:
 *
 * @code
   FIND pure_equilibrium
   FOR  some_game
   WITH [condition1](, [condition2](, ...));
   @endcode
 *
 * @author Mateusz Kubuszok
 *
 * @see ConditionDriver
 * @see ConditionFactory
 * @see Query
 * @see Parser
 */
class Condition : public virtual ValidableSymbol {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Condition();

    /**
     * @brief Returns Condition applicable to Routine.
     *
     * @param context     Context
     * @return            Condition applicable to Routine
     * @throw InvalidType thrown when condition make use of not accepted Objects
     */
    virtual Routines::ConditionPtr getCondition(
        const Context& context
    ) const = 0;

    /**
     * @brief Returns Message about Condition.
     *
     * @return Condition's Message
     */
    virtual Message toString() const override = 0;

protected:
    /**
     * @brief Obtains Identifier from Object.
     *
     * @param context     Context
     * @param object      Object that should contain Identifier
     * @return            Identifier stored/rfered by that Object
     * @throw InvalidType thrown when condition make use of not accepted Objects
     */
    Identifier getIdentifier(
        const Context&   context,
        const ObjectPtr& object
    ) const;
}; /* END class Condition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullCondition
 * @brief Null Condition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCondition final : public Condition {
public:
    virtual Routines::ConditionPtr getCondition(
        const Context&
    ) const override {
        return Routines::NullFactory::getInstance().createCondition();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullCondition");
    }
}; /* END class NullCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ErrorCondition
 * @brief Error Condition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorCondition final : public Condition {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorCondition(
        const Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual Routines::ConditionPtr getCondition(
        const Context&
    ) const override {
        return Routines::NullFactory::getInstance().createCondition();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_CONDITION_HPP_INCLUDED */
