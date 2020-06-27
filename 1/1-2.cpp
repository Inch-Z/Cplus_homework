
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int sp, height;
	bool flag = true;
	while (flag)
	{

		cout << "请输入你的图高度：" << endl;
		cin >> height;
		for (int i = 1; i <= height; i++)
		{
			if (i <= (height + 1) / 2)
				sp = (height + 1) / 2 - i + 1;
			else
				sp = i - (height + 1) / 2 + 1;
			cout << setw(sp);
			for (int j = 1; j <= height - 2 * sp + 1; j++)
				cout << '*';
			cout << '*' << endl;
		}
		cout << "继续使用请输入”1“，退出请输入”0“" << endl;
		cin >> flag;
	}
	return 0;
}