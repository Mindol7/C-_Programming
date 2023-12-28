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
        SoSimple& AddNum(int n){
            num+=n;
            return *this;
        }
        void ShowData(){
            cout<<"num : "<<num<<endl;
        }
};

SoSimple SimpleFuncObj(SoSimple ob){
    cout<<"return 이전"<<endl;
    return ob;
}

int main(){
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData(); //객체가 복사되어 반환되면서, this 포인터가 가르키는 SoSimple객체가 반환되면서 ShowData()함수호출
    obj.ShowData(); //원본은 그대로 유지됨
    return 0;
}