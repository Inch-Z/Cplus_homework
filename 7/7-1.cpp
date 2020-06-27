//
//  main.cpp
//  7.1
//
//  Created by Inch.Z on 2020/6/10.
//  Copyright ? 2020 Inch.Z. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string.h>
#include <algorithm>
template <class ElemType>

class Array
{
private:
    int length;
    ElemType *que;

public:
    Array()
    {
        cout << "����������Ԫ�ظ�����" << endl;
        cin >> length;
        que = new ElemType[length];
        cout << "������Ԫ�أ�" << endl;
        for (int i = 0; i < length; i++)
            cin >> que[i];
    }
    void sortArray()
    {
        sort(que, que + length);
        cout << "��������ɣ�����������Ϊ:" << endl;
        for (int i = 0; i < length; i++)
            cout << que[i] << " ";
        cout << "" << endl;
    }
    ElemType max()
    {
        ElemType m = que[0];
        for (int i = 0; i < length - 1; i++)
            if (que[i] < que[i + 1])
                m = que[i + 1];
        return m;
    }
    ElemType sum()
    {
        ElemType m = que[0];
        for (int i = 1; i < length; i++)
            m += que[i];
        return m;
    }
};
int main(int argc, const char *argv[])
{
    Array<int> array;
    int choc = 0;
    cout << "��������룺1������ 2�������ֵ 3����� 0���˳�" << endl;
    cin >> choc;
    while (choc)
    {
        switch (choc)
        {
        case 1:
            array.sortArray();
            cin >> choc;
            continue;
        case 2:
            cout << "MAX��" << array.max() << endl;
            cin >> choc;
            continue;
        case 3:
            cout << "SUM��" << array.sum() << endl;
            cin >> choc;
            continue;
        default:
            cout << "ERROR��PLEASE RETRY!" << endl;
            cout << "��������룺1������ 2�������ֵ 3����� 0���˳�" << endl;
            cin >> choc;
            continue;
        }
    }
}
