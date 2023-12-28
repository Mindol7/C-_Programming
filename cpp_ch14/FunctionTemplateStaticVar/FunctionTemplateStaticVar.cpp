#include <iostream>
using namespace std;

template <class T>
void ShowStaticVar(){
    static T num = 0;
    num+=1;
    cout<<num<<" ";
}

int main(){
    ShowStaticVar<int>();
    ShowStaticVar<int>();
    ShowStaticVar<int>();
    cout<<endl;
    
    ShowStaticVar<long>();
    ShowStaticVar<long>();
    ShowStaticVar<long>();
    cout<<endl;

    ShowStaticVar<double>();
    ShowStaticVar<double>();
    ShowStaticVar<double>();
    cout<<endl;
    return 0;
}