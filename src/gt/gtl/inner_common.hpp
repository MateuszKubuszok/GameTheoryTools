#ifndef __GT_GTL_INNER_COMMON_HPP__
#define __GT_GTL_INNER_COMMON_HPP__

////////////////////////////////////////////////////////////////////////////////

/* Include standard libraries */
#include <sstream>

/* Includes boost libraries */
#include <boost/foreach.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/thread/mutex.hpp>

/* Includes public interface */
#include "gt/gtl/common.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace GT{
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/* Implementations declarations */

class ExceptionFactory;

class ObjectTypeProperty;
class ObjectKnownProperties;

class ParamValueProperty;

class IdentifierParam;
class NumberParam;
class ObjectParam;

/* Shortens comonly used names */
typedef Model::ResultFactory    ResultFactory;
typedef Model::ResultBuilderPtr ResultBuilderPtr;

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

////////////////////////////////////////////////////////////////////////////////

/* Implementations headers */

#include "gt/gtl/exception_factory.hpp"

#include "gt/gtl/object_type_property.hpp"
#include "gt/gtl/object_known_properties.hpp"

#include "gt/gtl/param_value_property.hpp"

#include "gt/gtl/identifier_param.hpp"
#include "gt/gtl/number_param.hpp"
#include "gt/gtl/object_param.hpp"

////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_GTL_INNER_COMMON_HPP__ */
