cmake_minimum_required(VERSION 3.0.0)
project(mainProject VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
  main_test.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(tests
                include
)
add_executable(MyExec
  include/Solution.h
  main.cpp
)