cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(httpserver)
add_executable(${PROJECT_NAME}
  src/main.cpp
  src/utils.cpp
  src/path.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)

# target_include_directories(${PROJECT_NAME} PRIVATE
#   ${CMAKE_SOURCE_DIR}/include
#   ${CMAKE_SOURCE_DIR}/external/fmt/include
# )

# target_link_libraries(${PROJECT_NAME} PRIVATE
#   ${CMAKE_SOURCE_DIR}/external/fmt/build/libfmt.a
# )
