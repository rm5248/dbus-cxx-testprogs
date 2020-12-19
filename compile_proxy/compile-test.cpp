#include <dbus-cxx.h>
#include <iostream>

#include "SimpleTypesProxy.h"
#include "AvahiServerProxy.h"

int main()
{
    DBus::setLoggingFunction( DBus::logStdErr );
    DBus::setLogLevel( SL_LogLevel::SL_TRACE );
  std::shared_ptr<DBus::Dispatcher> dispatcher;
  dispatcher = DBus::StandaloneDispatcher::create();

  std::shared_ptr<DBus::Connection> connection;
  connection = dispatcher->create_connection( DBus::BusType::SESSION );

    std::shared_ptr<SimpleTypesProxy> simple = SimpleTypesProxy::create( connection,
                                                                         "foo.bar",
                                                                         "/foo/bar" );

    std::shared_ptr<test_interface> tiface = simple->gettest_interfaceInterface();

    std::shared_ptr<DBus::PeerInterfaceProxy> peer = simple->getPeerInterface();

    std::shared_ptr<AvahiServerProxy> avahi = AvahiServerProxy::create( connection, "avahi", "/avahi" );

  std::this_thread::sleep_for( std::chrono::seconds( 30 ) );
  return 0;
}
