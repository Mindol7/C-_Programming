#include <iostream>
using namespace std;

//template <typename T> //템플릿(틀) 선언 -> 이로써 자료형에 의존적이지 않게 함수를 찍어낼 수 있다
template <class T>
T Add(T num1, T num2){
    return num1+num2;
}

int main(){
    cout<<Add(10,20)<<endl;
    cout<<Add(1.2,3.4)<<endl;
    cout<<Add<int>(3.2,2.2)<<endl; //명시해줌으로써 자료형 깊은 결정
    cout<<Add(100,200)<<endl;
    return 0;
}