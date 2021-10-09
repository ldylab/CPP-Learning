#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

// 测试多态
void test()
{
    Worker * worker = NULL; // 创建一个空指针去接受子类的构建

    // 这个有问题，在父类由virtual创建的类型中，virtual并没有明确的定义，所以是并不能直接删除其创建的指针+new，要保证virtual有了明确的定义才可以删除

    worker = new Employee(1, "张三", 1); // new class 创建出来的是类的首地址，后面可以采用->结构去访问其中的value和func
    worker->showInfo(); // 访问其中的函数
    cout << worker->m_Name << endl; // 访问其中的变量
    delete worker; // new之后需要删除，new是创建在堆区域内 这样删除好像是有问题的

}

int main()
{
    WorkerManager wm; // 类创建实例

    wm.Show_Meun();

    int choice = 0;
    cout << "输入您要选择的功能： " << endl;
    cin >> choice;
    while(choice > 7 || choice < 0)
    {
        cout << "输入有误，请重新输入： " << endl;
        cin >> choice;
    }

    switch (choice)
    {
        case 0:
            wm.Sys_Esc();
            break;

        case 1:
            test();
            // 添加职工信息
            break;

        case 2:
            // 显示职工信息
            break;

        case 3:
            // 删除离职职工信息
            break;

        case 4:
            // 修改职工信息
            break;

        case 5:
            //查找职工信息
            break;

        case 6:
            //按照编号排序
            break;

        case 7:
            //清空所有文档
            break;
    }


    return 0;
}