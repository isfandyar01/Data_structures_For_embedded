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
    Queuew/queue.hpp
    stack/stack.hpp
)

set(Sources
    Queuew/queue.hpp
    stack/stack.hpp
)

add_library(${PROJECT_NAME} STATIC ${Sources} ${HEADER_SET})




target_include_directories(${PROJECT_NAME} PUBLIC QueuewLib StackLib)
# target_include_directories(q_test PUBLIC "${PROJECT_SOURCE_DIR}/tests")