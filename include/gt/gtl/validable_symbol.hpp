#ifndef __GT_GTL_VALIDABLE_SYMBOL_HPP__
#define __GT_GTL_VALIDABLE_SYMBOL_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Interface used for marking objects that are valid (or not) symbols in parser.
 *
 * @author Mateusz Kubuszok
 */
class ValidableSymbol {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~ValidableSymbol();

    /**
     * @brief Returns whether object is valid.
     *
     * @return true if object is Valid
     */
    virtual bool isValid();
}; /* END class ValidableSymbol */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_VALIDABLE_SYMBOL_HPP__ */
