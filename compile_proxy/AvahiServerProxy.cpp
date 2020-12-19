#include "AvahiServerProxy.h"

AvahiServerProxy::AvahiServerProxy(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread ) : DBus::ObjectProxy( conn, dest, path ){
m_org_freedesktop_Avahi_Server = org_freedesktop_Avahi_Server::create( "org.freedesktop.Avahi.Server" );
m_org_freedesktop_Avahi_Server2 = org_freedesktop_Avahi_Server2::create( "org.freedesktop.Avahi.Server2" );

}
std::shared_ptr<AvahiServerProxy> AvahiServerProxy::create(std::shared_ptr<DBus::Connection> conn, std::string dest, std::string path, DBus::ThreadForCalling signalCallingThread ){
return std::shared_ptr<AvahiServerProxy>( new AvahiServerProxy( conn, dest, path, signalCallingThread ) );

}
std::shared_ptr<org_freedesktop_Avahi_Server> AvahiServerProxy::getorg_freedesktop_Avahi_ServerInterface( ){
return m_org_freedesktop_Avahi_Server;

}
std::shared_ptr<org_freedesktop_Avahi_Server2> AvahiServerProxy::getorg_freedesktop_Avahi_Server2Interface( ){
return m_org_freedesktop_Avahi_Server2;

}
