/**
 * @file      gt/gtl/collections_driver.tpp
 * @brief     Defines GT::GTL::CollectionsDriver methods.
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

// template<typename Content>
// class CollectionsDriver : public virtual Root {
// public:

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::empty() const {
    return new CollectionsDriver<Content>::CollectionPtr(
        new CollectionsDriver<Content>::Collection()
    );
}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::create(
    const typename CollectionsDriver<Content>::ContentPtr* element
) const {
    CollectionsDriver<Content>::CollectionPtr* collection = empty();
    (*collection)->push_back(*element);
    return collection;
}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::insert(
    const typename CollectionsDriver<Content>::ContentPtr*    element,
    const typename CollectionsDriver<Content>::CollectionPtr* collection
) const {
    (*collection)->push_back(*element);
    return new CollectionsDriver<Content>::CollectionPtr(
        *collection
    );
}

template<typename Content>
Message CollectionsDriver<Content>::toString() const {
    return Message("CollectionsDriver");
}

// }; /* END class CollectionsDriver */
