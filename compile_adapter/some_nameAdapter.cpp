#include "some_nameAdapter.h"

some_nameAdapter::some_nameAdapter(std::string path, std::shared_ptr<some_interfaceInterface> _some_interfaceInterface ) : DBus::Object( path ){
this->add_interface( _some_interfaceInterface);

}
std::shared_ptr<some_nameAdapter> some_nameAdapter::create(std::shared_ptr<DBus::Connection> connection, std::string path, std::shared_ptr<some_interfaceInterface> _some_interfaceInterface, DBus::ThreadForCalling calling_thread ){
std::shared_ptr<some_nameAdapter> adapter = std::shared_ptr<some_nameAdapter>( new some_nameAdapter(
path
, _some_interfaceInterface
) );
if( connection ){ 
  if( connection->register_object( adapter, calling_thread ) != DBus::RegistrationStatus::Success ){
    return std::shared_ptr<some_nameAdapter>();
  }
}
return adapter;

}
