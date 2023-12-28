#include <iostream>
using namespace std;

class First{
    public:
        void FirstFunc(){cout<<"FirstFunc()"<<endl;}
        virtual void SimpleFunc(){cout<<"Simple First()"<<endl;}        
};

class Second:public First{
    public:
        void SecondFunc(){cout<<"SecondFunc()"<<endl;}
        virtual void SimpleFunc(){cout<<"Simple Second()"<<endl;}
};

class Third:public Second{
    public:
        void ThirdFunc(){cout<<"ThirdFunc()"<<endl;}
        virtual void SimpleFunc(){cout<<"Simple Third()"<<endl;}
};

int main(){
    Third obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.SimpleFunc();

    Second & sref = obj;
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();

    First & fref = obj;
    fref.FirstFunc();
    fref.SimpleFunc();
    return 0;
}