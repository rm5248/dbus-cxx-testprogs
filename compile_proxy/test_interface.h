#ifndef TEST_INTERFACE_H
#define TEST_INTERFACE_H

#include <dbus-cxx.h>
#include <memory>
#include <stdint.h>
#include <string>
class test_interface
 : public DBus::InterfaceProxy {
protected:
test_interface(std::string name );
public:
    static std::shared_ptr<test_interface> create(std::string name = "test.interface" );
    void typesMethod(int32_t first, double second );
protected:
    std::shared_ptr<DBus::MethodProxy<void(int32_t,double)>>  m_method_typesMethod;
};
#endif /* TEST_INTERFACE_H */
