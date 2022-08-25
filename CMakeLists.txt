cmake_minimum_required(VERSION 3.17)
project(FHE)

#include_directories(/usr/local/Cellar/gmp/6.2.1/include/gmp.h)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_C_FLAGS "-lgmp")
#target_link_libraries(FHE "usr/local/lib/libgmp.a")

add_executable(FHE main.cpp)

include_directories("/usr/local/include")
target_link_libraries(FHE "/usr/local/lib/libgmpxx.a")
target_link_libraries(FHE "/usr/local/lib/libgmp.a")