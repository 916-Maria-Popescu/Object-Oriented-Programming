cmake_minimum_required(VERSION 3.17)
project(a23_916_Maria_Popescu C)

set(CMAKE_C_STANDARD 11)

add_executable(a23_916_Maria_Popescu
        main.c
        Domain/Estate.c
        Domain/Estate.h
        Domain/DynamicArray.c
        Domain/DynamicArray.h
        Repository/EstateRepo.c
        Repository/EstateRepo.h
        UI/Console.c
        UI/Console.h
        Service/EstateService.c
        Service/EstateService.h
        Validators/Validator.c
        Validators/Validator.c
        Tests/Test.c
        Tests/Test.h
        Service/UndoRedo.c
        Service/UndoRedo.h
        )
