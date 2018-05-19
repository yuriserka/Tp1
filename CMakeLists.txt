cmake_minimum_required(VERSION 3.10)
project(Trabalho)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Trabalho
    auxiliares.h
    comandos.cc
    comandos.h
    controladores.cc
    controladores.h
    dominios.cc
    dominios.h
    entidades.cc
    entidades.h
    interfaces.h
    main.cc
    stubs.cc
    stubs.h
    teste-dominios.cc
    teste-dominios.h
    teste-entidades.cc
    teste-entidades.h
    testes.h
    )
