find_package(GTest REQUIRED)

add_executable(main_test main_test.cpp)

target_link_libraries(main_test
 PRIVATE
  GTest::GTest
)
