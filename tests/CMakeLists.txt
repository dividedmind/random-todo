
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(random-todoTest_SRCS random-todoTest.cpp)
qt4_automoc(${random-todoTest_SRCS})
add_executable(random-todoTest ${random-todoTest_SRCS})
add_test(random-todoTest random-todoTest)
target_link_libraries(random-todoTest ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY})
