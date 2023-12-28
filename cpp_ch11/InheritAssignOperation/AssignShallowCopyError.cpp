#include <iostream>
#include <cstring>
using namespace std;

class First{
    private:
        int num1, num2;
    public:
        First(int n1 = 0 , int n2 = 0):num1(n1), num2(n2){}
        void ShowData(){
            cout<<num1<<",  "<<num2<<endl;
        }

        First& operator=(const First& ref){
            cout<<"First& operator() "<<endl;
            num1 = ref.num1;
            num2 = ref.num2;
            return *this;
        }
};

class Second:public First{
    private:
        int num3, num4;
    public:
        Second(int n1, int n2, int n3, int n4):First(n1, n2),num3(n3),num4(n4){}
        void ShowData(){
            First::ShowData();
            cout<<num3<<",  "<<num4<<endl;
        }
        
        Second& operator=(const Second& ref){ //유도클래스의 디폴트 대입 연산자가 기초클래스의 대입 연산자 호출
            cout<<"Second& operator=()"<<endl; //정의된 대입 연산자는 기초클래스의 대입 연산자를 따로 정의하지 않으면 호출 안함
            First::operator=(ref);
            num3 = ref.num3;
            num4 = ref.num4;
            return *this;
        }
        
};

int main(){
    Second ssrc(111,222,333,444);
    Second scpy(0,0,0,0);
    scpy = ssrc;
    scpy.ShowData();
    return 0;
}