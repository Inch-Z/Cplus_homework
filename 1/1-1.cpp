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
        cout << "�����ж������롰2���������ж������롰3��" << endl;
        cin >> flag;
        switch (flag)
        {
        case 2:
            cout << "��������������" << endl;
            cin >> a >> b;
            cout << "������ǣ�" << max(a, b) << endl;
            break;
        case 3:
            cout << "��������������" << endl;
            cin >> a >> b >> c;
            cout << "������ǣ�" << max(a, b, c) << endl;
            break;
        default:
            break;
        }
        cout << "����ʹ�������롱1�����˳������롱0��" << endl;
        cin >> fr;
    }
    return 0;
}