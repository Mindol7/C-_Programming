#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int n):num(){
            cout<<"New Object : "<<this<<endl;
        }
        SoSimple(const SoSimple& copy):num(copy.num){
            cout<<"New Copy Obj: "<<this<<endl;
        }
        ~SoSimple(){
            cout<<"Destroy Obj : "<<this<<endl;
        }

};

SoSimple SimFuncObj(SoSimple ob){
    cout<<"Parm ADRRESS : "<<&ob<<endl;
    return ob;
}

int main(){
    SoSimple obj(7);
    SimFuncObj(obj);
    cout<<endl;

    SoSimple tempRef = SimFuncObj(obj);
    cout<<"Return obj "<<&tempRef<<endl;
    return 0;
}