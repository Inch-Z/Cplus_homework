#include <iostream>
#include <stdlib.h>
using namespace std;

class FDAccount
{
public:
    FDAccount(char *ID, char *depositor, double amount, int period, double rate); //amount ��ǰ����
    double fetch(char *ID, char *depositor, double amount);                       //ȡǮ
    void update();                                                                //ˢ�����
    void show();                                                                  //��ʾ�˻�������Ϣ
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
    cout << "�˻���Ϣ:" << endl;
    cout << "�˻�:" << accounts << endl;
    cout << "����:" << name << endl;
    cout << "����:" << term << endl;
    cout << "����:" << interest_rate << endl;
    cout << "�˻����:" << balance << endl;
}
int main()
{
    FDAccount depositor("8888", "��������", 888888, 24, 3.00);
    depositor.show();
    cout << endl;
    cout << "�����ϴδ��ʱ��Ϊ���ٸ���ǰ��" << endl;
    int x;
    cin >> x;
    if (x < depositor.getTerm())
    {
        cout << "��δ����" << endl;
        depositor.show();
        return 0;
    }
    else
    {
        cout << "�ѵ��ڿ���ȡ��" << endl;
        depositor.update();
        depositor.show();
    label1:
        int y = 0;
        cout << "ȡ�ֽ��:";
        cin >> y;
        if (y > depositor.getAmount())
        {
            cout << "����,��������" << endl;
            goto label1;
        }
        else
        {
            depositor.fetch("8888", "��������", y);
            cout << endl;
            depositor.show();
        }
    }
    return 0;
}
