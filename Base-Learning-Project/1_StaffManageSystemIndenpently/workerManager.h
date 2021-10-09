#pragma once
#include <iostream>
using namespace std;

// 创建管理系统的类
class WorkerManager
{
public:
    // 构造函数，并保持先不修改
    WorkerManager();

    // 菜单显示函数
    void Show_Meun();

    // 退出系统函数
    void Sys_Esc();

    // 析构函数，并保持先不修改
    ~WorkerManager();
};