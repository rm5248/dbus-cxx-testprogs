#include <dbus-cxx.h>
#include <iostream>



int main()
{
    DBus::setLoggingFunction( DBus::logStdErr );
    DBus::setLogLevel( SL_LogLevel::SL_TRACE );
  std::shared_ptr<DBus::Dispatcher> dispatcher;
  dispatcher = DBus::StandaloneDispatcher::create();

  std::shared_ptr<DBus::Connection> connection;
  connection = dispatcher->create_connection( DBus::BusType::SESSION );


  std::this_thread::sleep_for( std::chrono::seconds( 30 ) );
  return 0;
}
