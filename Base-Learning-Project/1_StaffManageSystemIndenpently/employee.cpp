#include "employee.h"

// 其中的构造函数是没有变量类型
Employee::Employee(int id, string name, int dId)
{
    // 使用this就是能在访问在类下定义的变量
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// 其中的函数是有变量类型的
void Employee::showInfo()
{
    // 就是其中变量都给输出出来
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位职责：完成经理交给的任务" << endl;
}

// 对于其中职务更加深入了解
string Employee::getDeptName()
{
    return string("员工");
}
