# simple configuration for compiling the code
cmake_minimum_required(VERSION 3.10)

project(gt9xx_cfgen)

include_directories(inc)

add_executable(gt9xx_cfgen src/main.c src/crc.c src/parseopt.c)
