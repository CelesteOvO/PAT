cmake_minimum_required(VERSION 3.25)
project(PAT)

set(CMAKE_CXX_STANDARD 17)

set(SRCS
        test1
        test2
        test3
        test4
        test5
        test6
        )

foreach(SRC ${SRCS})
    add_executable(${SRC}
            ${SRC}.cpp
            )
endforeach()
