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
        test14
        test15
        test16
        test17
        test18
        test19
        test20
        test21
        test22
        test23
        test24
        )

foreach(SRC ${SRCS})
    add_executable(${SRC}
            ${SRC}.cpp )
endforeach()
