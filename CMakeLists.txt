cmake_minimum_required(VERSION 3.10)
project(Trabalho)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Trabalho
    dominios.cc
    dominios.h
    entidades.cc
    entidades.h
    testes.h
        teste-dominios.cc
        teste-dominios.h
        teste-entidades.cc
        teste-entidades.h
        apresentacao.cc
        apresentacao.h
        servicos.cc
        servicos.h
        interfaces.h
        main.cc)
