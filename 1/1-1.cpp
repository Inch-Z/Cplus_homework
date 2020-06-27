//open with GBK
#include <iostream>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
int max(int a, int b, int c)
{
    return max(a, b) > c ? max(a, b) : c;
}
int main()
{
    int a, b, c, flag;
    bool fr = true;
    while (fr)
    {
        cout << "两数判断请输入“2”，三数判断请输入“3”" << endl;
        cin >> flag;
        switch (flag)
        {
        case 2:
            cout << "请输入两个数：" << endl;
            cin >> a >> b;
            cout << "最大数是：" << max(a, b) << endl;
            break;
        case 3:
            cout << "请输入三个数：" << endl;
            cin >> a >> b >> c;
            cout << "最大数是：" << max(a, b, c) << endl;
            break;
        default:
            break;
        }
        cout << "继续使用请输入”1“，退出请输入”0“" << endl;
        cin >> fr;
    }
    return 0;
}