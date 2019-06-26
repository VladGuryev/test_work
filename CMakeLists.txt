cmake_minimum_required(VERSION 2.8)

project(Guryev_Vlad)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(vlad_guryev_test_work main.cpp)	

set(SOURCE main.cpp)
set(HEADER IDictionary.h Dictionary.h INotFoundException.h NotFoundException.h TestRunner.h Tests.h)