cmake_minimum_required(VERSION 3.5)
project(DBusCxx-adapter-test)

include(FindPkgConfig)

pkg_check_modules( dbus-cxx REQUIRED dbus-cxx-2.0 )

add_executable( compile-test compile-test.cpp  some_interface.cpp some_interfaceInterface.cpp some_nameAdapter.cpp )


set_property( TARGET compile-test PROPERTY CXX_STANDARD 17 )
target_include_directories( compile-test PUBLIC ${dbus-cxx_INCLUDE_DIRS} )
target_link_libraries( compile-test ${dbus-cxx_LDFLAGS} )
