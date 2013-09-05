#ifndef __GT_MODEL_ROOT_HPP__
#define __GT_MODEL_ROOT_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Basic interface of many classes used in the project.
 *
 * Should be inherited with <pre>public virtual</pre> modifiers.
 *
 * @author Mateusz Kubuszok
 */
class Root {
    /**
     * @brief Syntax sugar for isEqual method.
     *
     * @param root1 first Root to compare
     * @param root2 second Root to compare
     * @return      true if Root are equal
     */
    friend bool operator==(
        Root& root1,
        Root& root2
    );

     /**
     * @brief Syntax sugar for !isEqual method.
     *
     * @param root1 first Root to compare
     * @param root2 second Root to compare
     * @return      true if Root are not equal
     */
    friend bool operator!=(
        Root& root1,
        Root& root2
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
        Root&         root
    );

    /**
     * @brief Whether class is in debug mode.
     */
    static bool debugMode;

    /**
     * @brief Number of allocations till now.
     */
    static unsigned int allocations;

    /**
     * @brief OutputStream to print debug results. 
     */
    static OutputStream* outputStream;
    
    /**
     * @brief Current Root's ID for debug mode.
     */
    unsigned int rootID;

public:
    /**
     * @brief Whether debug mode is used.
     *
     * @return true if debug mode is set
     */
    static bool getDebugMode();

    /**
     * @brief Sets debug mode.
     *
     * @param newDebugMode new debug mode
     */
    static void setDebugMode(
        bool newDebugMode
    );

    /**
     * @brief Sets output stream.
     *
     * @param newOutputStream new output stream
     */
    static void setOutputStream(
        OutputStream& newOutputStream
    );

    /**
     * @brief Default constructor.
     */
    Root();

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
        Root& root
    );

    /**
     * @brief Wheter Root is not a null object (null guardian). 
     *
     * @return true if object is not a null object
     */
    virtual bool isNotNull();

    /**
     * @brief Wheter Root is a null object (null guardian). 
     *
     * @return true if object is a null object
     */
    bool isNull();

    /**
     * @brief Returns Message about an object allowing its debuging.
     *
     * @return Root's Message
     */
    virtual Message toString() = 0;
};

////////////////////////////////////////////////////////////////////////////////

} /* END namepsace Model */
} /* END namspace GT */

#endif /* END #ifndef __GT_MODEL_ROOT_HPP__ */
