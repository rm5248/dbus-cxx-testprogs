#include "SimpleTypesProxy.h"

SimpleTypesProxy::SimpleTypesProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread ) : DBus::ObjectProxy( conn, dest, path ){
m_test_interface = test_interface::create( "test.interface" );

}
std::shared_ptr<SimpleTypesProxy> SimpleTypesProxy::create(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread ){
return std::shared_ptr<SimpleTypesProxy>( new SimpleTypesProxy( conn, dest, path, signalCallingThread ) );

}
std::shared_ptr<test_interface> SimpleTypesProxy::gettest_interfaceInterface( ){
return m_test_interface;

}
