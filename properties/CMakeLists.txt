cmake_minimum_required(VERSION 3.5)
project(DBusCxx-properties)

include(FindPkgConfig)

pkg_check_modules( dbus-cxx REQUIRED dbus-cxx-2.0 )

add_executable( properties properties.cpp )

set_property( TARGET properties PROPERTY CXX_STANDARD 17 )
target_include_directories( properties PUBLIC ${dbus-cxx_INCLUDE_DIRS} )
target_link_libraries( properties ${dbus-cxx_LDFLAGS} )
