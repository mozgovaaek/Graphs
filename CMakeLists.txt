cmake_minimum_required(VERSION 3.31)
project (Graph LANGUAGES CXX VERSION 1.0 DESCRIPTION "Библиотека для работы с графами")

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
        src/Algorithms.cpp
        src/ArcGraph.cpp
        src/IGraph.cpp
        src/ListGraph.cpp
        src/MatrixGraph.cpp
        src/SetGraph.cpp
        )

set(HEADERS
        include/Algorithms.h
        include/ArcGraph.h
        include/IGraph.h
        include/ListGraph.h
        include/MatrixGraph.h
        include/SetGraph.h
        )

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
