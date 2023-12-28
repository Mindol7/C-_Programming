#include <iostream>
using namespace std;

class Temporary{
    private:
        int num;
    public:
        Temporary(int n):num(n){
            cout<<"Create Temp Obj: "<<num<<endl;
        }
        ~Temporary(){
            cout<<"Destroy obj:"<<num<<endl;
        }
        void ShowTempInfo(){
            cout<<"My num is "<<num<<endl;
        }
};

int main(){
    Temporary(100);
    cout<<"*************** after make!"<<endl<<endl;
    Temporary(200).ShowTempInfo();
    cout<<"*************** after make!"<<endl<<endl;
    const Temporary &ref = Temporary(300);
    cout<<"*************** end of the main!"<<endl<<endl;
    return 0;
}