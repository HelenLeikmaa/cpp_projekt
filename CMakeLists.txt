cmake_minimum_required(VERSION 3.27)
project(cpp_projekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(CLI_ver1)
include_directories(CLI_ver1/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug)
include_directories(CLI_ver1/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug)
include_directories("Project files")
include_directories("Project files/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/kysitlus_Tartu2024_autogen")
include_directories("Project files/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/kysitlus_Tartu2024_autogen/include")

add_executable(cpp_projekt
        CLI_ver1/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/moc_mainwindow.cpp
        CLI_ver1/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/moc_predefs.h
        CLI_ver1/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/ui_mainwindow.h
        CLI_ver1/CLI.cpp
        CLI_ver1/DecHeader.h
        CLI_ver1/main.cpp
        CLI_ver1/mainwindow.cpp
        CLI_ver1/mainwindow.h
        CLI_ver1/question.cpp
        CLI_ver1/question.h
        "Project files/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/kysitlus_Tartu2024_autogen/EWIEGA46WW/moc_mainwindow.cpp"
        "Project files/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/kysitlus_Tartu2024_autogen/include/ui_mainwindow.h"
        "Project files/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/kysitlus_Tartu2024_autogen/moc_predefs.h"
        "Project files/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/kysitlus_Tartu2024_autogen/mocs_compilation.cpp"
        "Project files/gatheringResults.cpp"
        "Project files/gatheringResults.h"
        "Project files/main.cpp"
        "Project files/mainwindow.cpp"
        "Project files/mainwindow.h"
        "Project files/question.cpp"
        "Project files/question.h")
