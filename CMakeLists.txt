cmake_minimum_required(VERSION 3.22)


project(
    Embedded_data_Structures
    VERSION 1.0.0
    LANGUAGES C CXX)




set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# Add the queue source and header files


option(ENABLE_TESTING "Enable a Unit Testing Build" ON)

add_subdirectory(Queuew)
add_subdirectory(stack)
add_subdirectory(tests)


include(FetchContent)


if(ENABLE_TESTING)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v3.5.3
        GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif()

if(ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()