#ifndef __GT_MODEL_RESULT_HPP__
#define __GT_MODEL_RESULT_HPP__

namespace GT {
namespace Model {

/**
 * @brief Root of all Resuts created by GTL parser.
 *
 * @author Mateusz Kubuszok
 */
class Result {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Result() {}

    /**
     * @brief Returns result in a form available to send on output stream.
     *
     * @return string with result
     */ 
    virtual MessagePtr getResult() = 0;
}; /* END class Result */

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_RESULT_HPP__ */
