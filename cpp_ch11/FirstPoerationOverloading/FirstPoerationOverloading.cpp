#include <iostream>
using namespace std;

class First{
    private:
        int num1, num2;
    public:
        First(int n1 = 0 , int n2 = 0):num1(n1), num2(n2){}
        void ShowData(){
            cout<<num1<<",  "<<num2<<endl;
        }
};

class Second{
    private:
        int num3, num4;
    public:
        Second(int n3 = 0, int n4 = 0):num3(n3),num4(n4){}
        void ShowData(){
            cout<<num3<<",  "<<num4<<endl;
        }

        Second& operator=(const Second &ref){
            cout<<"Second Operator=()"<<endl;
            num3 = ref.num3;
            num4 = ref.num4;
            return *this;
        }
};

int main(){
    First fsrc(111, 222);
    First fcpy;
    Second ssrc(333, 444);
    Second scpy;
    fcpy = fsrc; //디폴트 대입 연산자의 호출 (동적할당 시 문제가 됨)
    scpy = ssrc;
    fcpy.ShowData();
    scpy.ShowData();

    First fob1, fob2;
    Second sob1, sob2;

    fob1=fob2=fsrc;
    sob1=sob2=ssrc;

    fob1.ShowData();
    fob2.ShowData();
    sob1.ShowData();
    sob2.ShowData();
    return 0;
}