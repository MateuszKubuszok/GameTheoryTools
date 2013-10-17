#ifndef __GT_GTL_HELPERS_HPP__
#define __GT_GTL_HELPERS_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Sets up location for ValidableSymbols. 
 *
 * @param  symbol        symbol to set
 * @param  inputLocation location to set
 * @return               reference to selffor chaining
 */
template<typename Symbol>
boost::shared_ptr<Symbol> setupLocation(
    boost::shared_ptr<Symbol> symbol,
    InputLocation&            inputLocation
);

////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/helpers.tpp"

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_HELPERS_HPP__ */
