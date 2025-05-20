cmake_minimum_required(VERSION 3.31)
project (Graph LANGUAGES CXX VERSION 1.0 DESCRIPTION "Библиотека для работы с графами")

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
        main.cpp
        src/IGraph.cpp)

set(HEADERS
        include/IGraph.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
