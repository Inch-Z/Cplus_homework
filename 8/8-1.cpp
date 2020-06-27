//
//  main.cpp
//  8.1
//
//  Created by 张印祺 on 2020/6/10.
//  Copyright © 2020 张印祺. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main(int argc, const char *argv[])
{
    ofstream intt;
    intt.open(".\\input.txt");
    if (!intt)
    {
        cout << "不能打开输入文件！" << endl;
        return 0;
    }
    intt << "Abc"
         << " " << 90 << endl;
    ifstream in;
    in.open(".\\input.txt");
    ofstream out;
    out.open(".\\output.txt");
    if (!out)
    {
        cout << "不能打开输出文件！" << endl;
        return 0;
    }
    char ch;
    while (!in.eof())
    {
        ch = in.get();
        if (islower(ch))
            ch = toupper(ch);
        else
            ch = tolower(ch);
        out.put(ch);
    }
    in.close();
    intt.close();
    out.close();
}
