#ifndef SOME_INTERFACEINTERFACE_H
#define SOME_INTERFACEINTERFACE_H

#include <dbus-cxx.h>
#include <map>
#include <memory>
#include <stdint.h>
#include <string>
#include <vector>
#include "some_interface.h"
class some_interfaceInterface
 : public DBus::Interface {
private:
some_interfaceInterface(std::string name, some_interface* adaptee );
public:
    static std::shared_ptr<some_interfaceInterface> create(std::string name, some_interface* adaptee );
};
#endif /* SOME_INTERFACEINTERFACE_H */
