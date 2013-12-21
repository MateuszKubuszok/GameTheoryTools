#ifndef __GT_GTL_VALIDABLE_SYMBOL_HPP__
#define __GT_GTL_VALIDABLE_SYMBOL_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/validable_symbol.hpp
 * @brief     Defines GT::GTL::ValidableSymbol class.
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
 * @class ValidableSymbol
 * @brief Interface used for marking objects that are valid (or not) symbols in Parser.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 * @see Coordinate
 * @see Definition
 * @see Details
 * @see Game
 * @see Object
 * @see Player
 * @see Param
 * @see Query
 * @see Parser
 */
class ValidableSymbol : public virtual Root {
    /**
     * @brief Defines SafeBoolIdiom as pointer to the method with no argument and return.
     */
    typedef void (ValidableSymbol::*SafeBoolIdiom)() const;

    /**
     * @brief Contains input location.
     */
    InputLocationPtr inputLocation;

public:
    /**
     * @brief Default constructor initiating input location.
     */
    ValidableSymbol();

    /**
     * @brief Default destructor.
     */
    virtual ~ValidableSymbol();

    /**
     * @brief Returns whether object is valid.
     *
     * @return true if object is Valid
     */
    virtual bool isValid() const;

    /**
     * @brief Returns input location.
     *
     * @return input location
     */
    virtual const InputLocationPtr getInputLocation() const;

    /**
     * @brief Sets input location.
     *
     * @param inutLocation input location
     */
    virtual void setInputLocation(
        const InputLocationPtr inputLocation
    );

    /**
     * @brief Safe Bool Idiom used to make checks without comparisons or algrbraic usage of bool.
     */
    operator SafeBoolIdiom() const;

private:
    /**
     * @brief Defines some method of SafeBoolIdiom type that will not be accessible.
     */
    void comparisonsAreNotAllowed() const;
}; /* END class ValidableSymbol */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_VALIDABLE_SYMBOL_HPP__ */
