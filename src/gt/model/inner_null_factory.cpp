/**
 * @file      gt/model/inner_null_factory.cpp
 * @brief     Defines GT::Model::InnerNullFactory methods.
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

#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class InnerNullFactory final {

InnerNullFactory& InnerNullFactory::getInstance() {
    static InnerNullFactory instance;
    return instance;
}

// public:

StrategicDataPtr InnerNullFactory::createStrategicData() {
    return StrategicDataPtr(new NullStrategicData());
}

ExtensiveDataPtr InnerNullFactory::createExtensiveData() {
    return ExtensiveDataPtr(new NullExtensiveData());
}

ExtensiveDataNodePtr InnerNullFactory::createExtensiveDataNode() {
    return ExtensiveDataNodePtr(new NullExtensiveDataNode());
}

// private:

InnerNullFactory::InnerNullFactory() {}

InnerNullFactory::~InnerNullFactory() {}

// }; /* END class InnerNullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
