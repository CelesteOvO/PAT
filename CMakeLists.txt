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
        test7
        test8
        test9
        test10
        test11
        test12
        test13
        )

foreach(SRC ${SRCS})
    add_executable(${SRC}
            ${SRC}.cpp )
endforeach()
