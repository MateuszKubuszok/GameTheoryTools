#ifndef GT_MODEL_RESULT_FACTORY_HPP_INCLUDED
#define GT_MODEL_RESULT_FACTORY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/result_factory.hpp
 * @brief     Defines GT::Model::ResultFactory class.
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
 * @enum  ResultBuilderMode
 * @brief Used for configuring what kind of builders should be returned by ResultFactory.
 *
 * @author Mateusz Kubuszok
 */
enum class ResultBuilderMode { PLAIN, JSON, XML };

/**
 * @enum  ResultIndentationMode
 * @brief Used for configuring whether builders returned by ResultFacotry should use indentation and how.
 *
 * @author Mateusz Kubuszok
 */
enum class ResultIndentationMode { TABS, SPACES, NONE };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ResultFactory
 * @brief Creates some simple Results as well as supplies builders for more complex of them.
 *
 * The type of ResultBuilder returned by factory is determined by builderMode settings.
 *
 * @author Mateusz Kubuszok
 *
 * @see Result
 * @see ResultBuilder
 */
class ResultFactory final {
    /**
     * @brief Contains current Builder Mode setting.
     */
    ResultBuilderMode     builderMode;

     /**
     * @brief Contains current Indentation Mode setting.
     */
    ResultIndentationMode indentationMode;

public:
    /**
     * @brief Returns the instance of a ResultFactory.
     *
     * @return ResultFactory instance
     */
    static ResultFactory& getInstance();

    /**
     * @brief Returns ResultBuilder.
     *
     * @return ResultBuilder
     */
    ResultBuilderPtr buildResult() const;

    /**
     * @brief Returns Results with predefined const content.
     *
     * @param content content to be contained by the Result
     * @return        Result with constant content
     */
    ResultPtr constResult(
        const Message& content
    ) const;

    /**
     * @brief Returns empty Result.
     *
     * @return an empty result
     */
    ResultPtr emptyResult() const;

    /**
     * @brief Returns current builder mode.
     *
     * @return currently used builder mode
     */
    ResultBuilderMode getBuilderMode() const;

    /**
     * @brief Sets current builder mode.
     *
     * @param  builderMode new builder mode
     * @return             ResultsFactory for chaining
     */
    ResultFactory& setBuilderMode(
        const ResultBuilderMode builderMode
    );

    /**
     * @brief Returns current indentation mode.
     *
     * @return currently used indentation mode
     */
    ResultIndentationMode getIndentationMode() const;

     /**
     * @brief Sets current indentation mode.
     *
     * @param  indentationMode new indentation mode
     * @return                 ResultsFactory for chaining
     */
    ResultFactory& setIndentationMode(
        const ResultIndentationMode indentationMode
    );

private:
    /**
     * @brief Private constructor.
     */
    ResultFactory();

    /**
     * @brief Private copy constructor.
     */
    ResultFactory(
        const ResultFactory& resultFactory
    ) = delete;

    /**
     * @brief Private destructor.
     */
    ~ResultFactory() = default;
}; /* END class ResultFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef GT_MODEL_RESULT_FACTORY_HPP_INCLUDED */
