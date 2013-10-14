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
    /**
     * @brief Defines SafeBoolIdiom as pointer to the method with no argument and return.
     */
    typedef void (ValidableSymbol::*SafeBoolIdiom)() const;

    /**
     * @brief Defines some method of SafeBoolIdiom type that will not be accessible.
     */
    void comparisonsAreNotAllowed() const;

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
    virtual bool isValid() const;

    /**
     * @brief Safe Bool Idiom used to make checks without comparisons or algrbraic usage of bool.
     */
    operator SafeBoolIdiom() const;
}; /* END class ValidableSymbol */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Not callable on ValidableSymbol to prevent comparison.
 */
template <typename SomeOtherType>
bool operator==(
    const ValidableSymbol& validableSymbol,
    const SomeOtherType&   someOtherType
) {
    validableSymbol.comparisonsAreNotAllowed();
    return false;
}

/**
 * @brief Not callable on ValidableSymbol to prevent comparison.
 */
template <typename SomeOtherType> 
bool operator!=(
    const ValidableSymbol& validableSymbol,
    const SomeOtherType&   someOtherType
) {
    validableSymbol.comparisonsAreNotAllowed();
    return false;
} 

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_VALIDABLE_SYMBOL_HPP__ */
