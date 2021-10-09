#pragma once
#include<iostream>
#include<string>
using namespace std;

// 其中class的声明和变量的初始化是在.h文件中
class Worker
{
public:
    // 不需要重写构造函数和析构函数的
    virtual void showInfo() = 0; // 作为一个被继承的父类，最好就是采用virtual的方法

    // 获得岗位名称
    virtual string getDeptName() = 0;

    // 职工有几个编号需要自己构建
    int m_Id; // 职工编号
    string m_Name; // 职工姓名
    int m_DeptId; // 职工所在部门的名称编号
};