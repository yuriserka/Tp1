cmake_minimum_required(VERSION 3.10)
project(Trabalho)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Trabalho
    dominios.cc
    dominios.h
    entidades.cc
    entidades.h
    controladores.cc
    controladores.h
    stubs.cc
    stubs.h
    interfaces.h
    main.cc)
