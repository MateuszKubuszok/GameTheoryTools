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
    /**
     * @brief Name of the property
     */
    const IdentifierPtr name;

    /**
     * @brief Value of the property.
     */
    const ObjectPtr value;

public:
    /**
     * @brief Constructor for name and value.
     *
     * @param definedName  name of the defined property
     * @param definedValue value of the defined property
     */
    Definition(
        IdentifierPtr definedName,
        ObjectPtr     definedValue
    );

    /**
     * @brief Default constructor.
     */
    ~Definition();

    /**
     * @brief Returns name of the property.
     *
     * @return value of the property
     */
    IdentifierPtr getName();

    /**
     * @brief Returns value of the property.
     *
     * @return value of the property
     */
    ObjectPtr getValue();
}; /* END class Definition */

} /* END namepsace GTL */
} /* END namspace GT */

#endif /* END #ifndef __GT_GTL_DEFINITION_HPP__ */
