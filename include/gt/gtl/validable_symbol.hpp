#ifndef __GT_GTL_VALIDABLE_SYMBOL_HPP__
#define __GT_GTL_VALIDABLE_SYMBOL_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
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
    virtual InputLocationPtr getInputLocation();

    /**
     * @brief Sets input location.
     *
     * @param inutLocation input location
     */
    virtual void setInputLocation(
        InputLocationPtr inputLocation
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
