cmake_minimum_required(VERSION 3.20)
project(StaffManage)

set(CMAKE_CXX_STANDARD 14)

add_executable(StaffManage workerManager.h workerManager.cpp main.cpp worker.cpp worker.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)
