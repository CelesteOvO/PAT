cmake_minimum_required(VERSION 3.25)
project(PAT)

set(CMAKE_CXX_STANDARD 17)

set(SRCS
        test1
        )

foreach(SRC ${SRCS})
    add_executable(${SRC}
            ${SRC}.cpp
            test2.cpp test3.cpp "test 4.cpp")
endforeach()
