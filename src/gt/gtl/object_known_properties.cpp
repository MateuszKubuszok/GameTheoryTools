/**
 * @file      gt/gtl/object_known_properties.cpp
 * @brief     Defines GT::GTL::ObjectKnownProperties methods.
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

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ObjectKnownProperties final : public ObjectProperty {
// public:

ObjectKnownProperties::ObjectKnownProperties(
    const Object* describedObject
) :
    object(describedObject)
    {}

ResultPtr ObjectKnownProperties::findForConditions(
    const Context&,
    const Conditions&
) const {
    static const IdentifierPtr knownProperties = createIdentifierPtr("Known Properties");
    static const IdentifierPtr property        = createIdentifierPtr("Property");

    IdentifiersPtr records = createIdentifiersPtr();
    records->push_back(knownProperties);

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    resultBuilder->setHeaders(records);

    IdentifiersPtr propertiesList = object->listProperties();
    for (IdentifierPtr& propertyName : *propertiesList) {
        MessagesPtr content = createMessagesPtr();
        content->push_back( createMessagePtr(propertyName) );
        resultBuilder->addRecord(property, content);
    }

    return resultBuilder->build();
}

// }; /* END class ObjectKnownProperties */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
