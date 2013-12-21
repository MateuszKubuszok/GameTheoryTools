#ifndef __GT_MODEL_EMPTY_RESULT_HPP__
#define __GT_MODEL_EMPTY_RESULT_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/empty_result.hpp
 * @brief     Defines GT::Model::EmptyResult class.
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
 * @class EmptyResult
 * @brief Contains empty Message.
 *
 * Implements Result interface.
 *
 * @author Mateusz Kubuszok
 *
 * @see Result
 * @see ConstResult
 * @see ResultFactory
 */
class EmptyResult final : public Result {
public:
    /**
     * @brief Creates Result with empty Message.
     */
    EmptyResult();

    /**
     * Returns Result's Message.
     *
     * @return Results's Message
     */
    virtual Message getResult() const override;
}; /* END class EmptyString */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EMPTY_RESULT_HPP__ */
