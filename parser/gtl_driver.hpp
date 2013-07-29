#ifndef __GTL_DRIVER_HPP__
    #define __GTL_DRIVER_HPP__ 1

    #include <boost/container/slist.hpp>

    #include "gtl_definition.hpp"
    #include "gtl_query.hpp"
    #include "gtl_object.hpp"
    #include "gtl_identifier.hpp"
    #include "gtl_condition.hpp"

    namespace GTL {
        class Driver {
        public:
            Driver();
            virtual ~Driver();

            virtual void storeDefinedObject(Definition &definition);
            virtual void executeQuery(Query &query);

            Definition& createDefinition(Object &object, std::string &identifier);

            Query& createQuery(boost::containers::slist<std::string> &identifiers, boost::containers::slist<Object>, boost::containers::slist<Condition> &conditions);

            // TODO
        }
    }
#endif /* END __GTL_DRIVER_HPP__ */