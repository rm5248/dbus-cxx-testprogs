cmake_minimum_required(VERSION 3.10)

project(complex-data-resolve1)

set(CMAKE_CXX_STANDARD 17)

include( FindPkgConfig )
pkg_check_modules( sigc REQUIRED sigc++-3.0 )
find_package(dbus-cxx REQUIRED)
find_package(Threads)

add_executable(complex-data main.cpp)
target_link_libraries(complex-data dbus-cxx::dbus-cxx Threads::Threads ${sigc_LIBRARIES})
target_include_directories(complex-data PRIVATE ${sigc_INCLUDE_DIRS})
