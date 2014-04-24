#ifndef GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP_INCLUDED
#define GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/abstract_result_builder.hpp
 * @brief     Defines GT::Model::AbstractResultBuilder abstract class.
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
 * @class AbstractResultBuilder
 * @brief Common base class of all actual implemetations used in Model.
 *
 * Implements ResultBuilder interface.
 *
 * @author Mateusz Kubuszok
 *
 * @see ResultBuilder
 */
class AbstractResultBuilder : public ResultBuilder {
public:
    /**
     * @brief Constructor initiating class with indentation.
     *
     * @param indentation sequence used for indentation
     */
    explicit AbstractResultBuilder(
        const Message indentation
    );

    /**
     * @brief Sets headers used for displaying records.
     *
     * Size of headers must match size of each record.
     *
     * @param   propertiesNames headers' names that will be used in a Result
     * @return                  refernce to self for chaining
     *
     * @see #addRecord(const IdentifierPtr&, const MessagesPtr&)
     */
    virtual ResultBuilder& setHeaders(
        const IdentifiersPtr& propertiesNames
    ) override;

    /**
     * @brief Adds record to displayed Result.
     *
     * Results size must match headers size.
     *
     * @param name             name of added record
     * @param propertiesValues properties that should be displayed
     * @return                 refernce to self for chaining
     *
     * @see #setHeaders(const IdentifiersPtr&)
     */
    virtual ResultBuilder& addRecord(
        const IdentifierPtr& name,
        const MessagesPtr&   propertiesValues
    ) override;

    /**
     * @brief Adds single named subresult.
     *
     * @param name   name subresult is build
     * @param result subresult
     * @result       reference for itself for chaining
     */
    virtual ResultBuilder& addResult(
        const IdentifierPtr& name,
        const MessagePtr&    result
    ) override;

    /**
     * @brief Build Result.
     *
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages of any Object does not match properties' one
     *
     * @see #buildRaw()
     */
    virtual ResultPtr build() const = 0;

    /**
     * @brief Build raw Result - one that can be inserted into other results.
     *
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages of any Object does not match properties' one
     *
     * @see #build()
     */
    virtual ResultPtr buildRaw() const = 0;

    /**
     * Displays what would be build or error message that would be thrown.
     *
     * @return current result or error message
     *
     * @see #build()
     */
    virtual Message toString() const override;

protected:
    /**
     * @brief Type containing name-properties pair.
     */
    typedef std::pair<IdentifierPtr, MessagesPtr>   PartialResult;
    /**
     * @brief Type containing name to properties mapping.
     */
    typedef boost::container::vector<PartialResult> PartialResults;
    /**
     * @brief Type containing name-subresult pair.
     */
    typedef std::pair<IdentifierPtr, MessagePtr>    SubResult;
    /**
     * @brief Type containing name to subresult mapping.
     */
    typedef boost::container::vector<SubResult>     SubResults;

    /**
     * @brief Names of properties.
     */
    IdentifiersPtr propertiesNames;
    /**
     * @brief Values of declared properties.
     */
    PartialResults partialResults;
    /**
     * @brief SubResults.
     */
    SubResults     subResults;
    /**
     * @brief Indent used.
     */
    Message        indent;

    /**
     * @brief Check whether all records has the same size as headers.
     *
     * @throw IllegalInnerState thrown when some record does not match headers size
     */
    void checkPropertyToResultMatching() const;

    /**
     * @brief Adds indent to the beginning of each line of passes content.
     *
     * @param content content that should be indented
     * @return        indented content
     */
    Message addIndent(
        const Message content
    ) const;
}; /* END class AbstractResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP_INCLUDED */
