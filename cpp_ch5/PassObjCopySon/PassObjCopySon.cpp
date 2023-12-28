#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int n):num(n){}
        SoSimple(const SoSimple& copy):num(copy.num){
            cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
        }
        void ShowData(){
            cout<<"num : "<<num<<endl;
        }
};

void SoSimpleFuncObj(SoSimple ob){ //객체가 인자로 전달될때 복사생성자가 호출됨
    ob.ShowData();
}

int main(){
    SoSimple obj(7);
    cout<<"함수 호출 전 "<<endl;
    cout<<"////"<<endl;
    SoSimpleFuncObj(obj);
    cout<<"함수 호출 후 "<<endl;
    return 0;
}