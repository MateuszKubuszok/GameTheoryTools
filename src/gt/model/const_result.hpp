#ifndef GT_MODEL_CONST_RESULT_HPP_INCLUDED
#define GT_MODEL_CONST_RESULT_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/const_result.hpp
 * @brief     Defines GT::Model::ConstResult class.
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
 * @class ConstResult
 * @brief Contains const Result Message.
 *
 * Implements Result interface.
 *
 * @author Mateusz Kubuszok
 *
 * @see Result
 * @see EmptyResult
 * @see ResultFactory
 */
class ConstResult final : public Result {
    /**
     * @brief Result to return.
     */
    const Message result;

public:
    /**
     * @brief Initiates Result with a Message.
     *
     * @param content message that should be stored as a Result
     */
    explicit ConstResult(
        const Message& content
    );

    /**
     * Returns Result's Message.
     *
     * @return Results's Message
     */
    virtual Message getResult() const override;
}; /* END class ConstResult */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_CONST_RESULT_HPP_INCLUDED */
