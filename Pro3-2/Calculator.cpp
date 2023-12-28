#include <iostream>
#include "Calculator.h"
using namespace std;

void Calculator::Init(){
    a = 0;
    b = 0;
    result = 0;
    AddCount = 0;
    MinCount = 0;
    MulCount = 0;
    DivCount = 0;
}

float Calculator::Add(float num1, float num2){
    result = num1+num2;
    AddCount += 1;
    return result;
}

float Calculator::Min(float num1, float num2){
    result = num1-num2;
    MinCount += 1;
    return result;
}

float Calculator::Mul(float num1, float num2){
    result = num1*num2;
    MulCount += 1;
    return result;
}

float Calculator::Div(float num1, float num2){
    result = num1/num2;
    DivCount += 1;
    return result;
}

void Calculator::ShowOpCount(){
    cout<<"Add Step : "<<AddCount<<"  Min Step : "<<MinCount<<"  Mul Step : "<<MulCount<<"  Div Step : "<<DivCount<<endl;
}