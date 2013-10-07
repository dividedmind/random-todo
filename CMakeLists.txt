project(random-todo)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)
find_package(KdepimLibs REQUIRED)
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fexceptions")

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(random-todo_SRCS random-todo.cpp main.cpp)
qt4_automoc(${random-todo_SRCS})
add_executable(random-todo ${random-todo_SRCS})
target_link_libraries(random-todo ${QT_QTCORE_LIBRARY} ${KDEPIMLIBS_AKONADI_LIBS} ${KDEPIMLIBS_KCALCORE_LIBS})

add_subdirectory(tests)
