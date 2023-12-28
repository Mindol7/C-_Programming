#include <iostream>
using namespace std;

template <class T>
T Max(T a, T b){
    return a>b?a:b;
}

int main(void){
    cout<<Max(20,10)<<endl;
    cout<<Max('A','C')<<endl;
    cout<<Max(3.5,7.5)<<endl;
    cout<<Max("Minhyuk","SongHyun")<<endl; //이 코드에서는 주소값이 앞선것을 반환하게됨 -> 함수 템플릿의 특수화 필요
    return 0;
}