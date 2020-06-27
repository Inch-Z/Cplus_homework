//Student1浅拷贝，Student2深拷贝
#include <iostream>
#include <string.h>
using namespace std;
class Student1
{
public:
    Student1(char *sName = "noName", int sid = 999, char sex_ = 'F')
    {
        cout << "调用构造函数" << endl;
        strcpy(name, sName);
        sno = sid;
        sex = sex_;
    }
    Student1(Student1 &p)
    {
        cout << "调用浅拷贝" << endl;
        strcpy(name, p.name);
        sno = p.sno;
        sex = p.sex;
    }
    void printinfo()
    {
        cout << name << ' ' << sno << ' ' << sex << endl;
    }

private:
    int sno;
    char name[10];
    char sex; //F or M
};
class Student2
{
public:
    Student2(char *sName = "noName", int sid = 123, char _sex = 'M')
    {
        cout << "调用构造函数" << endl;
        name = new char[strlen(sName) + 1];
        if (name != 0)
        {
            strcpy(name, sName);
            sno = sid;
            sex = _sex;
        }
    }
    Student2(Student2 &p)
    {
        cout << "调用深拷贝" << endl;
        name = new char[strlen(p.name) + 1];
        if (name != 0)
        {
            strcpy(name, p.name);
            sno = p.sno;
            sex = p.sex;
        }
    }
    void printinfo()
    {
        cout << name << ' ' << sno << ' ' << sex << endl;
    }

    void getAddr()
    {
        cout << this->name << "Add:";
        cout << &(this->name) << endl;
    }
    int sno;
    char *name;
    char sex; //F or M
};
int main()
{
    Student1 zhang("张");
    zhang.printinfo();
    Student1 wang(zhang);
    wang.printinfo();
    Student2 zhang1("张");
    zhang1.printinfo();
    zhang1.getAddr();
    Student2 wang1(zhang1);
    wang1.printinfo();
    wang1.getAddr();
}
