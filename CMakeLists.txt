cmake_minimum_required(VERSION 3.22)

project(
    Embedded_data_Structures
    VERSION 1.0.0
    LANGUAGES C CXX)


set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# Add the queue source and header files


include(FetchContent)


FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.5.3
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(Catch2)


enable_testing()



include(CTest)
# add_subdirectory(googletest)
add_subdirectory(Queuew)
add_subdirectory(stack)
add_subdirectory(tests)


