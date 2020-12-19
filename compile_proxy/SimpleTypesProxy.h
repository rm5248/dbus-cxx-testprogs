#ifndef SIMPLETYPESPROXY_H
#define SIMPLETYPESPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "test_interface.h"
class SimpleTypesProxy
 : public DBus::ObjectProxy {
public:
SimpleTypesProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread );
public:
    static std::shared_ptr<SimpleTypesProxy> create(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread );
    std::shared_ptr<test_interface> gettest_interfaceInterface( );
protected:
    std::shared_ptr<test_interface> m_test_interface;
};
#endif /* SIMPLETYPESPROXY_H */
