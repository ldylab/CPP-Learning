cmake_minimum_required(VERSION 3.20)
project(1_StaffManageSystemIndenpently)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_StaffManageSystemIndenpently main.cpp workerManager.cpp workerManager.h worker.cpp worker.h employee.cpp employee.h boss.cpp boss.h manager.cpp manager.h)
