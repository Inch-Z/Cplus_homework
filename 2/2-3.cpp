#include <iostream>
using namespace std;
class sale
{
private:
    int num;
    int quanity;
    double price;
    static double sum;
    static double discount;
    static int count;

public:
    sale(int n, int q, double p) : num(n), quanity(q), price(p){};
    static double Average(sale *, int n);
    static void display(sale *, int n);
};
double sale::discount = 0.98;
double sale::sum = 0;
int sale::count = 0;
double sale::Average(sale *s, int n)
{
    sale *p;
    for (p = s; p < s + n; p++)
    {
        if (p->quanity > 10)
        {
            p->price *= discount;
        }
        sum += (p->price) * (p->quanity);
        count += p->quanity;
    }
    return sum / count;
}

void sale::display(sale *s, int n)
{
    cout << "Average:" << sale::Average(s, n) << endl;
    cout << "Sum:" << sale::count << endl;
}

int main(int argc, const char *argv[])
{
    sale s[3] = {sale(101, 5, 23.5), sale{102, 12, 24.56}, sale(103, 100, 21.5)};
    sale::display(s, 3);
    return 0;
}
