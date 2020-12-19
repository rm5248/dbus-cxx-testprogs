#include "org_freedesktop_Avahi_Server.h"

org_freedesktop_Avahi_Server::org_freedesktop_Avahi_Server(std::string name ) : DBus::InterfaceProxy( name ){
m_method_GetVersionString = this->create_method<std::string()>("GetVersionString");
m_method_GetAPIVersion = this->create_method<uint32_t()>("GetAPIVersion");
m_method_GetHostName = this->create_method<std::string()>("GetHostName");
m_method_SetHostName = this->create_method<void(std::string)>("SetHostName");
m_method_GetHostNameFqdn = this->create_method<std::string()>("GetHostNameFqdn");
m_method_GetDomainName = this->create_method<std::string()>("GetDomainName");
m_method_IsNSSSupportAvailable = this->create_method<bool()>("IsNSSSupportAvailable");
m_method_GetState = this->create_method<int32_t()>("GetState");
m_method_GetLocalServiceCookie = this->create_method<uint32_t()>("GetLocalServiceCookie");
m_method_GetAlternativeHostName = this->create_method<std::string(std::string)>("GetAlternativeHostName");
m_method_GetAlternativeServiceName = this->create_method<std::string(std::string)>("GetAlternativeServiceName");
m_method_GetNetworkInterfaceNameByIndex = this->create_method<std::string(int32_t)>("GetNetworkInterfaceNameByIndex");
m_method_GetNetworkInterfaceIndexByName = this->create_method<int32_t(std::string)>("GetNetworkInterfaceIndexByName");
m_method_ResolveHostName = this->create_method<uint32_t(int32_t,int32_t,std::string,int32_t,uint32_t)>("ResolveHostName");
m_method_ResolveAddress = this->create_method<uint32_t(int32_t,int32_t,std::string,uint32_t)>("ResolveAddress");
m_method_ResolveService = this->create_method<uint32_t(int32_t,int32_t,std::string,std::string,std::string,int32_t,uint32_t)>("ResolveService");
m_method_EntryGroupNew = this->create_method<DBus::Path()>("EntryGroupNew");
m_method_DomainBrowserNew = this->create_method<DBus::Path(int32_t,int32_t,std::string,int32_t,uint32_t)>("DomainBrowserNew");
m_method_ServiceTypeBrowserNew = this->create_method<DBus::Path(int32_t,int32_t,std::string,uint32_t)>("ServiceTypeBrowserNew");
m_method_ServiceBrowserNew = this->create_method<DBus::Path(int32_t,int32_t,std::string,std::string,uint32_t)>("ServiceBrowserNew");
m_method_ServiceResolverNew = this->create_method<DBus::Path(int32_t,int32_t,std::string,std::string,std::string,int32_t,uint32_t)>("ServiceResolverNew");
m_method_HostNameResolverNew = this->create_method<DBus::Path(int32_t,int32_t,std::string,int32_t,uint32_t)>("HostNameResolverNew");
m_method_AddressResolverNew = this->create_method<DBus::Path(int32_t,int32_t,std::string,uint32_t)>("AddressResolverNew");
m_method_RecordBrowserNew = this->create_method<DBus::Path(int32_t,int32_t,std::string,uint16_t,uint16_t,uint32_t)>("RecordBrowserNew");

}
std::shared_ptr<org_freedesktop_Avahi_Server> org_freedesktop_Avahi_Server::create(std::string name ){
return std::shared_ptr<org_freedesktop_Avahi_Server>( new org_freedesktop_Avahi_Server( name ));

}
std::string org_freedesktop_Avahi_Server::GetVersionString( ){
return (*m_method_GetVersionString)();

}
uint32_t org_freedesktop_Avahi_Server::GetAPIVersion( ){
return (*m_method_GetAPIVersion)();

}
std::string org_freedesktop_Avahi_Server::GetHostName( ){
return (*m_method_GetHostName)();

}
void org_freedesktop_Avahi_Server::SetHostName(std::string name ){
(*m_method_SetHostName)(name);

}
std::string org_freedesktop_Avahi_Server::GetHostNameFqdn( ){
return (*m_method_GetHostNameFqdn)();

}
std::string org_freedesktop_Avahi_Server::GetDomainName( ){
return (*m_method_GetDomainName)();

}
bool org_freedesktop_Avahi_Server::IsNSSSupportAvailable( ){
return (*m_method_IsNSSSupportAvailable)();

}
int32_t org_freedesktop_Avahi_Server::GetState( ){
return (*m_method_GetState)();

}
uint32_t org_freedesktop_Avahi_Server::GetLocalServiceCookie( ){
return (*m_method_GetLocalServiceCookie)();

}
std::string org_freedesktop_Avahi_Server::GetAlternativeHostName(std::string name ){
return (*m_method_GetAlternativeHostName)(name);

}
std::string org_freedesktop_Avahi_Server::GetAlternativeServiceName(std::string name ){
return (*m_method_GetAlternativeServiceName)(name);

}
std::string org_freedesktop_Avahi_Server::GetNetworkInterfaceNameByIndex(int32_t index ){
return (*m_method_GetNetworkInterfaceNameByIndex)(index);

}
int32_t org_freedesktop_Avahi_Server::GetNetworkInterfaceIndexByName(std::string name ){
return (*m_method_GetNetworkInterfaceIndexByName)(name);

}
uint32_t org_freedesktop_Avahi_Server::ResolveHostName(int32_t interface, int32_t protocol, std::string name, int32_t aprotocol, uint32_t flags ){
return (*m_method_ResolveHostName)(interface,protocol,name,aprotocol,flags);

}
uint32_t org_freedesktop_Avahi_Server::ResolveAddress(int32_t interface, int32_t protocol, std::string address, uint32_t flags ){
return (*m_method_ResolveAddress)(interface,protocol,address,flags);

}
uint32_t org_freedesktop_Avahi_Server::ResolveService(int32_t interface, int32_t protocol, std::string name, std::string type, std::string domain, int32_t aprotocol, uint32_t flags ){
return (*m_method_ResolveService)(interface,protocol,name,type,domain,aprotocol,flags);

}
DBus::Path org_freedesktop_Avahi_Server::EntryGroupNew( ){
return (*m_method_EntryGroupNew)();

}
DBus::Path org_freedesktop_Avahi_Server::DomainBrowserNew(int32_t interface, int32_t protocol, std::string domain, int32_t btype, uint32_t flags ){
return (*m_method_DomainBrowserNew)(interface,protocol,domain,btype,flags);

}
DBus::Path org_freedesktop_Avahi_Server::ServiceTypeBrowserNew(int32_t interface, int32_t protocol, std::string domain, uint32_t flags ){
return (*m_method_ServiceTypeBrowserNew)(interface,protocol,domain,flags);

}
DBus::Path org_freedesktop_Avahi_Server::ServiceBrowserNew(int32_t interface, int32_t protocol, std::string type, std::string domain, uint32_t flags ){
return (*m_method_ServiceBrowserNew)(interface,protocol,type,domain,flags);

}
DBus::Path org_freedesktop_Avahi_Server::ServiceResolverNew(int32_t interface, int32_t protocol, std::string name, std::string type, std::string domain, int32_t aprotocol, uint32_t flags ){
return (*m_method_ServiceResolverNew)(interface,protocol,name,type,domain,aprotocol,flags);

}
DBus::Path org_freedesktop_Avahi_Server::HostNameResolverNew(int32_t interface, int32_t protocol, std::string name, int32_t aprotocol, uint32_t flags ){
return (*m_method_HostNameResolverNew)(interface,protocol,name,aprotocol,flags);

}
DBus::Path org_freedesktop_Avahi_Server::AddressResolverNew(int32_t interface, int32_t protocol, std::string address, uint32_t flags ){
return (*m_method_AddressResolverNew)(interface,protocol,address,flags);

}
DBus::Path org_freedesktop_Avahi_Server::RecordBrowserNew(int32_t interface, int32_t protocol, std::string name, uint16_t clazz, uint16_t type, uint32_t flags ){
return (*m_method_RecordBrowserNew)(interface,protocol,name,clazz,type,flags);

}
