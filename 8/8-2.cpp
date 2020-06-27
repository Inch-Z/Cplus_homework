//
//  main.cpp
//  8.2
//
//  Created by 张印祺 on 2020/6/10.
//  Copyright © 2020 张印祺. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
using namespace std;
class Book
{
private:
    char name[20];
    char publisher[20];
    char editor[20];
    float price;

public:
    Book() {}
    Book(char *n, char *p, char *e, float pri)
    {
        strcpy(name, n);
        strcpy(publisher, p);
        strcpy(editor, e);
        price = pri;
    }
    float getPrice()
    {
        return price;
    }
    void display()
    {
        cout << name << "\t" << publisher << "\t" << editor << "\t" << price << endl;
    }
};

int main()
{
    int num;
    cout << "输入书的数目：" << endl;
    cin >> num;
    fstream ioFile;
    char Name[20], Pulisher[20], Editor[20];
    float pri;
    ioFile.open("..\\book.dat", ios::out);
    for (int i = 0; i < num; i++)
    {
        cout << "书名:";
        cin >> Name;
        cout << "出版社:";
        cin >> Pulisher;
        cout << "作者:";
        cin >> Editor;
        cout << "价格:";
        cin >> pri;
        Book b(Name, Pulisher, Editor, pri);
        ioFile.write((char *)&b, sizeof(b));
    }
    ioFile.close();
    ioFile.open("..\\book.dat", ios::in | ios::binary);
    cout << "书名\t"
         << "  出版社\t"
         << "   作者\t"
         << "   价格" << endl;
    Book book;
    float pric = 0;
    for (int i = 0; i < num; i++)
    {
        ioFile.read((char *)&book, sizeof(book));
        pric += book.getPrice();
        book.display();
    }
    cout << "总价格为：" << pric << endl;
    ioFile.close();
}
