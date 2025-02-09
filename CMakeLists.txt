cmake_minimum_required(VERSION 3.18)

project(joytrack
  DESCRIPTION "Joystick-driven musical tracker"
  HOMEPAGE_URL "https://github.com/konsumer/joytrack"
  VERSION 0.0.1
  LANGUAGES C CXX
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

set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON CACHE BOOL "" FORCE)

include(FetchContent)
# set(FETCHCONTENT_QUIET OFF)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(tomlc99 REQUIRED)
find_package(glfw REQUIRED)
find_package(OpenGL REQUIRED)
find_package(imgui REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} tomlc99 glfw imgui)
