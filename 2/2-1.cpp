#include <iostream>
#include <stdlib.h>
using namespace std;

class FDAccount
{
public:
    FDAccount(char *ID, char *depositor, double amount, int period, double rate); //amount 当前存入
    double fetch(char *ID, char *depositor, double amount);                       //取钱
    void update();                                                                //刷新余额
    void show();                                                                  //显示账户所有信息
    int getTerm() { return term; }
    double getAmount() { return balance; }

protected:
    double interest_rate;

private:
    char *accounts;
    char *name;
    double balance; //Deposited
    int term;       //DDL
};
FDAccount::FDAccount(char *ID, char *depositor, double amount, int period, double rate)
{
    name = depositor;
    accounts = ID;
    if (amount < 0 || rate < 0)
    {
        cout << "ERROR" << endl;
        exit(1);
    }
    balance = amount;
    term = period;
    interest_rate = rate;
}
double FDAccount::fetch(char *ID, char *depositor, double amount)
{
    cout << "Account:" << accounts << endl
         << "Name:" << name << endl
         << "Balance:" << amount << endl;
    balance -= amount;
    return balance;
}
void FDAccount::update()
{
    balance = balance + balance * (interest_rate / 100.0) * (term / 12.0);
}
void FDAccount::show()
{
    cout << "账户信息:" << endl;
    cout << "账户:" << accounts << endl;
    cout << "名称:" << name << endl;
    cout << "期限:" << term << endl;
    cout << "利率:" << interest_rate << endl;
    cout << "账户余额:" << balance << endl;
}
int main()
{
    FDAccount depositor("8888", "测试用例", 888888, 24, 3.00);
    depositor.show();
    cout << endl;
    cout << "输入上次存款时间为多少个月前？" << endl;
    int x;
    cin >> x;
    if (x < depositor.getTerm())
    {
        cout << "还未到期" << endl;
        depositor.show();
        return 0;
    }
    else
    {
        cout << "已到期可以取出" << endl;
        depositor.update();
        depositor.show();
    label1:
        int y = 0;
        cout << "取现金额:";
        cin >> y;
        if (y > depositor.getAmount())
        {
            cout << "余额不足,重新输入" << endl;
            goto label1;
        }
        else
        {
            depositor.fetch("8888", "测试用例", y);
            cout << endl;
            depositor.show();
        }
    }
    return 0;
}
