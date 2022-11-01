cmake_minimum_required(VERSION 3.23)
project(Calculator)

set(CMAKE_CXX_STANDARD 23)

#add_library(Max SHARED src/operations/Max.cpp)
#add_library(Min SHARED src/operations/Min.cpp)
#add_library(Pow SHARED src/operations/Pow.cpp)
#add_library(Sin SHARED src/operations/Sin.cpp)
#add_library(Cos SHARED src/operations/Cos.cpp)
#add_library(Tan SHARED src/operations/Tan.cpp)
#add_library(Abs SHARED src/operations/Abs.cpp)
#add_library(Exp SHARED src/operations/Exp.cpp)
#add_library(Log SHARED src/operations/Log.cpp)
#add_library(Sqrt SHARED src/operations/Sqrt.cpp)

add_executable(Calculator main.cpp src/Calculator.cpp src/Calculator.h src/parser/Parser.cpp src/parser/Parser.h src/parser/Lexer.cpp src/parser/Lexer.h src/LoaderDLL.cpp src/LoaderDLL.h)
