cmake_minimum_required(VERSION 3.23)
project(Calculator)

set(CMAKE_CXX_STANDARD 23)

add_executable(Calculator main.cpp src/Calculator.cpp src/Calculator.h src/parser/Parser.cpp src/parser/Parser.h src/parser/Lexer.cpp src/parser/Lexer.h src/operations/LoaderDLL.cpp src/operations/LoaderDLL.h)