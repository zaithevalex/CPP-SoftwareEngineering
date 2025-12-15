cmake_minimum_required(VERSION 3.29)
project(tasks)

set(CMAKE_CXX_STANDARD 23)

add_executable(tasks 02-02/main.cpp
        02-03/main.cpp
        02-06/main.cpp
        02-08/main.cpp
        02-07/main.cpp)

# Note: In a real project, you'd likely want separate targets or to comment out old main.cpp files
# as multiple main functions will conflict if linked into one executable.
# However, based on the existing file, it seems like just a list of source files.
# If you want to build new tasks, you might want to create separate targets or 
# just be aware that "add_executable(tasks ...)" with multiple mains is invalid in C++.
# I will leave the file as is to match the user's setup, but typically you run one at a time.
