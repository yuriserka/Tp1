cmake_minimum_required(VERSION 3.10)
project(Trabalho)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Trabalho
        dominios.cc
        dominios.h
        entidades.cc
        entidades.h
        main.cc
        testes.cc
        testes.h
        unit-test-dominios.cc
        unit-test-dominios.h
        unit-test-entidades.cc
        unit-test-entidades.h)
