#include <dbus-cxx.h>
#include <dbus-cxx-qt.h>
#include <QCoreApplication>
#include <QTimer>

#include "avahitester.h"

int main( int argc, char** argv ){
    QCoreApplication a(argc, argv);
    std::shared_ptr<DBus::Dispatcher> disp;
    std::shared_ptr<DBus::Connection> conn;

    disp = DBus::Qt::QtDispatcher::create();
    conn = disp->create_connection( DBus::BusType::SYSTEM );
    if( !conn ){
        return 1;
    }

    AvahiTester avahi;
    avahi.setConnection( conn );
    QTimer::singleShot( 0, &avahi, &AvahiTester::start );

    return a.exec();
}
