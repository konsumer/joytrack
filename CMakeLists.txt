cmake_minimum_required(VERSION 3.18)

project(joytrack
  DESCRIPTION "Joystick-driven musical tracker"
  HOMEPAGE_URL "https://github.com/konsumer/joytrack"
  VERSION 0.0.1
  LANGUAGES C
)

set(CMAKE_BUILD_TYPE Release)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
    set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
endif()

if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
    set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
endif()

if(POLICY CMP0169)
    cmake_policy(SET CMP0169 NEW)
    set(CMAKE_POLICY_DEFAULT_CMP0169 NEW)
endif()

# enable colors for ninja
set(CMAKE_COLOR_DIAGNOSTICS ON)

include(FetchContent)
# set(FETCHCONTENT_QUIET OFF)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(tomlc99 REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} tomlc99)
