#ifndef __GT_PROGRAM_HELPERS_HPP__
#define __GT_PROGRAM_HELPERS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/program/helpers.hpp
 * @brief     Declares GT::Program helpers.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace std {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using GT::InputStream;
using GT::OutputStream;

using GT::Model::ResultBuilderMode;
using GT::Model::ResultIndentationMode;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Allows conversion from ResultBuilderMode to std::string.
 *
 * @param outputStream      OutputStream to write to
 * @param resultBuilderMode ResultBuilderMode to convert
 * @return                  reference to OutputStream for chainging
 */
OutputStream& operator<<(
    OutputStream&           outputStream,
    const ResultBuilderMode resultBuilderMode
);

/**
 * @brief Sets ResultBuilderMode from InputStream.
 *
 * @param inputStream                              InputStream to extract enum from
 * @param resultBuilderMode                        enum that needs to be set
 * @return                                         reference to InputStream for chaining
 * @throw boost::program_options::validation_error thrown when parsed string does not mathc the type of enum
 */
InputStream& operator>>(
    InputStream&       inputStream,
    ResultBuilderMode& resultBuilderMode
);

/**
 * @brief Allows conversion from ResultIndentationMode to std::string.
 *
 * @param outputStream          OutputStream to write to
 * @param resultIndentationMode ResultIndentationMode to convert
 * @return                      reference to OutputStream for chainging
 */
OutputStream& operator<<(
    OutputStream&               outputStream,
    const ResultIndentationMode resultIndentationMode
);

/**
 * @brief Sets ResultBuilderMode from InputStream.
 *
 * @param inputStream                              InputStream to extract enum from
 * @param resultBuilderMode                        enum that needs to be set
 * @return                                         reference to InputStream for chaining
 * @throw boost::program_options::validation_error thrown when parsed string does not mathc the type of enum
 */
InputStream& operator>>(
    InputStream&           inputStream,
    ResultIndentationMode& resultIndentationMode
);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace std */

#endif /* END #ifndef __GT_PROGRAM_HELPERS_HPP__ */
