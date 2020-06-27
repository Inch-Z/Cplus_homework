#include <iostream>
using namespace std;
#include <string.h>
class Employee //职工类
{
public:
    Employee(char *, char *); //构造函数
    ~Employee() {}            //析构函数
    virtual double pay() = 0;
    virtual void print() = 0;

protected:
    char name[20]; //姓名
    char id[20];   //工号
};
Employee::Employee(char *name, char *id)
{
    strcpy(this->name, name);
    strcpy(this->id, id);
}
class Manager : public Employee
{
public:
    Manager(char *name, char *id, double salary, double more) : Employee(name, id) { this->salary = salary; }
    ~Manager() {}
    double pay() { return salary + more; }
    void print() { cout << endl
                        << "name:" << name << "  ID:" << id << "  pay:" << pay() << endl; }

private:
    double salary;
    double more;
};
class Saleman : public Employee
{
public:
    Saleman(char *name, char *id, double salary, double profit) : Employee(name, id)
    {
        this->salary = salary;
        this->profit = profit;
    }
    ~Saleman() {}
    double pay() { return (salary + 0.1 * profit); }
    void print() { cout << endl
                        << "name:" << name << "  ID:" << id << "  pay:" << pay() << endl; }

private:
    double salary;
    double profit;
};
class Technician : public Employee
{
public:
    Technician(char *name, char *id, int hours, double wage) : Employee(name, id)
    {
        this->hours = hours;
        this->wage = wage;
    }
    ~Technician() {}
    double pay() { return hours * wage; }
    void print()
    {
        cout << endl
             << "name:" << name << "  ID:" << id << "  pay:" << pay() << endl;
    }

private:
    int hours;
    double wage;
};

int main()
{
    Manager manager("张三", "101", 9000, 123);
    Technician technician("李四", "112", 8 * 29, 30);
    Saleman saleman("王五", "999", 6000, 10000);
    saleman.print();
    manager.print();
    technician.print();
    return 0;
}
