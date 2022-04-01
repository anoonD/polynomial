cmake_minimum_required(VERSION 3.00)
project(Polynomial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 20)
set(source_dir src)

find_package(fmt)
add_executable( main
                src/main.cpp
                src/Expression.cpp
                src/Expression.h
                src/Term.cpp
                src/Term.h 
                )

target_link_libraries(main fmt::fmt)
