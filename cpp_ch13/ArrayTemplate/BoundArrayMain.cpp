#include <iostream>
#include "Point.h"
#include "ArrayTemplate.h"
using namespace std;

int main(){
    BoundCheckArray<int> iarray(5); //int의 형태
    for(int i = 0; i<5; i++){
        iarray[i] = (i+1)*11;
    }
    for(int i = 0; i<5; i++){
        cout<<iarray[i];
    }

    BoundCheckArray<Point> oarry(3); //객체를 가르키는 포인터 만드는거야
    oarry[0] = Point(3, 4); //임시객체의 형태
    oarry[1] = Point(5, 6);
    oarry[2] = Point(7, 8);

    typedef Point* POINT_PTR;

    //포인터를 가르키는 포인터를 만드는거야
    BoundCheckArray<POINT_PTR> parry(3);
    parry[0] = new Point(3, 4); //포인터의 형태
    parry[1] = new Point(5, 6);
    parry[2] = new Point(7, 8);

    for(int i = 0; i<parry.GetArrLen();i++){
        cout<<*(parry[i]);
    }

    delete parry[0];
    delete parry[1];
    delete parry[2];
    return 0;

}