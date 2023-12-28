#include <iostream>
using namespace std;

class SinivelCap{
    public:
        void Take() const{
            cout<<"Happy nose\n";
        }
};

class SneezeCap{
    public:
        void Take() const{
            cout<<"Stop nose\n";
        }
};

class SnuffleCap{
    public:
        void Take() const{
            cout<<"Pill nose\n";
        }
};

class ColdPatient{
    public:
        void TakeSinivelCap(const SinivelCap &cap) const{
            cap.Take();
        }

        void TakeSneezeCap(const SneezeCap &cap) const{
            cap.Take();
        }
        void TakeSnuffleCap(const SnuffleCap &cap) const{
            cap.Take();
        }
};

int main(){
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;

    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezeCap(zcap);
    sufferer.TakeSnuffleCap(ncap); //한번에 이루어지지 않고 따로따로 이루어졌음, 그래서 캡슐화 만족 x
    return 0;
}