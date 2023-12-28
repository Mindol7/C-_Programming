#include <iostream>
using namespace std;

class SoBase{
    private:
        int baseNum;
    public:
        SoBase():baseNum(20){
            cout<<"SoBase()"<<endl;
        }
        SoBase(int n):baseNum(n){
            cout<<"SoBase(int n)"<<endl;
        }
        void ShowBaseData(){
            cout<<baseNum<<endl;
        }
};

class SoDerived: public SoBase{
    private:
        int deriveNum;
    public:
        SoDerived():deriveNum(30){
            cout<<"SoDerived()"<<endl;
        }
        SoDerived(int b):deriveNum(b){
            cout<<"SoDerived(int b)"<<endl;
        }
        SoDerived(int n, int b):SoBase(n), deriveNum(b){
            cout<<"SoDerived(int n, int b)"<<endl;
        }

        void ShowDerivData(){
            ShowBaseData();
            cout<<deriveNum<<endl;
        }
};

int main(){
    cout<<"case 1 ........."<<endl; //디폴트 복사생성자로 기초클래스가 호출되고 그다음 유도클래스가 호출됨
    SoDerived dr1;
    dr1.ShowDerivData();
    cout<<"--------------"<<endl;
    cout<<"case 2 ........."<<endl;
    SoDerived dr2(12);
    dr1.ShowDerivData();
    cout<<"--------------"<<endl;
    cout<<"case 3 ........."<<endl;
    SoDerived dr3(25, 35);
    dr3.ShowDerivData();
    cout<<"-------------"<<endl;
    return 0;
}