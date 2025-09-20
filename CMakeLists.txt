cmake_minimum_required(VERSION 3.16)
project(UDIS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(udis
	src/main.cpp
	src/spacecraft.cpp
)

target_include_directories(udis PRIVATE ${EIGEN3_INCLUDE_DIR})
target_link_libraries(udis PRIVATE Eigen3::Eigen)
