#include "org_freedesktop_Avahi_Server2.h"

org_freedesktop_Avahi_Server2::org_freedesktop_Avahi_Server2(std::string name ) : DBus::InterfaceProxy( name ){
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
m_method_DomainBrowserPrepare = this->create_method<DBus::Path(int32_t,int32_t,std::string,int32_t,uint32_t)>("DomainBrowserPrepare");
m_method_ServiceTypeBrowserPrepare = this->create_method<DBus::Path(int32_t,int32_t,std::string,uint32_t)>("ServiceTypeBrowserPrepare");
m_method_ServiceBrowserPrepare = this->create_method<DBus::Path(int32_t,int32_t,std::string,std::string,uint32_t)>("ServiceBrowserPrepare");
m_method_ServiceResolverPrepare = this->create_method<DBus::Path(int32_t,int32_t,std::string,std::string,std::string,int32_t,uint32_t)>("ServiceResolverPrepare");
m_method_HostNameResolverPrepare = this->create_method<DBus::Path(int32_t,int32_t,std::string,int32_t,uint32_t)>("HostNameResolverPrepare");
m_method_AddressResolverPrepare = this->create_method<DBus::Path(int32_t,int32_t,std::string,uint32_t)>("AddressResolverPrepare");
m_method_RecordBrowserPrepare = this->create_method<DBus::Path(int32_t,int32_t,std::string,uint16_t,uint16_t,uint32_t)>("RecordBrowserPrepare");

}
std::shared_ptr<org_freedesktop_Avahi_Server2> org_freedesktop_Avahi_Server2::create(std::string name ){
return std::shared_ptr<org_freedesktop_Avahi_Server2>( new org_freedesktop_Avahi_Server2( name ));

}
std::string org_freedesktop_Avahi_Server2::GetVersionString( ){
return (*m_method_GetVersionString)();

}
uint32_t org_freedesktop_Avahi_Server2::GetAPIVersion( ){
return (*m_method_GetAPIVersion)();

}
std::string org_freedesktop_Avahi_Server2::GetHostName( ){
return (*m_method_GetHostName)();

}
void org_freedesktop_Avahi_Server2::SetHostName(std::string name ){
(*m_method_SetHostName)(name);

}
std::string org_freedesktop_Avahi_Server2::GetHostNameFqdn( ){
return (*m_method_GetHostNameFqdn)();

}
std::string org_freedesktop_Avahi_Server2::GetDomainName( ){
return (*m_method_GetDomainName)();

}
bool org_freedesktop_Avahi_Server2::IsNSSSupportAvailable( ){
return (*m_method_IsNSSSupportAvailable)();

}
int32_t org_freedesktop_Avahi_Server2::GetState( ){
return (*m_method_GetState)();

}
uint32_t org_freedesktop_Avahi_Server2::GetLocalServiceCookie( ){
return (*m_method_GetLocalServiceCookie)();

}
std::string org_freedesktop_Avahi_Server2::GetAlternativeHostName(std::string name ){
return (*m_method_GetAlternativeHostName)(name);

}
std::string org_freedesktop_Avahi_Server2::GetAlternativeServiceName(std::string name ){
return (*m_method_GetAlternativeServiceName)(name);

}
std::string org_freedesktop_Avahi_Server2::GetNetworkInterfaceNameByIndex(int32_t index ){
return (*m_method_GetNetworkInterfaceNameByIndex)(index);

}
int32_t org_freedesktop_Avahi_Server2::GetNetworkInterfaceIndexByName(std::string name ){
return (*m_method_GetNetworkInterfaceIndexByName)(name);

}
uint32_t org_freedesktop_Avahi_Server2::ResolveHostName(int32_t interface, int32_t protocol, std::string name, int32_t aprotocol, uint32_t flags ){
return (*m_method_ResolveHostName)(interface,protocol,name,aprotocol,flags);

}
uint32_t org_freedesktop_Avahi_Server2::ResolveAddress(int32_t interface, int32_t protocol, std::string address, uint32_t flags ){
return (*m_method_ResolveAddress)(interface,protocol,address,flags);

}
uint32_t org_freedesktop_Avahi_Server2::ResolveService(int32_t interface, int32_t protocol, std::string name, std::string type, std::string domain, int32_t aprotocol, uint32_t flags ){
return (*m_method_ResolveService)(interface,protocol,name,type,domain,aprotocol,flags);

}
DBus::Path org_freedesktop_Avahi_Server2::EntryGroupNew( ){
return (*m_method_EntryGroupNew)();

}
DBus::Path org_freedesktop_Avahi_Server2::DomainBrowserPrepare(int32_t interface, int32_t protocol, std::string domain, int32_t btype, uint32_t flags ){
return (*m_method_DomainBrowserPrepare)(interface,protocol,domain,btype,flags);

}
DBus::Path org_freedesktop_Avahi_Server2::ServiceTypeBrowserPrepare(int32_t interface, int32_t protocol, std::string domain, uint32_t flags ){
return (*m_method_ServiceTypeBrowserPrepare)(interface,protocol,domain,flags);

}
DBus::Path org_freedesktop_Avahi_Server2::ServiceBrowserPrepare(int32_t interface, int32_t protocol, std::string type, std::string domain, uint32_t flags ){
return (*m_method_ServiceBrowserPrepare)(interface,protocol,type,domain,flags);

}
DBus::Path org_freedesktop_Avahi_Server2::ServiceResolverPrepare(int32_t interface, int32_t protocol, std::string name, std::string type, std::string domain, int32_t aprotocol, uint32_t flags ){
return (*m_method_ServiceResolverPrepare)(interface,protocol,name,type,domain,aprotocol,flags);

}
DBus::Path org_freedesktop_Avahi_Server2::HostNameResolverPrepare(int32_t interface, int32_t protocol, std::string name, int32_t aprotocol, uint32_t flags ){
return (*m_method_HostNameResolverPrepare)(interface,protocol,name,aprotocol,flags);

}
DBus::Path org_freedesktop_Avahi_Server2::AddressResolverPrepare(int32_t interface, int32_t protocol, std::string address, uint32_t flags ){
return (*m_method_AddressResolverPrepare)(interface,protocol,address,flags);

}
DBus::Path org_freedesktop_Avahi_Server2::RecordBrowserPrepare(int32_t interface, int32_t protocol, std::string name, uint16_t clazz, uint16_t type, uint32_t flags ){
return (*m_method_RecordBrowserPrepare)(interface,protocol,name,clazz,type,flags);

}
