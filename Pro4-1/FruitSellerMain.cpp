#include <iostream>
#include "FruitSeller.h"
using namespace std;

int main(){
    //정보의 은닉을 통해 직접적으로 멤버에 접근하지 않음
    FruitSeller seller;
    FruitBuyer buyer;
    seller.InitMembers(1000,20,0);
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 3000);

    cout<<"과일 판매자의 현황"<<endl;
    seller.ShowSaleResult();
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowBuyResult();
    return 0;
}