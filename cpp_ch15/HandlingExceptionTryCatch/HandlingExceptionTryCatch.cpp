#include <iostream>
using namespace std;

int main(){
    int num1, num2;
    cout<<"두 개의 숫자 입력 : ";
    cin>>num1>>num2;

    try{
        if(num2 == 0){
            throw num2;
        }
        cout<<"num1 / num2 = "<<num1/num2<<endl;
        cout<<"num1 % num2 = "<<num1%num2<<endl;
    }
    catch(int expt){
        cout<<"분모가 0이 될 수는 없다"<<endl;
        cout<<"프로그램 다시 실행해라"<<endl;
    }
    return 0;
}