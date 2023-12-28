#include "Car.h"

int main(){
    Car DoubleR;
    DoubleR.InitMembers("DoubleR", 100);
    DoubleR.Accel();
    DoubleR.Accel();
    DoubleR.Accel();
    DoubleR.ShowCarState();
    DoubleR.Break();
    DoubleR.ShowCarState();
    return 0;
}