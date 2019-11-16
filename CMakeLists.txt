cmake_minimum_required(VERSION 3.13)
project(leetcode)

set(GOOGLETEST_VERSION 1.9.0)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(
        external/googletest/googletest
)

include_directories(
        include
        external/googletest/googletest/include
)

#add_executable(test_main  tests/IntersectionNode_unittest.cpp IntersectionofTwoLinkedLists/IntersectionofTwoLinkedLists.cpp external/googletest/googletest)
#target_link_libraries(test_main gtest_main)
add_executable(island NumofIslands/NumofIslands.cpp)
target_link_libraries(island)