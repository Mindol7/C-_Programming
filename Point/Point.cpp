#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int &xpos, const int &ypos){
    x = xpos;
    y = ypos;
}

int Point::GetX() const{
    return x;
}

int Point::GetY() const{
    return y;
}

bool Point::SetX(int xpos){
    if(xpos<0 || xpos > 100){
        cout<<"Error Range of value !"<<endl;
        return false;
    }
    else{
        x = xpos;
        return true;
    }
}

bool Point::SetY(int ypos){
    if(ypos<0 || ypos > 100){
        cout<<"Error Range of value !"<<endl;
        return false;
    }
    else{
        y = ypos;
        return true;
    }
}