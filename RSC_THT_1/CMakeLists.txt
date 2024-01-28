cmake_minimum_required(VERSION 3.5.0)
project(THT_RSC VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable(hello src/hello.cpp)
add_executable(cam src/cam.cpp)
add_executable(ball src/ball.cpp)

target_link_libraries( cam ${OpenCV_LIBS} )
target_link_libraries( ball ${OpenCV_LIBS} )


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)