#include <iostream>
#include <cstring>
using namespace std;

class DepositException{ //예외의 이유를 알려주는 예외객체
    private:
        int reqDep;
    public:
        DepositException(int money):reqDep(money){}
        void ShowExceptionReason(){
            cout<<"[에외 메시지 : "<<reqDep<<"는 입금 불가]"<<endl;
        }
};

class WithdrawException{ //예외의 이유를 알려주는 예외객체
    private:
        int balance;
    public:
        WithdrawException(int money):balance(money){}
        void ShowExceptionReason(){
            cout<<"[에외 메시지: 잔액 "<<balance<<", 잔액부족"<<endl;
        }
};

class Account{
    private:
        char accNum[50];
        int balance;
    public:
        Account(char * acc, int money):balance(money){
            strcpy(accNum, acc);
        }
        void Deposit(int money){
            if(money<0){
                DepositException expn(money);
                throw expn;
            }
            balance += money;
        }
        void Withdraw(int money){
            if(money > balance){
                WithdrawException expn(money); //임시객체의 형태로 전달이 더 좋음
                throw expn;
            }
            balance -= money;
        }
        void ShowMyMoney() const{
            cout<<"잔고 : "<<balance<<endl<<endl;
        }
};

int main(){
    Account myAcc("1234-2198", 5000);

    try{
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    }
    catch(DepositException &expn){
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try{
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4500);
    }
    catch(WithdrawException &expn){
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();
    return 0;
}