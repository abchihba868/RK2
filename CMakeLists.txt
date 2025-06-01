cmake_minimum_required(VERSION 3.10)
project(monster_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(monster_game STATIC
    src/slime.cpp
    src/goblin.cpp
    src/dragon.cpp
    src/monster_pool.cpp
)

add_executable(monster_game_main src/main.cpp)
target_link_libraries(monster_game_main monster_game)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    add_executable(slime_test tests/slime_test.cpp src/slime.cpp)
    target_link_libraries(slime_test monster_game GTest::gtest_main)
    add_test(NAME slime_test COMMAND slime_test)

    add_executable(goblin_test tests/goblin_test.cpp src/goblin.cpp)
    target_link_libraries(goblin_test monster_game GTest::gtest_main)
    add_test(NAME goblin_test COMMAND goblin_test)

    add_executable(dragon_test tests/dragon_test.cpp src/dragon.cpp)
    target_link_libraries(dragon_test monster_game GTest::gtest_main)
    add_test(NAME dragon_test COMMAND dragon_test)

    add_executable(monster_pool_test tests/monster_pool_test.cpp 
        src/slime.cpp src/goblin.cpp src/dragon.cpp src/monster_pool.cpp)
    target_link_libraries(monster_pool_test monster_game GTest::gtest_main)
    add_test(NAME monster_pool_test COMMAND monster_pool_test)
endif()

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
set(CPACK_PACKAGE_VERSION "1.0.0")
include(CPack)
