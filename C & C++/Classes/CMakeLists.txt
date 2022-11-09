cmake_minimum_required(VERSION 3.22)
project(HackerRank)

set(CMAKE_CXX_STANDARD 20)

add_executable(box_it "box_it.cpp")

add_executable(class "class.cpp")

add_executable(classes_objects "classes_objects.cpp")

add_executable(exceptional_server "exceptional_server.cpp")

add_executable(inherited_code "inherited_code.cpp")

add_executable(polymorphism "polymorphism.cpp")

add_executable(structs "structs.cpp")

add_executable(virtual_functions "VirtualFunctions/main.cpp"
"VirtualFunctions/Person.h" "VirtualFunctions/Person.cpp"
"VirtualFunctions/Professor.h" "VirtualFunctions/Professor.cpp" 
"VirtualFunctions/Student.h" "VirtualFunctions/Student.cpp")