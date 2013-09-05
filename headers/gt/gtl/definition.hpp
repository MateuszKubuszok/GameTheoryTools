#ifndef __GT_GTL_DEFINITION_HPP__
#define __GT_GTL_DEFINITION_HPP__

namespace GT {
namespace GTL {

/**
 * @brief Definition used to define Context. 
 *
 * @author Mateusz Kubuszok
 */
class Definition : public virtual Root {
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

    /**
     * @brief Returns Message about Definition.
     *
     * @return Definition's Message
     */
    virtual Message toString();
}; /* END class Definition */

} /* END namepsace GTL */
} /* END namspace GT */

#endif /* END #ifndef __GT_GTL_DEFINITION_HPP__ */
