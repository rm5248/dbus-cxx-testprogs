#include "test_interface.h"

test_interface::test_interface(std::string name ) : DBus::InterfaceProxy( name ){
m_method_typesMethod = this->create_method<void(int32_t,double)>("typesMethod");

}
std::shared_ptr<test_interface> test_interface::create(std::string name ){
return std::shared_ptr<test_interface>( new test_interface( name ));

}
void test_interface::typesMethod(int32_t first, double second ){
(*m_method_typesMethod)(first,second);

}
