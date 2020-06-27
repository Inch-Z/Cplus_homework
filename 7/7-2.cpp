//
//  main.cpp
//  7.2
//
//  Created by Inch.Z on 2020/6/10.
//  Copyright © 2020 Inch.Z. All rights reserved.
//
//  main.cpp
//  7.1
//
//  Created by Inch.Z on 2020/6/10.
//  Copyright © 2020 Inch.Z. All rights reserved.
#include <iostream>
using namespace std;
class Queue
{
private:
    int *data;
    int head, tail, count;

public:
    Queue()
    {
        data = new int[10];
        tail = -1;
        count = 0;
        head = 0;
    }
    ~Queue()
    {
        delete[] data;
    }
    void pop()
    {
        if (count < 0)
            return;
        head = (head + 1) % 10;
        --count;
    }
    void push(int e)
    {
        if (count < 10)
        {
            tail = (tail + 1) % 10;
            data[tail] = e;
            ++count;
        }
        else
        {
            throw "队列已满！";
        }
    }
    int top()
    {
        if (count > 0)
        {

            return data[head];
        }
        else
        {
            throw "队列已空！";
        }
    }
    void output()
    {
        cout << "队列的元素为：" << endl;
        for (int i = head; i != tail + 1; i = (i + 1) % 10)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main(int argc, const char *argv[])
{
    Queue q;
    int choc = 0;
    cout << "请选择功能：1、入队 2、出队 0、退出" << endl;
    cin >> choc;
    while (choc)
    {
        if (choc == 1)
        {
            cout << "请输入要入队的值：" << endl;
            int d;
            cin >> d;
            try
            {
                q.push(d);
            }
            catch (const char *msg)
            {
                cerr << msg << endl;
            }
        }
        else if (choc == 2)
        {
            try
            {
                cout << "队首的元素为：" << q.top() << endl;
                q.pop();
            }
            catch (const char *msg)
            {
                cerr << msg << endl;
            }
        }
        else if (choc != 0)
        {
            cout << "输入错误！" << endl;
        }
        q.output();
        cout << "请选择功能：1、入队 2、出队 0、退出" << endl;
        cin >> choc;
    }
}
