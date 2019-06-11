cmake_minimum_required(VERSION 3.10)
project(vcube C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(vcube
        cisj.c
        cisj.h
        failure_detector.c
        failure_detector.h
        rand.c
        smpl.c
        smpl.h
        vcube.c
        vcube.h logger.c logger.h node.h best_effort.c best_effort.h broadcast.c broadcast.h)
