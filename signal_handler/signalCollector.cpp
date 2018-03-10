#include <dbus-cxx.h>
#include "myData.h"
#include <stdio.h>
#include <unistd.h>

using namespace std;

void print( struct _myData );

int main()
{

  DBus::init();

  DBus::Dispatcher::pointer dispatcher = DBus::Dispatcher::create();

  DBus::Connection::pointer connection = dispatcher->create_connection( DBus::BUS_SYSTEM );

  DBus::signal_proxy<void, struct _myData>::pointer signal = connection->create_signal_proxy<void, struct _myData>("/test/signal/Object", "test.signal.Type", "Test");

  signal->connect( sigc::ptr_fun(print) );

  std::cout << "Running" << std::flush;
  
  for (;;)
  {
    std::cout << "." << std::flush;
    sleep(1);
  }
  
  std::cout << std::endl;

  return 0;
}

void print( struct _myData val ){
  cout << "The data in the signal: " << endl;
  cout << "Octet: " << (int)val.octet << endl;
  cout << "Dword: " << (int)val.dword << endl;
  cout << "Name : " << val.deviceName << endl << endl;
}
