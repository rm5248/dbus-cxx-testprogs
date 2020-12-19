#include "some_interfaceInterface.h"

some_interfaceInterface::some_interfaceInterface(std::string name, some_interface* adaptee ) : DBus::Interface( name ){
this->create_method<std::map<std::string,std::string>(std::vector<std::string>)>("some_method", sigc::mem_fun( *adaptee, &some_interface::some_method));

}
std::shared_ptr<some_interfaceInterface> some_interfaceInterface::create(std::string name, some_interface* adaptee ){
return std::shared_ptr<some_interfaceInterface>( new some_interfaceInterface( name, adaptee ) );

}
