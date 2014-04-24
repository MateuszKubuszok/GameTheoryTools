#ifndef GT_MODEL_XML_RESULT_BUILDER_HPP_INCLUDED
#define GT_MODEL_XML_RESULT_BUILDER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/xml_result_builder.hpp
 * @brief     Defines GT::Model::XMLResultBuilder class.
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
 * @class XMLResultBuilder
 * @brief Builder used for creating Results displayed to user in XML format.
 *
 * Implements ResultBuilder interface via AbstractResultBuilder class.
 *
 * Used when ResultFactory's BuilderMode is set to BuilderMode#XML.
 *
 * Indentation depends on ResultFactory's IndentationMode.
 *
 * @author Mateusz Kubuszok
 *
 * @see ResultBuilder
 * @see AbstractResultBuilder
 * @see ResultFactory#buildResult()
 */
class XMLResultBuilder final : public AbstractResultBuilder {
public:
    /**
     * @brief Constructor initiating class with indentation.
     *
     * @param indentation sequence used for indentation
     */
    explicit XMLResultBuilder(
        const Message indentation
    );

    /**
     * @brief Build Result.
     *
     * @return                  Result
     * @throw IllegalInnerState thrown when number of Messages for any Object does not match properties' ones
     *
     * @see #buildRaw()
     */
    virtual ResultPtr build() const override;

    /**
     * @brief Build raw Result - one that can be inserted into other results.
     *
     * @return                  Result
     * @throw IllegalInnerState thrown when number of Messages for any Object does not match properties' ones
     *
     * @see #build()
     */
    virtual ResultPtr buildRaw() const override;
}; /* END class XMLResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_XML_RESULT_BUILDER_HPP_INCLUDED */
