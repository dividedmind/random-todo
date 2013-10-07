project(random-todo)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
enable_testing()

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(random-todo_SRCS random-todo.cpp main.cpp)
qt4_automoc(${random-todo_SRCS})
add_executable(random-todo ${random-todo_SRCS})
target_link_libraries(random-todo ${QT_QTCORE_LIBRARY})

add_subdirectory(tests)
