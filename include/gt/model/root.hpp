#ifndef __GT_MODEL_ROOT_HPP__
#define __GT_MODEL_ROOT_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/root.hpp
 * @brief     Defines GT::Model::Root class.
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
 * @class Root
 * @brief Basic interface of many classes used in the project.
 *
 * @author Mateusz Kubuszok
 */
class Root {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Root();

    /**
     * @brief Defines equality relation.
     *
     * @param root another root to compare
     * @return     true if roots are equal
     */
    virtual bool isEqual(
        const Root& root
    ) const;

    /**
     * @brief Wheter Root is not a null Object (null guardian).
     *
     * @return true if object is not a null object
     */
    virtual bool isNotNull() const;

    /**
     * @brief Wheter Root is a null Object (null guardian).
     *
     * @return true if object is a null object
     */
    bool isNull() const;

    /**
     * @brief Returns Message about an Object allowing its debuging.
     *
     * Also used by Models and Routines to render Results.
     *
     * @return Root's Message
     */
    virtual Message toString() const = 0;

    /**
     * @brief Syntax sugar for #isEqual(const Root&)const method.
     *
     * @param root1 first Root to compare
     * @param root2 second Root to compare
     * @return      true if Root are equal
     */
    friend bool operator==(
        const Root& root1,
        const Root& root2
    );

     /**
     * @brief Syntax sugar for !#isEqual(const Root&)const method.
     *
     * @param root1 first Root to compare
     * @param root2 second Root to compare
     * @return      true if Root are not equal
     */
    friend bool operator!=(
        const Root& root1,
        const Root& root2
    );

     /**
     * @brief Syntax sugar for #toString()const method.
     *
     * @param stream stream to concatenate
     * @param root   Root to concatenate
     * @return       stream for chaining
     */
    friend OutputStream& operator<<(
        OutputStream& stream,
        const Root&   root
    );
}; /* END class Root */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namepsace Model */
} /* END namspace GT */

#endif /* END #ifndef __GT_MODEL_ROOT_HPP__ */
