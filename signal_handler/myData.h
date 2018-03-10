#ifndef MYDATA_H
#define MYDATA_H

#include <string>
#include <vector>

typedef struct _myData
{
  static constexpr const char* DBUS_SIGNATURE = "(yus)";
  uint8_t        octet;
  uint32_t       dword;
  std::string    deviceName;
} myData_t;

//------------------------------------------------------------------------------
// Return dbus custom data description. This has to live in the DBus namespace
// in order to work with libdbus-cxx.
//------------------------------------------------------------------------------

namespace DBus
{
    inline std::string signature(struct _myData) {return _myData::DBUS_SIGNATURE;}
}

// Required to be here I think 
#include <dbus-cxx.h>

//------------------------------------------------------------------------------
// These iterators insert/extract a myData struct into/from a DBus::Message.
//------------------------------------------------------------------------------

DBus::MessageIterator &operator>>(DBus::MessageIterator& i, struct _myData& f);
DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct _myData& f);

#endif // MYDATA_H
