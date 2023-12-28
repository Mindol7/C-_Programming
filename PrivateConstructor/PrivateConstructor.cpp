#include <iostream>
using namespace std;

class AAA{ //내부에서 객체 생성 private 생성자 필요
    private:
        int num;
    public:
        AAA():num(0){};
        AAA& CreateInitObj(int n)const{
            AAA * ptr = new AAA(n);
            return *ptr;
        }
        void ShowNum() const{
            cout<<num<<endl;
        }
    private:
        AAA(int n):num(n){};
};

int main(){
    AAA base;
    base.ShowNum();

    AAA &obj1 = base.CreateInitObj(3);
    obj1.ShowNum();
    AAA &obj2 = base.CreateInitObj(20);
    obj2.ShowNum();

    delete &obj1;
    delete &obj2;
    return 0;
}