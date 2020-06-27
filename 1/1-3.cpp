#include <iostream>
#include <string>
using namespace std;

int Num;

struct teacher
{
    string name;
    double rate;
    double salary;
    double hours;
    string title;
};

void setName(teacher teacher[])
{

    for (int i = 0; i < Num; i++)
    {
        cout << "请输入姓名、职称：";
        cin >> teacher[i].name >> teacher[i].title;
        cout << "该教师输入结束" << endl;
    }
}

void setRate(teacher teacher[])
{
    for (int i = 0; i < Num; i++)
    {
        if (teacher[i].title == "教授")
            teacher[i].rate = 100;
        else if (teacher[i].title == "副教授")
            teacher[i].rate = 80;
        else if (teacher[i].title == "讲师")
            teacher[i].rate = 60;
        else
            teacher[i].rate = 40;
    }
}

void setHours(teacher teacher[])
{
    for (int i = 0; i < Num; i++)
    {

        cout << "请输入" << teacher[i].name << "授课时数（h）:";
        cin >> teacher[i].hours;
        cout << endl;
    }
}

void setSalary(teacher teacher[])
{
    for (int i = 0; i < Num; i++)
    {
        teacher[i].salary = teacher[i].hours * teacher[i].rate;
    }
}

void Pr(teacher teacher[])
{
    for (int i = 0; i < Num; i++)
    {
        cout << teacher[i].name << "应发工资：" << teacher[i].salary << "元" << endl;
    }
}

int main()
{
    string _init;
    cout << "请输入教师数量：";
    cin >> Num;
    cout << endl;
    teacher teacher[Num];
    cout << "首次使用请输入“init”，否则输入任意字符。" << endl;
    cin >> _init;
    if (_init == "init")
    {
        setName(teacher);
        setRate(teacher);
    }
    setHours(teacher);
    setSalary(teacher);
    Pr(teacher);
    return 0;
}