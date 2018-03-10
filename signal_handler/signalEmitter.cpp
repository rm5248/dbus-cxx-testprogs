#include "myData.h"
#include <dbus-cxx.h>
#include <stdio.h>
#include <unistd.h>

/**
 * This example demonstrates a signal emitter using a dbus-cxx signal
 * derived from sigc::signal.
 *
 * The message of the signal is created when the signal is emitted from
 * the emission parameters.
 *
 * However, the connection must still be flushed since a dispatcher is
 * not being used.
 */

int main()
{
  DBus::init();
  
  DBus::Connection::pointer connection = DBus::Connection::create( DBus::BUS_SYSTEM );

  DBus::signal<void,struct _myData>::pointer signal = connection->create_signal<void,struct _myData>("/test/signal/Object", "test.signal.Type", "Test");

  struct _myData sigvalue1;
  sigvalue1.octet = 128;
  sigvalue1.dword = 65535;
  sigvalue1.deviceName = "Hogwaller";
  
  for (;;)
  {
    signal->emit( sigvalue1 );
    connection->flush();
    sleep (1);
  }
}
