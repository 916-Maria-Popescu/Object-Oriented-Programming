cmake_minimum_required(VERSION 3.17)
project(t1_916_Maria_Popescu_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(UI)

add_executable(t1_916_Maria_Popescu_1
        main.cpp
        Domain/Gene.cpp
        Domain/Gene.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        UI/Console.cpp
        UI/Console.h)
