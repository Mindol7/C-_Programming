#include <iostream>
using namespace std;

template <class T>
class SimpleStaticMem{
    private:
        static T mem;
    public:
        void AddMem(T num){
            mem += num;
        }
        void ShowMem() const{
            cout<<mem<<endl;
        }
};
template <class T>
T SimpleStaticMem<T>::mem = 0;

template <>
long SimpleStaticMem<long>::mem = 5; //static 변수의 특수화를 반영한 초기화

int main(){
    SimpleStaticMem<int> obj1; //static mem_ver1
    SimpleStaticMem<int> obj2;
    obj1.AddMem(2);
    obj2.AddMem(3);
    obj1.ShowMem();

    SimpleStaticMem<long> obj3; //static mem_ver2
    SimpleStaticMem<long> obj4;
    obj3.AddMem(500);
    obj4.AddMem(1000);
    obj3.ShowMem();
    obj4.ShowMem();
    return 0;
}