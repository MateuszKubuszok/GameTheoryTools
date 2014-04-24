#ifndef GT_GTL_PARAM_FACTORY_HPP_INCLUDED
#define GT_GTL_PARAM_FACTORY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/param_factory.hpp
 * @brief     Defines GT::GTL::ParamFactory class.
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
 * @class ParamFactory
 * @brief Used for creation of Params that may differs in behaviour.
 *
 * @author Mateusz Kubuszok
 */
class ParamFactory final {
public:
    /**
     * @brief Returns the instance of a ParamFactory.
     *
     * @return ParamFactory instance
     */
    static ParamFactory& getInstance();

    /**
     * @brief Creates Param by identifier attatched to it.
     *
     * @param identifier identifier of a Param
     * @return           Param instance
     */
    ParamPtr createParam(
        const Identifier& identifier
    ) const;

    /**
     * @brief Creates Param by identifier attatched to it.
     *
     * @param identifier identifier of a Param
     * @return           Param instance
     */
    ParamPtr createParam(
        const IdentifierPtr identifier
    ) const;

    /**
     * @brief Creates Param by value contained by it.
     *
     * @param number value of a Param
     * @return       Param instance
     */
    ParamPtr createParam(
        const Number& number
    ) const;

    /**
     * @brief Creates Param by value contained by it.
     *
     * @param number value of a Param
     * @return       Param instance
     */
    ParamPtr createParam(
        const NumberPtr number
    ) const;

    /**
     * @brief Creates Param by value contained by it.
     *
     * @param object value of a Param
     * @return       Param instance
     */
    ParamPtr createParam(
        const ObjectPtr object
    ) const;

private:
    /**
     * @brief Private constructor.
     */
    ParamFactory() = default;

    /**
     * @brief Private copy constructor.
     */
    ParamFactory(
        const ParamFactory& paramFactory
    ) = delete;

    /**
     * @brief Private destructor.
     */
    ~ParamFactory() = default;
}; /* END class ParamFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_PARAM_FACTORY_HPP_INCLUDED */
