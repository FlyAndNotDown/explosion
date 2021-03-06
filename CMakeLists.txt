cmake_minimum_required(VERSION 3.15)
project(Explosion)

set(CMAKE_CXX_STANDARD 17)

include(cmake/Explosion.cmake)

option(EXP_VERBOSE_INFO "verbose info for cmake debug" ON)
option(EXP_BUILD_TEST "build test" ON)
option(EXP_BUILD_SAMPLES "build samples" ON)

if (NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "please set $CMAKE_BUILD_TYPE on configuring cmake")
endif()

get_property(GENERATOR_IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if (${GENERATOR_IS_MULTI_CONFIG})
    set(CMAKE_CONFIGURATION_TYPES "${CMAKE_BUILD_TYPE}" CACHE STRING "cmake configuration types for multi config generator" FORCE)
    message("-- generator is multi config, but just using $CMAKE_BUILD_TYPE as the only one config, current config is ${CMAKE_CONFIGURATION_TYPES}")
else()
    message("-- generator is single config, using $CMAKE_BUILD_TYPE to build, current build type is ${CMAKE_BUILD_TYPE}")
endif()

if (NOT EXP_3RD_ROOT)
    message(FATAL_ERROR "please download the Explosion3rdParty package and define $EXP_3RD_ROOT, see https://github.com/ExplosionEngine/Explosion3rdParty/releases")
endif()

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(GEN_PRE_DIR ${CMAKE_BINARY_DIR}/Gen/ApiHeader)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
if (${CMAKE_GENERATOR} MATCHES "^Visual Studio .*$")
    set(PROJECT_RUNTIME_DIRECTORY ${CMAKE_BINARY_DIR}/Bin/${CMAKE_BUILD_TYPE})
else()
    set(PROJECT_RUNTIME_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
endif()

include(GenerateExportHeader)
# TODO using api define in each module
# set(CMAKE_CXX_VISIBILITY_PRESET hidden)
# set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)

include_directories(${GEN_PRE_DIR})

if (${EXP_BUILD_TEST})
    message("-- enable testing")
    enable_testing()
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_definitions(-DEXPLOSION_DEBUG)
endif()

add_subdirectory(${EXP_3RD_ROOT} 3rd)
add_subdirectory(Common)
add_subdirectory(Engine)
add_subdirectory(Modules)
add_subdirectory(Assets)
