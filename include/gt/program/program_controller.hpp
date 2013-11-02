#ifndef __GT_MAIN_PROGRAM_CONTROLLER_HPP__
#define __GT_MAIN_PROGRAM_CONTROLLER_HPP__

namespace GT {
namespace Program {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Sets up Parser and runs it.
 *
 * @author Mateusz Kubuszok
 *
 * @see GTL::Parser
 */
class ProgramController {
    /**
     * @brief Debug level - if its different to 0 parser messages are shown.
     */
    int            debugLevel;
    /**
     * @brief Whether ExcutionDriver should be used instead of CheckingDriver.
     */
    bool           shouldExecute;

    /**
     * @brief Pointer to input stream.
     */
    std::istream*  inputStream;
    /**
     * @brief Pointer to output stream.
     */
    std::ostream*  outputStream;
    /**
     * @brief Pointer to error stream.
     */
    std::ostream*  errorStream;

    /**
     * @brief Whether input stream need to be released after usage.
     */
    bool shouldFreeInputStream;
    /**
     * @brief Whether output stream need to be released after usage.
     */
    bool shouldFreeOutputStream;
    /**
     * @brief Whether error stream need to be released after usage.
     */
    bool shouldFreeErrorStream;

public:
    /**
     * @brief Initiates controller with default settings.
     *
     * <p>By default stream are set to standard ones (without freeing), debug level is set to 0 and driver
     * executes input.</p>
     */
    ProgramController();

    /**
     * @brief Default destructor - frees resources if necessary.
     */
    ~ProgramController();

    /**
     * @brief Sets used driver to Checking Driver.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setCheckingOnly();

    /**
     * @brief Sets used driver to Execution Driver.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setCheckingAndExecution();

    /**
     * @brief Sets debug level.
     *
     * @param debugLevel new debug level
     * @return           reference to itself for chaining
     */
    ProgramController& setDebugLevel(
        int debugLevel
    );

    /**
     * @brief Sets used input stream to standard input stream.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setDefaultInputStream();

    /**
     * @brief Sets used input stream to file input stream.
     *
     * @param filename name of file to read
     * @return         reference to itself for chaining
     */
    ProgramController& setInputStream(
        std::string filename
    );

    /**
     * @brief Sets used input stream to given input stream.
     *
     * @param inputStream   name of new input stream
     * @param shouldBeFreed whether resource shoud be freed after usage
     * @return              reference to itself for chaining
     */
    ProgramController& setInputStream(
        InputStream* inputStream,
        bool         shouldBeFreed
    );

    /**
     * @brief Sets used output stream to standard output stream.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setDefaultOutputStream();

    /**
     * @brief Sets used output stream to file output stream.
     *
     * @param filename name of file to write
     * @return         reference to itself for chaining
     */
    ProgramController& setOutputStream(
        std::string filename
    );

    /**
     * @brief Sets used output stream to given output stream.
     *
     * @param outputStream  name of new output stream
     * @param shouldBeFreed whether resource shoud be freed after usage
     * @return              reference to itself for chaining
     */
    ProgramController& setOutputStream(
        OutputStream* outputStream,
        bool          shouldBeFreed
    );

    /**
     * @brief Sets used error stream to standard error stream.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setDefaultErrorStream();

    /**
     * @brief Sets used error stream to file output stream.
     *
     * @param filename name of file to write
     * @return         reference to itself for chaining
     */
    ProgramController& setErrorStream(
        std::string filename
    );

    /**
     * @brief Sets used error stream to given error stream.
     *
     * @param errorStream   name of new error stream
     * @param shouldBeFreed whether resource shoud be freed after usage
     * @return              reference to itself for chaining
     */
    ProgramController& setErrorStream(
        OutputStream* errorStream,
        bool          shouldBeFreed
    );

    /**
     * @brief Executes Parser as a program.
     *
     * @return 0 of no error occurred, number of errors otherwise
     */
    int run();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Program */
} /* END namespace GT */

#endif /* #ifndef __GT_MAIN_PROGRAM_CONTROLLER_HPP__ */
