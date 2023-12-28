#include <iostream>
using namespace std;

class SoBase{
    private:
        int baseNum;
    public:
        SoBase(int n):baseNum(n){
            cout<<"SoBase(int n) : "<<baseNum<<endl;
        }
        ~SoBase(){
            cout<<"~SoBase()"<<baseNum<<endl;
        }
};

class SoDeriv: public SoBase{
    private:
        int derivNum;
    public:
        SoDeriv(int n):SoBase(n),derivNum(n){
            cout<<"SoDeriv(int n): "<<derivNum<<endl;
        }
        ~SoDeriv(){
            cout<<"~SoDeriv(int n)"<<derivNum<<endl;
        }
};

int main(){
    SoDeriv dr1(50);
    SoDeriv dr2(100);
    return 0;
}