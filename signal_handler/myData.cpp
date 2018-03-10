#include "myData.h"

#include <dbus-cxx/enums.h>

DBus::MessageIterator &operator>>(DBus::MessageIterator& i, struct _myData& f)
{
  DBus::MessageIterator subiter = i.recurse();
  subiter >> f.octet;
  subiter >> f.dword;
  subiter >> f.deviceName;

  return i;
}

DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct _myData& f)
{
  // Normally, the second argument to open_container is the internal signature,
  // but it is not used if it is a struct
  i.open_container( DBus::CONTAINER_STRUCT, "" );
  i.sub_iterator()->append((uint8_t)f.octet);
  i.sub_iterator()->append((uint32_t)f.dword);
  i.sub_iterator()->append((std::string)f.deviceName);
  i.close_container();

  return i;
}
