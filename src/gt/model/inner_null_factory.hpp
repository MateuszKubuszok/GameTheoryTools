#ifndef __GT_MODEL_INNER_NULL_FACTORY_HPP__
#define __GT_MODEL_INNER_NULL_FACTORY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/inner_null_factory.hpp
 * @brief     Defines GT::Model::InnerNullFactory class.
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
 * @class InnerNullFactory
 * @brief Used for creation of Null instances for Model inner classes.
 *
 * @author Mateusz Kubuszok
 *
 * @see NullFactory
 */
class InnerNullFactory final {
public:
    /**
     * @brief Returns the instance of a InnerNullFactory.
     *
     * @return InnerNullFactory instance
     */
    static InnerNullFactory& getInstance();

    /**
     * @brief Creates null StrategicData.
     *
     * @result null StrategicData
     */
    StrategicDataPtr createStrategicData();

    /**
     * @brief Creates null ExtensiveData.
     *
     * @result null ExtensiveData
     */
    ExtensiveDataPtr createExtensiveData();

    /**
     * @brief Creates null ExtensiveData.
     *
     * @result null ExtensiveDataNode
     */
    ExtensiveDataNodePtr createExtensiveDataNode();

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    InnerNullFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    InnerNullFactory(
        const InnerNullFactory& innerNullFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~InnerNullFactory();
}; /* END class InnerNullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_INNER_NULL_FACTORY_HPP__ */
