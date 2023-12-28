#include <iostream>
#include "FruitSeller.h"
using namespace std;

bool FruitSeller::InitMembers(int price, int num, int money){
    if(num < 0){
        cout<<"Error to Range !!!"<<endl; //사과 갯수 0보다 작지 않도록 안정장치 및 액세스
        return false;
    }
    else{
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
        return true;
    }
}

int FruitSeller::SaleApples(int money){
    int num = money /APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
}

int FruitSeller::GetApple() const{
    return numOfApples;
}

int FruitSeller::GetMoney() const{
    return myMoney;
}

void FruitSeller::ShowSaleResult() const{
    cout<<"Remain money : "<<GetApple()<<endl;
    cout<<"Plus Money : "<<GetMoney()<<endl;
}

bool FruitBuyer::InitMembers(int money){
    if(money < 0){
        cout<<"Fail to Init!!!"<<endl; //초기자본이 0보다 작지 않도록 안전장치
        return false;
    }
    else{
        myMoney = money;
        numOfApples = 0;
        return true;
    }
}

bool FruitBuyer::BuyApples(FruitSeller &seller, int money){ //판매자는 이름이 있지만 보통 현실에서도 seller라고 부름
    if(money < 0){
        cout<<"PLZ Give me money"<<endl; //구매할때 돈을 주도록하기 위한 안전장치 이에따라 판매자는 믿고 갯수를 돈을 계산하고 사과를 줄 수 있게됨
        return false;
    }
    else{
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
}

int FruitBuyer::GetApple() const{
    return numOfApples;
}

int FruitBuyer::GetMoney() const{
    return myMoney;
}

void FruitBuyer::ShowBuyResult() const{
    cout<<"Remain money : "<<GetMoney()<<endl;
    cout<<"구매한 사과의 갯수 : "<<GetApple()<<endl;
}