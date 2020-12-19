#ifndef NONAMEPROXY_H
#define NONAMEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
#include "org_freedesktop_Avahi_Server.h"
#include "org_freedesktop_Avahi_Server2.h"
class NONAMEProxy
 : public DBus::ObjectProxy {
public:
NONAMEProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread );
public:
    static std::shared_ptr<NONAMEProxy> create(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread );
    std::shared_ptr<org_freedesktop_Avahi_Server> getorg_freedesktop_Avahi_ServerInterface( );
    std::shared_ptr<org_freedesktop_Avahi_Server2> getorg_freedesktop_Avahi_Server2Interface( );
protected:
    std::shared_ptr<org_freedesktop_Avahi_Server> m_org_freedesktop_Avahi_Server;
    std::shared_ptr<org_freedesktop_Avahi_Server2> m_org_freedesktop_Avahi_Server2;
};
#endif /* NONAMEPROXY_H */
