#ifndef __GT_PROGRAM_HELPERS_HPP__
#define __GT_PROGRAM_HELPERS_HPP__

namespace std {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Allows conversion from ResultBuilderMode to std::string.
 *
 * @param outputStream      OutputStream to write to
 * @param resultBuilderMode ResultBuilderMode to convert
 * @return                  reference to OutputStream for chainging
 */
GT::OutputStream& operator<<(
    GT::OutputStream&                  outputStream,
    const GT::Model::ResultBuilderMode resultBuilderMode
);

/**
 * @brief Sets ResultBuilderMode from InputStream.
 *
 * @param inputStream                              InputStream to extract enum from
 * @param resultBuilderMode                        enum that needs to be set
 * @return                                         reference to InputStream for chaining
 * @throw boost::program_options::validation_error thrown when parsed string does not mathc the type of enum
 */
GT::InputStream& operator>>(
    GT::InputStream&              inputStream,
    GT::Model::ResultBuilderMode& resultBuilderMode
);

/**
 * @brief Allows conversion from ResultIndentationMode to std::string.
 *
 * @param outputStream          OutputStream to write to
 * @param resultIndentationMode ResultIndentationMode to convert
 * @return                      reference to OutputStream for chainging
 */
GT::OutputStream& operator<<(
    GT::OutputStream&                      outputStream,
    const GT::Model::ResultIndentationMode resultIndentationMode
);

/**
 * @brief Sets ResultBuilderMode from InputStream.
 *
 * @param inputStream                              InputStream to extract enum from
 * @param resultBuilderMode                        enum that needs to be set
 * @return                                         reference to InputStream for chaining
 * @throw boost::program_options::validation_error thrown when parsed string does not mathc the type of enum
 */
GT::InputStream& operator>>(
    GT::InputStream&                  inputStream,
    GT::Model::ResultIndentationMode& resultIndentationMode
);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace std */

#endif /* END #ifndef __GT_PROGRAM_HELPERS_HPP__ */
