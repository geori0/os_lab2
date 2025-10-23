cmake_minimum_required(VERSION 3.10)
project(OS_Lab2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message("Build for Linux")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")
endif ()

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  message("Build for Windows")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /WX /fsanitize=address /Zi")
endif ()

add_library(search_lib src/search.cpp)
target_include_directories(search_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(generate_lib src/generate_str.cpp)
target_include_directories(generate_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(os_lib src/os_linux.cpp)
target_include_directories(os_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main src/main.cpp)


target_link_libraries(main PRIVATE os_lib)
target_link_libraries(main PRIVATE generate_lib)
target_link_libraries(main PRIVATE search_lib)