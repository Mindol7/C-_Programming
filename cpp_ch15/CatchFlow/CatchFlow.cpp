#include <iostream>
using namespace std;

class AAA{
    public:
        void ShowYou(){
            cout<<"AAA Exception !!!"<<endl;
        }
};

class BBB : public AAA{
    public:
        void ShowYou(){
            cout<<"BBB Exception !!!"<<endl;
        }
};

class CCC : public BBB{
    public:
        void ShowYou(){
            cout<<"CCC Exception !!!"<<endl;
        }
};

void ExceptionGenerator(int expn){
    if(expn == 1){
        throw AAA();
    }
    else if(expn == 2){
        throw BBB();
    }
    else{
        throw CCC();
    }
}

int main(){
    try{
        ExceptionGenerator(3); //ccc전달
        ExceptionGenerator(2); //bbb전달
        ExceptionGenerator(1); //aaa전달
    }
    catch(CCC& expn){
        cout<<"CCC exception"<<endl;
        expn.ShowYou();
    }
    catch(BBB& expn){
        cout<<"BBB exception"<<endl;
        expn.ShowYou();
    }
    catch(AAA& expn){
        cout<<"AAA exception"<<endl;
        expn.ShowYou();
    }
    return 0;
}