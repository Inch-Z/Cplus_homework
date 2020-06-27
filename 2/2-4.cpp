#include <iostream>
using namespace std;
class List;
class Node
{
public:
    friend class List;
    Node(int d = 0)
    {
        data = d;
        next = 0;
    }

private:
    Node *next;
    int data;
};
class List
{
public:
    List() { list = 0; }
    List(int d) { list = new Node(d); }
    int print();
    void insert(int d = 0);
    int append(int d = 0);
    void connect(List &il);
    void reverse();
    int length();

private:
    Node *end();
    Node *list;
};
int List::print()
{
    if (list == 0)
    {
        cout << "NULL!" << endl;
        return 0;
    }
    Node *p = list;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }

    return 0;
}
void List::insert(int d)
{
    Node *p = new Node(d);
    p->next = list;
    list = p;
}
int List::append(int d)
{
    Node *p = new Node(d);
    if (list == 0)
        list = p;
    else
        (end())->next = p;
    return 0;
}
Node *List::end()
{
    Node *p, *ptr;
    for (p = ptr = list; ptr;)
    {
        p = ptr;
        ptr = ptr->next;
    }
    return p;
}
void List::connect(List &il)
{
    Node *p = il.list;
    while (p)
    {
        append(p->data);
        p = p->next;
    }
}
void List::reverse()
{
    Node *p, *ptr, *t;
    ptr = 0;
    p = list;
    list = end();
    while (p != list)
    {
        t = p->next;
        p->next = ptr;
        ptr = p;
        p = t;
    }
    list->next = ptr;
}
int List::length()
{
    int count = 0;
    Node *p = list;
    for (; p; p = p->next)
        count++;
    return count;
}

int main(int argc, const char *argv[])
{
    List list1;
    list1.print();
    for (int i = 0; i < 20; i += 2)
        list1.insert(i);
    cout << "下面输出前插入的list1" << endl;

    list1.print();
    List list2;
    cout << "\n";
    list2.print();
    for (int i = 0; i < 10; i += 3)
        list2.append(i);
    cout << "下面输出后插入的L2" << endl;
    list2.print();
    cout << "\n";
    list1.connect(list2);
    cout << "下面输出合并的L1" << endl;
    list1.print();
    list2.reverse();
    cout << "\n";
    cout << "下面输出反转后的L2" << endl;
    list2.print();
    cout << "\n";
    cout << "下面输出L1的长度：";
    cout << list1.length() << endl;

    return 0;
}
