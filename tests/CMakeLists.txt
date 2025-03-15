add_executable(words_repository_test words_repository_test.cc)

target_include_directories(words_repository_test PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
target_include_directories(words_repository_test PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_directories(words_repository_test PRIVATE ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(words_repository_test words_repository gtest gtest_main)

# add_test(NAME words_repository_test COMMAND words_repository_test)
# 下面两行意味着可以用ctest运行(不同于上面这行，可以列出每个用例的执行情况），并在左边TEST EXPLORER列出
include(GoogleTest)
gtest_discover_tests(words_repository_test)