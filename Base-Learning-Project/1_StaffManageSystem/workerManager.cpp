//
// Created by Henry on 2021/10/6.
//
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


// 构造函数
// 在每一次被调用时都会先运行一次WorkerManage，在其中先判断文件的存在形式，是否有文件，文件内是否是有格式完整文件格式
WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios:: in);

    // 文件不存在的情况
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl; // 测试输出
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close(); // 关闭文件
        return;
    }

    //文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空！ " << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum(); // 为函数
    cout << "职工个数为： " << num << endl;
    this->m_EmpNum = num; // 其中变量的写入

    //根据职工数创建数组
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    //初始化职工
    init_Emp();

    //测试代码
    for (int i = 0; i < m_EmpNum; i++)
    {
        cout << "职工号： " << this->m_EmpArray[i]->m_Id
             << " 职工姓名： " << this->m_EmpArray[i]->m_Name
             << " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
    }
}

// 菜单显示
void WorkerManager::Show_Meun()
{
    cout << "********************************************" << endl;
    cout << "***********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// 退出系统
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

// 增加职工
void WorkerManager::Add_Emp()
{
    cout << "请输入增加职工数量： " << endl;

    int addNum = 0;
    cin >> addNum;

    if(addNum > 0)
    {
        // 计算新空间大小
        int newSize = this->m_EmpNum + addNum;
        cout << "计算空间大小： " << newSize << endl;

        // 开辟新空间
        Worker ** newSpace = new Worker*[newSize];

        // 见源空间下的内容存放到新空间下
        if(this->m_EmpArray != NULL)
        {
            for(int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        for(int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i+1 << " 个新职工编号： " << endl;
            cin >> id;

            cout << "请输入第 " << i+1 << " 个新职工姓名： " << endl;
            cin >> name;

            cout << "请选择哥职工的岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;

            cin >> dSelect; // 输入选择

            Worker * worker = NULL;
            switch (dSelect)
            {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            cout << "第一次打印" << endl;
            newSpace[this->m_EmpNum + i] = worker;
        }

        //释放原有空间
        //delete[] this->m_EmpArray;

        //更改新空间的指向
        this->m_EmpArray = newSpace;

        /*************************************/
        for(int i = 0; i < m_EmpNum + 1; i ++)
        {
            cout << "Array的打印： " << this->m_EmpArray[i] << endl;
        }
        /*************************************/

        //更新新的个数
        this->m_EmpNum = newSize;

        //提示信息
        cout << "成功添加" << addNum << "名新职工！" << endl;

        this->m_FileIsEmpty = false; //更新属性
        this->save(); //保存到文件中
    }
    else
    {
        cout << "输入有误" << endl;
    }

    system("clear");
}

// 析构函数
WorkerManager:: ~WorkerManager()
{
    if(this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
    }
}

// 保存文件功能的实现
void WorkerManager:: save()
{
    ofstream ofs; // 相当于是创建了一个保存文件的类
    ofs.open(FILENAME, ios::out);

    cout << "个数 = " << this->m_EmpNum << endl;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        // 其中应该要注意下输入的类型大小，并且在中途丢失时应该也能要保存下来文件
        cout << "编号为： " << i << " ID: " << this->m_EmpArray[i]->m_Id << endl;
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();

    cout << "已经保存到文件中" << endl;
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios:: in);

    int id;
    string name;
    int dId;

    int num = 0;

    while(ifs >> id && ifs >> name && ifs >> dId)
    {
        //记录人数
        num++;
    }
    ifs.close();

    return num;
}

void WorkerManager:: init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    //应该就是取得最后的index
    while(ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker * worker = NULL;

        // 根据不同的部门Id创建不同对象
        if(dId == 1)
        {
            worker = new Employee(id, name, dId);
        }
        else if(dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }

        this->m_EmpArray[index] = worker;
        index++;
    }
}

void WorkerManager:: Show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或是记录为空" << endl;
    }
    else
    {
        for(int i = 0; i < m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("clear");
}

// 职工是否存在函数
int WorkerManager::IsExist(int id)
{
    int index = -1;

    for(int i = 0; i < this->m_EmpNum; i++)
    {
        if(this->m_EmpArray[i]->m_Id == id)
        {
            index = i;

            break;
        }
    }

    return index;
}

// 删除员工的实现
void WorkerManager::Del_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }

    else
    {
        cout << "请输入想要删除的职工号： " << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if(index != -1) // 说明有找到对象需要删除
        {
            for(int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;

            this->save();
            cout << "删除成功！" << endl;
        }

        else
        {
            cout << "删除失败，未找到该员工" << endl;
        }
    }

    system("clear");
}

// 修改员工函数实现
void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入修改员工的编号： " << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        cout << "RET = " << ret << endl;
        if(ret != -1)
        {
            // 在删除地址时会报错
            //delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = " ";
            int dSelect = 0;

            cout << "查到： " << id << "号职工，请输入新职工号：" << endl;
            cin >> newId;

            cout << "请输入新姓名：" << endl;
            cin >> newName;

            cout << "请输入岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect)
            {
                case 1:
                    worker = new Employee(newId, newName, dSelect);
                    break;
                case 2:
                    worker = new Manager(newId, newName, dSelect);
                    break;
                case 3:
                    worker = new Boss(newId, newName, dSelect);
                    break;
                default:
                    break;
            }

            this->m_EmpArray[ret] = worker;

            cout << "修改成功！" << endl;

            this->save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }
    system("clear");
}

void WorkerManager::Find_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入查找方式： " << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;

        if(select == 1)
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int ret = IsExist(id);
            if(ret != -1)
            {
                cout << "查找成功！该职工信息如下：" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if(select == 2)
        {
            string name;
            cout << "请输入查找的姓名" << endl;
            cin >> name;

            bool flag = false;
            for(int i = 0; i < m_EmpNum; i++)
            {
                if(m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功，职工编号为："
                    << m_EmpArray[i]->m_Id
                    << " 号的信息如下： " << endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag == false)
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }

    system("clear");
}

void WorkerManager::Sort_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("clear");
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

        int select = 0;
        cin >> select;

        for(int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i;
            for(int j = i + 1; j < m_EmpNum; j++)
            {
                if(select == 1)
                {
                    if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else  //降序
                {
                    if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax)
            {
                Worker * temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }
        cout << "排序成功,排序后结果为：" << endl;
        this->save();
        this->Show_Emp();
    }
}

//清空文件
void WorkerManager::Clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    //delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }

    system("pause");
    system("cls");
}
