project(akorandom)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)
find_package(KdepimLibs REQUIRED)
enable_testing()


include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(akorandom_SRCS akorandom.cpp main.cpp)
qt4_automoc(${akorandom_SRCS})
add_executable(akorandom ${akorandom_SRCS})
target_link_libraries(akorandom ${QT_QTCORE_LIBRARY} ${KDEPIMLIBS_AKONADI_LIBS} ${KDEPIMLIBS_KCALCORE_LIBS} ${KDEPIMLIBS_KABC_LIBS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fexceptions")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

add_subdirectory(tests)
