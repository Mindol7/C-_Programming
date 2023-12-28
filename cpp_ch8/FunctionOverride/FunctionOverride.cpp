#include <iostream>
using namespace std;

class First{
    public:
        void MyFunc(){
            cout<<"First"<<endl;
        }
};

class Second:public First{
    public:
        void MyFunc(){
            cout<<"Second"<<endl;
    }
};

class Third:public Second{
    public:
        void MyFunc(){
            cout<<"Third"<<endl;
    }
};

int main(){
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;
    return 0;
}