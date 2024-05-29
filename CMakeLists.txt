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


enable_testing()



add_subdirectory(googletest)
add_subdirectory(Queuew)
add_subdirectory(stack)
add_subdirectory(tests)

set(HEADER_SET
    Queuew/queue.h
    stack/stack.h
)

set(Sources
    Queuew/queue.cpp
    stack/stack.cpp
)

add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})




target_include_directories(${PROJECT_NAME} PUBLIC QueuewLib StackLib)
