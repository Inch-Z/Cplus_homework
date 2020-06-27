#include <iostream>
#include "math.h"
using namespace std;
class Shape
{
public:
    virtual double area() = 0;
    virtual void show() = 0;
};
class Triangle : public Shape
{
protected:
    double a, b, c;

public:
    Triangle() : a(0), b(0), c(0) {}
    Triangle(double aa, double bb, double cc) : a(aa), b(bb), c(cc) {}
    double area() override
    {
        double p = 0.5 * (a + b + c);
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    void show() override
    {
        cout << "Tri a,b,c：" << a << " " << b << " " << c << endl;
        cout << "Tri's area" << area() << endl;
    }
};
class Rectangle : public Shape
{
protected:
    double a, b;

public:
    Rectangle() : a(0), b(0) {}
    Rectangle(double aa, double bb) : a(aa), b(bb) {}
    double area() override { return a * b; }
    void show() override
    {
        cout << "Rect a,b:" << a << " " << b << endl;
        cout << "Rect's area" << area() << endl;
    }
};
class Circle : public Shape
{
protected:
    double a, b, r;

public:
    Circle() : a(0), b(0), r(0) {}
    Circle(double aa, double bb, double rr) : a(aa), b(bb), r(rr) {}
    double area() override { return r * r * 3.14; }
    void show() override
    {
        cout << "C'S："
             << "(" << a << "," << b << ")" << endl;
        cout << "radius：" << r << endl;
        cout << "area:" << area() << endl;
    }
};
double total(Shape *s[], int n)
{
    int i = 0;
    double sum = 0;
    for (; i < n; i++)
    {
        sum += s[i]->area();
    }
    return sum;
}
int main()
{
    Shape *p[3];
    Triangle tr = Triangle(3, 4, 5);
    Rectangle re = Rectangle(3, 4);
    Circle ci = Circle(3, 4, 5);
    tr.show();
    re.show();
    ci.show();
    p[0] = &tr;
    p[1] = &re;
    p[2] = &ci;
    cout << "total：" << total(p, 3) << endl;
    return 0;
}