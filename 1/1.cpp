/*
 * @Author: your name
 * @Date: 2020-03-11 16:55:06
 * @LastEditTime: 2020-03-11 16:56:29
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++w\1.cpp
 */

#include <iostream>
using namespace std;

int count(int n, int x)
{
    int res = 0, j;
    for (int i = 1; j = n / i; i *= 10)
    {
        int high = j / 10;
        if (x == 0)
        {
            if (high)
                high--;
            else
                break;
        }
        res += high * i;
        int tem = j % 10;
        if (tem > x)
            res += i;
        else if (tem == x)
            res += n - j * i + 1;
    }
    return res;
}
int main()
{
    int n;
    while (cin >> n)
    {
        cout << count(n, 0);
        for (int i = 1; i <= 9; i++)
            cout << " " << count(n, i);
    }
    return 0;
}