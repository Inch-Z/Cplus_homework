#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159
class Point
{
    friend class Line;

protected:
    double x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double xv, double yv)
    {
        x = xv;
        y = yv;
    }
    double Area() { return 0; }
    void Show() { cout << "x=" << x << ' ' << "y=" << y << endl; }
};
class Circle : public Point
{
protected:
    double radius;

public:
    Circle()
    {
        x = 0;
        y = 0;
        radius = 0;
    }
    Circle(double xv, double yv, double vv) : Point(xv, yv)
    { //调用基类构造函数
        radius = vv;
    }
    Circle(Circle &cir) : Point(cir)
    { //按赋值兼容规则 cir 可为 Point 实参
        radius = cir.radius;
    }
    Circle &operator=(Circle &cir)
    {
        this->Point::operator=(cir); //在派生类中定义重载的拷贝赋值操作符有固定的 标准格式
        radius = cir.radius;
        return *this;
    }
    double Area() { return PI * radius * radius; }
    void Show()
    {
        cout << "x=" << x << ' ' << "y=" << y << " radius=" << radius << endl; //访问基类的数据成员
    }
};
class Cylinder : public Circle
{
    double high;

public:
    Cylinder()
    {
        x = 0;
        y = 0;
        radius = 0;
        high = 0;
    }
    Cylinder(double xv, double yv, double vv, double kv) : Circle(xv, yv, vv)
    { //调用基类构造 函数
        high = kv;
    }
    Cylinder(Cylinder &cyl) : Circle(cyl)
    { //按赋值兼容规则 cyl 可为 Cylinder 实参
        high = cyl.high;
    }
    Cylinder &operator=(Cylinder &cyl)
    {
        this->Circle ::operator=(cyl); //在派生类中定义重载的拷贝赋值操作符有固定 的标准格式
        high = cyl.high;
        return *this;
    }
    double ceArea() { return 2 * PI * radius * high; }
    double quArea() { return ceArea() + 2 * Area(); }
    double volume() { return Area() * high; }
    void Show()
    {
        cout << "x=" << x << ' ' << "y=" << y << ' ' << "radius=" << radius << ' ' << "high=" << high << endl; //访问基类的数据成员
    }
};
class Line
{
    Point start, end; //对象成员
public:
    Line() {} //对象成员初始化
    Line(double xv1, double yv1, double xv2, double yv2) : start(xv1, yv1), end(xv2, yv2) {}
    double GetLength() { return sqrt((start.x - end.x) * (start.x - end.x) + (start.y - end.y) * (start.y - end.y)); }
    double Area() { return 0; }
    void Show()
    {
        cout << "start point:\n";
        start.Show();
        cout << "end point:\n";
        end.Show();
    }
};
int main()
{
    Point pt(0, 0);
    Circle cl1(100, 100, 10), cl2(cl1), cl3;
    Cylinder h1(50, 50, 20, 30), h2(h1), h3;
    Line ln1(0, 0, 100, 100), ln2;
    cout << "点面积：" << pt.Area() << endl;
    pt.Show();
    cout << "cl1 圆面积：" << cl1.Area() << endl;
    cl1.Show();
    cout << "cl2 圆面积：" << cl2.Area() << endl;
    cl2.Show();
    cl3 = cl1;
    cout << "cl3 圆面积：" << cl3.Area() << endl;
    cl3.Show();
    cout << "h1 底面积：" << h1.Area() << endl;
    cout << "h1 侧面积：" << h1.ceArea() << endl;
    cout << "h1 全面积：" << h1.quArea() << endl;
    cout << "h1 体积：" << h1.volume() << endl;
    h1.Show();
    cout << "h2 底面积：" << h2.Area() << endl;
    cout << "h2 侧面积：" << h2.ceArea() << endl;
    cout << "h2 全面积：" << h2.quArea() << endl;
    cout << "h2 体积：" << h2.volume() << endl;
    h2.Show();
    h3 = h1;
    cout << "h3 底面积：" << h3.Area() << endl;
    cout << "h3 侧面积：" << h3.ceArea() << endl;
    cout << "h3 全面积：" << h3.quArea() << endl;
    cout << "h3 体积：" << h3.volume() << endl;
    h3.Show();
    cout << "线面积：" << ln1.Area() << '\t' << "线长度： " << ln1.GetLength() << endl;
    ln1.Show();
    ln2.Show();
    return 0;
}