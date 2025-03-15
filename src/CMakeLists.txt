add_library(words_repository words_repository.cc)
target_include_directories(words_repository PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

add_executable(words_app words_app.cc)
target_include_directories(words_app PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

target_link_libraries(words_app words_repository)