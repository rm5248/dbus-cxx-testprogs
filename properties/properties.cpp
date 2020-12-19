#include <dbus-cxx.h>
#include <iostream>

static void foo(){

}

static void localObject( std::shared_ptr<DBus::Connection> conn ){
    std::shared_ptr<DBus::Object> obj =
            conn->create_object( "/foo/bar", DBus::ThreadForCalling::DispatcherThread );

    obj->create_property<bool>( "what.blah", "FooProperty" );
    obj->create_method<void()>( "what.blah", "foo", sigc::ptr_fun( foo ) );
}

int main()
{
    DBus::setLoggingFunction( DBus::logStdErr );
    DBus::setLogLevel( SL_LogLevel::SL_TRACE );
  std::shared_ptr<DBus::Dispatcher> dispatcher;
  dispatcher = DBus::StandaloneDispatcher::create();

  std::shared_ptr<DBus::Connection> connection;
  connection = dispatcher->create_connection( DBus::BusType::SESSION );

  std::shared_ptr<DBus::ObjectProxy> object;
  object = connection->create_object_proxy("org.gnome.Shell", "/org/gnome/Shell");

  std::shared_ptr<DBus::PropertyProxy<bool> > overviewProperty =
    object->create_property<bool>( "org.gnome.Shell", "OverviewActive", DBus::PropertyUpdateType::Updates );

  std::cout << "overiview active: " << overviewProperty->value() << std::endl;

  connection->request_name( "dbuscxx.foo.bar" );
  localObject( connection );


  std::this_thread::sleep_for( std::chrono::seconds( 30 ) );
  return 0;
}
