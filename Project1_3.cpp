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
    cout << "������������";
    char name[10];
    cin >> name;
    cout << "������ְ�ƣ�" << endl
         << "����=1��������=2����ʦ=3������=4" << endl;
    cin >> t;
    cout << "�������ڿ�ʱ����" << endl;
    cin >> hours;
    Salary = CalSalary(t, hours);
    cout << name << endl;
    cout << "ְ�ƣ�";
    switch (t)
    {
    case 1:
        cout << "����";
        break;
    case 2:
        cout << "������";
        break;
    case 3:
        cout << "��ʦ";
        break;
    case 4:
        cout << "����";
        break;
    default:
        break;
    }
    cout << endl
         << "�ڿ�ʱ����" << hours << "Сʱ" << endl
         << "����Ϊ��" << Salary << "Ԫ" << endl;
    return 0;
}