#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int num):num(num){}
        SoSimple& AddNum(int n){
            num += n;
            return *this;
        }

        void ShowData(){
            cout<<"num: "<<num<<endl;
        }
        void ShowData() const{
            cout<<"const num: "<<num<<endl;
        }
};

void YourFunc(const SoSimple& obj){
    obj.ShowData(); //const로 인자를 받았으니 const가 전달됨
}

int main(){
    const SoSimple obj1(7);
    SoSimple obj2(25);
    //obj.AddNum(20);
    obj1.ShowData();
    obj2.ShowData();
    YourFunc(obj1);
    YourFunc(obj2);

    return 0;
}