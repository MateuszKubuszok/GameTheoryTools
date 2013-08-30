#ifndef __GT_GTL_DEFINITION_HPP__
#define __GT_GTL_DEFINITION_HPP__

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Definition used to define Context. 
 *
 * @author Mateusz Kubuszok
 */
class Definition {
public:
    /**
     * @brief Constructor for name and value.
     *
     * @param definedName  name of the defined property
     * @param definedValue value of the defined property
     */
    Definition(
        Identifier& definedName,
        Object&     definedValue
    ) :
        name(definedName),
        value(definedValue);

    /**
     * @brief Default constructor.
     */
    ~Definition();

    /**
     * @brief Returns name of the property.
     *
     * @return value of the property
     */
    Identifier getName();

    /**
     * @brief Returns value of the property.
     *
     * @return value of the property
     */
    Object getValue();
private:
    /**
     * @brief Name of the property
     */
    const Identifier name;

    /**
     * @brief Value of the property.
     */
    const Object value;
} /* END class Definition */

} /* END namepsace GTL */
} /* END namspace GT */

#endif /* #ifndef __GT_GTL_DEFINITION_HPP__ */
