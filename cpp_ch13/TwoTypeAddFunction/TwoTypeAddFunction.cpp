#include <iostream>
using namespace std;

template <class T> //틀
T Add(T num1, T num2){ //틀의 모양
    cout<<"T Add(T num1, T num2)"<<endl;
    return num1+num2;
}

int Add(int num1, int num2){
    cout<<"Add(int num1, int num2)"<<endl;
    return num1+num2;
}
int Add(double num1, double num2){
    cout<<"Add(double num1, double num2)"<<endl;
    return num1+num2;
}

int main(){
    cout<< Add(10,20)<<endl;
    cout<< Add(3.7, 5.2)<<endl;
    cout<< Add<int>(2.3,4.3)<<endl; //템플릿 함수가 호출
    cout<< Add<double>(102.4,200)<<endl;
    return 0;
}