cmake_minimum_required(VERSION 3.20)

project(service LANGUAGES CXX)

#include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(conan.cmake)

conan_cmake_autodetect(settings)

conan_cmake_install(
    PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR}
    BUILD missing
    REMOTE conancenter
    SETTINGS ${settings}
)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

find_package(spdlog REQUIRED)
find_package(Boost REQUIRED COMPONENTS coroutine)

add_executable(service 
src/main.cpp
src/server.cpp
src/connection.cpp
)

# target requires C++17
target_compile_features(service PRIVATE cxx_std_17)

target_link_libraries(service
PRIVATE
spdlog::spdlog
Boost::coroutine
)