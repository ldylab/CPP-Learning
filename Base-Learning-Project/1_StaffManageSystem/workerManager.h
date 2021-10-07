#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
using namespace std;

#define FILENAME "empFile.txt"

// 类可以在h文件中构造
class WorkerManager
{
public:
    // 构造函数
    WorkerManager();

    // 展示菜单
    void Show_Meun();

    // 退出功能
    void exitSystem();

    // 析构函数
    ~WorkerManager();

    // 增加职工
    void Add_Emp();

    // 保存文件
    void save();

    //统计人数
    int get_EmpNum();

    //初始化员工数组
    void init_Emp();

    //显示职工
    void Show_Emp();

    //删除职工
    void Del_Emp();

    //判断员工是否存在
    int IsExist(int id);

    //修改员工
    void Mod_Emp();

    //查找职工
    void Find_Emp();

    //排序职工
    void Sort_Emp();

    //清空文件
    void Clean_File();

public: // 成员属性
    int m_EmpNum;

    Worker ** m_EmpArray;

    //标志文件是否为空
    bool m_FileIsEmpty;
};