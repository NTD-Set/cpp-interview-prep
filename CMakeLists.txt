cmake_minimum_required(VERSION 3.15)
project(cpp_interview)

set(CMAKE_CXX_STANDARD 17)

# Helper macro to add all .cpp files in a folder as executables
macro(add_folder_executables folder_name)
    file(GLOB_RECURSE files "${folder_name}/*.cpp")
    foreach(file ${files})
        # Extract just the filename without extension
        get_filename_component(exec_name ${file} NAME_WE)
        # Create a unique target name using folder + filename
        string(REPLACE "/" "_" target_name "${folder_name}_${exec_name}")
        add_executable(${target_name} ${file})
    endforeach()
endmacro()

# Add executables for each week
add_folder_executables(cpp_core)
