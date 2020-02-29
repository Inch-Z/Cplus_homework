#include <iostream>
using namespace std;
int setRate(int t)
{
    int rate;
    switch (t)
    {
    case 1:
        rate = 100;
        break;
    case 2:
        rate = 80;
        break;
    case 3:
        rate = 60;
        break;
    case 4:
        rate = 40;
        break;
    default:
        break;
    }
    return rate;
}
double CalSalary(int t, double hours)
{
    int rate = setRate(t);
    int Salary = rate * hours;
    return Salary;
}

int main()
{
    double hours;
    double Salary;
    int t;
    cout << "请输入姓名：";
    char name[10];
    cin >> name;
    cout << "请输入职称：" << endl
         << "教授=1，副教授=2，讲师=3，助教=4" << endl;
    cin >> t;
    cout << "请输入授课时数：" << endl;
    cin >> hours;
    Salary = CalSalary(t, hours);
    cout << name << endl;
    cout << "职称：";
    switch (t)
    {
    case 1:
        cout << "教授";
        break;
    case 2:
        cout << "副教授";
        break;
    case 3:
        cout << "讲师";
        break;
    case 4:
        cout << "助教";
        break;
    default:
        break;
    }
    cout << endl
         << "授课时数：" << hours << "小时" << endl
         << "工资为：" << Salary << "元" << endl;
    return 0;
}