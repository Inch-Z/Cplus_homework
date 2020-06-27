
#include <iostream>
#include <unistd.h>
#include <Windows.h>
using namespace std;
class Timer
{
private:
    int hour, minute, second;

public:
    Timer(){};
    Timer(int h, int m, int s) : hour(h), minute(m), second(s) {}
    friend ostream &operator<<(ostream &os, Timer &s);
    friend ostream &operator>>(ostream &os, Timer &s);
    Timer operator--();
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }
    void setHour(int h) { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSecond(int s) { second = s; }
    void show() {}
};
Timer Timer::operator--()
{
    if (second > 0)
    {
        second--;
    }
    else if (minute > 0)
    {
        second = 59;
        minute--;
    }
    else
    {
        minute = 59;
        second = 59;
        hour--;
    }
    return *this;
}

ostream &operator<<(ostream &os, Timer &t)
{
    os << t.getHour() << ":";
    os << t.getMinute() << ":";
    os << t.getSecond() << endl;
    return os;
}
istream &operator>>(istream &is, Timer &t)
{
    cout << "按顺序输入时 分 秒" << endl;
    int i;
    is >> i;
    t.setHour(i);
    is >> i;
    t.setMinute(i);
    is >> i;
    t.setSecond(i);
    //cout<<endl;
    return is;
}
int main(int argc, const char *argv[])
{
    Timer t = Timer();
    cin >> t;
    while (1)
    {
        if (t.getHour() == 0 && t.getMinute() == 0 && t.getSecond() == 0)
        {
            t.setHour(24);
            t.setMinute(0);
            t.setSecond(0);
        }
        --t;
        system("cls");
        cout << t;
        sleep(1);
    }
}
