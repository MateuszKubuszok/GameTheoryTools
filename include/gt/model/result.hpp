#ifndef __GT_MODEL_RESULT_HPP__
#define __GT_MODEL_RESULT_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/result.hpp
 * @brief     Defines GT::Model::Result interface.
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
 * @class Result
 * @brief Root of all Results created by GTL Parser.
 *
 * Since all classes of GT (except factories, Numbers, Identifiers and Messages) extend this one,
 * they are guaranteed to have Result#toSting() and Result#isEqual(const Root&) methods as well as
 * Result#==(const ResultPtr&, const ResultPtr&), Result#!=(const ResultPtr&, const ResultPtr&)
 * and Result#<<(OutputStream&, const ResultPtr&) operators overloaded.
 *
 * @author Mateusz Kubuszok
 *
 * @see ResultBuilder
 * @see ResultFactory
 */
class Result : public virtual Root {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Result();

    /**
     * @brief Returns Result in a form available to send on OutputStream.
     *
     * @return Message with Result
     */
    virtual Message getResult() const = 0;

    /**
     * @brief Defines equality relation.
     *
     * @param root another root to compare
     * @return     true if roots are equal
     */
    virtual bool isEqual(
        const Root& root
    ) const override;

    /**
     * @brief Return message with results.
     *
     * @return Result as a Message
     */
    virtual Message toString() const override;

    /**
     * @brief Syntax sugar for Result#isEqual(const Root&) method.
     *
     * @param result1 first Result to compare
     * @param result2 second Result to compare
     * @return        true if Results are equal
     */
    friend bool operator==(
        const ResultPtr& result1,
        const ResultPtr& result2
    );

    /**
     * @brief Syntax sugar for !Result#isEqual(const Root&) method.
     *
     * @param result1 first Result to compare
     * @param result2 second Result to compare
     * @return        true if Results are not equal
     */
    friend bool operator!=(
        const ResultPtr& result1,
        const ResultPtr& result2
    );

    /**
     * @brief Syntax sugar for #toString() method.
     *
     * @param stream stream to concatenate
     * @param result Result to concatenate
     * @return       stream for chaining
     */
    friend OutputStream& operator<<(
        OutputStream&    stream,
        const ResultPtr& result
    );
}; /* END class Result */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullResult
 * @brief Null Result for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullResult final : public virtual Result {
public:
    virtual Message getResult() const override {
        return Message("NullResult");
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullResult");
    }
}; /* END class NullResult */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_RESULT_HPP__ */
