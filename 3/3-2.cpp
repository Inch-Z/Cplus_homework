#include <iostream>
#include <string>
using namespace std;
class automobile
{
protected:
    string model;                //型号
    double cylinders_capability; //排量
    int wheels;                  //轮数
    double price;                //价格
public:
    automobile(string mod = "#", double cl = 0, int wh = 4, double pr = 0)
    {
        model = mod;
        cylinders_capability = cl;
        wheels = wh;
        price = pr;
    }
    void display()
    {
        cout << "汽车型号：" << model << '\t' << "排量：" << cylinders_capability << "升" << endl;
        cout << "轮数：" << wheels << '\t' << "价格：" << price << endl;
    }
};
class car : public virtual automobile
{
protected:
    int seats;      //座位数
    int safeguards; //保护措施数量
public:
    car(string mod = "#", double cl = 0, int wh = 4, double pr = 0, int st = 5, int saf = 0) : automobile(mod, cl, wh, pr)
    {
        seats = st;
        safeguards = saf;
    }
    void display()
    {
        automobile::display();
        cout << "座位数：" << seats << '\t' << "保护措施数量：" << safeguards << endl;
    }
};
class truck : public virtual automobile
{
protected:
    double carrying_capacity; //载重量
public:
    truck(string mod = "#", double cl = 0, int wh = 4, double pr = 0, double cc = 0) : automobile(mod, cl, wh, pr)
    {
        carrying_capacity = cc;
    }
    void display()
    {
        automobile::display();
        cout << "货物载重量：" << carrying_capacity << "吨" << endl;
    }
    void display1()
    {
        cout << "货物载重量：" << carrying_capacity << "吨" << endl;
    }
};
class car_truck : public car, public truck
{
public:
    car_truck(string mod = "#", double cl = 0, int wh = 4, double pr = 0, int st = 5, int saf = 0, double cc = 0) : car(mod, cl, wh, pr, st, saf), truck(mod, cl, wh, pr, cc), automobile(mod, cl, wh, pr) {}
    void display()
    {
        car::display();
        truck::display();
    }
    void reset()
    { //从类car修改类automobile中的mode，实际仅有一个automobile基类
        car::model = "!";
    }
};
class car1 : public automobile
{
protected:
    int seats;      //座位数
    int safeguards; //保护措施数量
public:
    car1(string mod = "#", double cl = 0, int wh = 4, double pr = 0, int st = 5, int saf = 0) : automobile(mod, cl, wh, pr)
    {
        seats = st;
        safeguards = saf;
    }
    void display()
    {
        automobile::display();
        cout << "座位数：" << seats << '\t' << "保护措施数量：" << safeguards << endl;
    }
};
class truck1 : public automobile
{
protected:
    double carrying_capacity; //载重量
public:
    truck1(string mod = "#", double cl = 0, int wh = 4, double pr = 0, double cc = 0) : automobile(mod, cl, wh, pr)
    {
        carrying_capacity = cc;
    }
    void display()
    {
        automobile::display();
        cout << "货物载重量：" << carrying_capacity << "吨" << endl;
    }
    void display1()
    {
        cout << "货物载重量：" << carrying_capacity << "吨" << endl;
    }
};
class car_truck1 : public car1, public truck1
{
public:
    car_truck1(string mod = "#", double cl = 0, int wh = 4, double pr = 0, int st = 5, int saf = 0,
               double cc = 0) : car1(mod, cl, wh, pr, st, saf), truck1(mod, cl, wh, pr, cc) {}
    void display()
    {
        car1::display();
        truck1::display();
    }
    void reset()
    {
        car1::model = "!";
    } //仅修改类car的基类automobile的model，类truck的基类automobile的model未改
};
int main()
{
    car_truck ct("##", 1.6, 4, 8.4, 5, 3, 0.6);
    ct.display();
    ct.reset();
    ct.display(); //显示出两个同样的model，实际是一个
    car_truck1 ct1;
    ct1.display();
    ct1.reset();
    ct1.display(); //显示出有两个不同的model
    return 0;
}