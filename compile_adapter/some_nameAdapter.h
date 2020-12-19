#ifndef SOME_NAMEADAPTER_H
#define SOME_NAMEADAPTER_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "some_interfaceInterface.h"
class some_nameAdapter
 : public DBus::Object {
public:
some_nameAdapter(std::string path, std::shared_ptr<some_interfaceInterface> _some_interfaceInterface );
public:
    static std::shared_ptr<some_nameAdapter> create(std::shared_ptr<DBus::Connection> connection, std::string path, std::shared_ptr<some_interfaceInterface> _some_interfaceInterface, DBus::ThreadForCalling calling_thread = DBus::ThreadForCalling::DispatcherThread );
};
#endif /* SOME_NAMEADAPTER_H */
