# Engine bridge project
cmake_minimum_required(VERSION 3.17)
project(HPMSBase)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_SHARED_LIBRARY_PREFIX)
set(CMAKE_STATIC_LIBRARY_PREFIX)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(DYNALO_VERSION 1.0.3)
set(GLM_VERSION 0.9.9.8)

string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
if (BUILD_TYPE STREQUAL "debug")
    set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "Debug Postfix for lib, samples and tools")
    add_definitions(-DHPMS_BACKEND_DLL_POSTFIX="d")
else ()
    set(CMAKE_DEBUG_POSTFIX "" CACHE STRING "Debug Postfix for lib, samples and tools")
    add_definitions(-DHPMS_BACKEND_DLL_POSTFIX="")
endif ()


include(cmake/Shared.cmake)

# Other libraries setup.
install_from_repo(https://github.com/maddouri/dynalo.git DYNALO ${DYNALO_VERSION} FALSE /include/dynalo/)

install_from_repo(https://github.com/g-truc/glm.git GLM ${GLM_VERSION} TRUE /)

include_directories(include)

add_library(HPMSBase SHARED src/api/HPMSApiManager.cpp)