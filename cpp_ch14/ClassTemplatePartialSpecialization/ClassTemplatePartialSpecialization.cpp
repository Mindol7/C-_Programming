#include <iostream>
using namespace std;


//CASE 1
template <class T1, class T2>
class MySimple{
    public:
        void WhoAreYou(){    
            cout<<"Size of T1 : "<<sizeof(T1)<<endl;
            cout<<"Size of T2 : "<<sizeof(T2)<<endl;
            cout<<"<class T1, class T2"<<endl;
        }
};

//CASE 2
template<>
class MySimple<int, double>{
    public:
        void WhoAreYou(){    
            cout<<"Size of int : "<<sizeof(int)<<endl;
            cout<<"Size of double : "<<sizeof(double)<<endl;
            cout<<"<class int, class double"<<endl;
        }
};

// CASE 3
template<class T1>
class MySimple<T1, int>{
    public:
        void WhoAreYou(){    
            cout<<"Size of T1 : "<<sizeof(T1)<<endl;
            cout<<"Size of int : "<<sizeof(int)<<endl;
            cout<<"<class T1, class int"<<endl;
        }
};

int main(){
    MySimple<char, double> obj1;
    obj1.WhoAreYou(); //CASE 1 출력

    MySimple<int, long> obj2;
    obj2.WhoAreYou(); //CASE 1 출력

    MySimple<double, int> obj3;
    obj3.WhoAreYou(); //CASE 3 출력

    MySimple<int, double> obj4;
    obj4.WhoAreYou(); //CASE 2 출력
    return 0;
}