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

class ObjectTypeProperty;
class ObjectKnownProperties;

class ParamTypeProperty;
class ParamValueProperty;

class IdentifierParam;
class ValueParam;

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

////////////////////////////////////////////////////////////////////////////////

/* Implementations headers */

#include "gt/gtl/object_type_property.hpp"
#include "gt/gtl/object_known_properties.hpp"

#include "gt/gtl/param_type_property.hpp"
#include "gt/gtl/param_value_property.hpp"

#include "gt/gtl/identifier_param.hpp"
#include "gt/gtl/value_param.hpp"

////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_GTL_INNER_COMMON_HPP__ */