cmake_minimum_required(VERSION 3.17)
project(a45)

set(CMAKE_CXX_STANDARD 20)

add_executable(a45 main.cpp
        Domain/DynamicArray.h
        Domain/Movie.h
        Domain/Movie.cpp
        Repository/RepositoryMovies.h
        Repository/RepositoryMovies.cpp
        Service/ServiceMovies.h
        Service/ServiceMovies.cpp
        Validators/Validator.h
        Validators/Validator.cpp
        UI/Console.h
        UI/Console.cpp
        Tests/TestAll.h
        Tests/TestAll.cpp
        Tests/TestDomain.h
        Tests/TestDomain.cpp
        Tests/TestService.h
        Tests/TestService.cpp
        Tests/TestRepository.cpp
        Tests/TestRepository.h
        Tests/TestDA.h
        Tests/TestDA.cpp)