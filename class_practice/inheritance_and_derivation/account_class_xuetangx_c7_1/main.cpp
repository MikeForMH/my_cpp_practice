//
//  main.cpp
//  account_class_xuetangx_c7_1
//
//  Created by Michael Hui on 29/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Account
{
    string userName;
public:
    Account(){};
    Account( string name );
    void  PrintUserName();
};

class CreditAccount : public Account
{
public:
    CreditAccount( string name, int credit);
    void PrintInfo();
private:
    int credit;
};

//请实现Account构造函数Account(char *name)
Account::Account(string name){
    userName = name;
}
//请实现Account的PrintUserName()函数
void Account::PrintUserName(){
    cout << userName << endl;
}
//请实现CreditAccount类的构造函数CreditAccount(char* name, long number)
CreditAccount::CreditAccount(string name, int credit):Account(name){
    this->credit = credit;
}
//请实现CreditAccount类的PrintInfo()函数
void CreditAccount::PrintInfo(){
    PrintUserName();
    cout << credit << endl;
}

int main()
{
    CreditAccount a("I Love CPP", 10000);
    a.PrintInfo();
    return 0;
    }
