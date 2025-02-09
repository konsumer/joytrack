FetchContent_Declare(tomlc99
  URL https://github.com/cktan/tomlc99/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(tomlc99)

add_library(tomlc99 ${tomlc99_SOURCE_DIR}/toml.c)
include_directories(${tomlc99_SOURCE_DIR})
