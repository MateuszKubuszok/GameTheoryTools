#ifndef __GT_MODEL_ROOT_HPP__
#define __GT_MODEL_ROOT_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Basic interface of many classes used in the project.
 *
 * <p>Should be inherited with <pre>public virtual</pre> modifiers.</p>
 *
 * @author Mateusz Kubuszok
 */
class Root {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Root();

    /**
     * @brief Defines equality relation.
     *
     * @param root another root to compare
     * @return     true if roots are equal
     */
    virtual bool isEqual(
        const Root& root
    ) const;

    /**
     * @brief Wheter Root is not a null object (null guardian).
     *
     * @return true if object is not a null object
     */
    virtual bool isNotNull() const;

    /**
     * @brief Wheter Root is a null object (null guardian).
     *
     * @return true if object is a null object
     */
    bool isNull() const;

    /**
     * @brief Returns Message about an object allowing its debuging.
     *
     * @return Root's Message
     */
    virtual Message toString() const = 0;

        /**
     * @brief Syntax sugar for isEqual method.
     *
     * @param root1 first Root to compare
     * @param root2 second Root to compare
     * @return      true if Root are equal
     */
    friend bool operator==(
        const Root& root1,
        const Root& root2
    );

     /**
     * @brief Syntax sugar for !isEqual method.
     *
     * @param root1 first Root to compare
     * @param root2 second Root to compare
     * @return      true if Root are not equal
     */
    friend bool operator!=(
        const Root& root1,
        const Root& root2
    );

     /**
     * @brief Syntax sugar for toStream method.
     *
     * @param stream stream to concatenate
     * @param root   Root to concatenate
     * @return       stream for chaining
     */
    friend OutputStream& operator<<(
        OutputStream& stream,
        const Root&   root
    );
}; /* END class Root */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namepsace Model */
} /* END namspace GT */

#endif /* END #ifndef __GT_MODEL_ROOT_HPP__ */
