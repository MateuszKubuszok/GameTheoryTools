#ifndef __GT_GTL_HELPERS_HPP__
#define __GT_GTL_HELPERS_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

/**
 * @brief Creates error Message for given parent message and error origin.
 *
 * @param parentMessage parent message that will be explained by suberror message
 * @param invalidSymbol invalid symbol to display
 * @return              message to show
 */
Message suberrorMessage(
    Message&         parentMessage,
    ValidableSymbol& invalidSymbol
);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/helpers.tpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_HELPERS_HPP__ */
