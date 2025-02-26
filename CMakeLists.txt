cmake_minimum_required(VERSION 3.30)
project(Library_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library_System main.cpp
        Book.cpp
        Book.h
        Library.cpp
        Library.h
        Person.cpp
        Person.h
        Member.cpp
        Member.h
        Transaction.cpp
        Transaction.h
        Start.h)
