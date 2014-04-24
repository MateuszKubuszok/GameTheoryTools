#ifndef GT_MODEL_RESULT_BUILDER_HPP_INCLUDED
#define GT_MODEL_RESULT_BUILDER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/result_builder.hpp
 * @brief     Defines GT::Model::ResultBuilder interface.
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
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ResultBuilder
 * @brief Builder used for creating Results displayed to user.
 *
 * @author Mateusz Kubuszok
 *
 * @see Result
 * @see ResultFactory
 */
class ResultBuilder : public virtual Root {
public:
    /**
     * @brief Sets headers used for displaying records.
     *
     * Size of headers must match size of each record.
     *
     * @param  properties headers' names that will be used in a Result
     * @return            reference to self for chaining
     *
     * @see #addRecord(const IdentifierPtr&, const MessagesPtr&)
     */
    virtual ResultBuilder& setHeaders(
        const IdentifiersPtr& properties
    ) = 0;

    /**
     * @brief Adds record to displayed Result.
     *
     * Results size must match headers size.
     *
     * @param object  name of added record
     * @param results properties that should be displayed
     * @return        reference to self for chaining
     *
     * @see #setHeaders(const IdentifiersPtr&)
     */
    virtual ResultBuilder& addRecord(
        const IdentifierPtr& object,
        const MessagesPtr&   results
    ) = 0;

    /**
     * @brief Adds single named subresult.
     *
     * @param name   name of subresult
     * @param result subresult
     * @result       reference for itself for chaining
     */
    virtual ResultBuilder& addResult(
        const IdentifierPtr& name,
        const MessagePtr&    result
    ) = 0;

    /**
     * @brief Build Result.
     *
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages for any Object
     *                           does not match number of properties
     */
    virtual ResultPtr build() const = 0;

    /**
     * @brief Build raw Result - one that can be inserted into other results.
     *
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages for any Object
     *                           does not match number of properties
     */
    virtual ResultPtr buildRaw() const = 0;
}; /* END class ResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullResultBuilder
 * @brief Null ResultBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullResultBuilder final : public ResultBuilder {
public:
    virtual ResultBuilder& setHeaders(
        const IdentifiersPtr&
    ) override {
        return *this;
    }

    virtual ResultBuilder& addRecord(
        const IdentifierPtr&,
        const MessagesPtr&
    ) override {
        return *this;
    }

    virtual ResultBuilder& addResult(
        const IdentifierPtr&,
        const MessagePtr&
    ) override {
        return *this;
    }

    virtual ResultPtr build() const override {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr buildRaw() const override {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullResultBuilder");
    }
}; /* END class NullResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef GT_MODEL_RESULT_BUILDER_HPP_INCLUDED */
