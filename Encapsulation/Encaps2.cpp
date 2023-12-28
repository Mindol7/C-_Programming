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

class CONTAC600{
    private: //각기 다른 기능을 하는 클래스(객체)들이 멤버객체가 되어 캡슐약이라는 클래스에 묶임 -> 캡슐화
        SinivelCap sin;
        SneezeCap sne;
        SnuffleCap snu;
    public:
        void Take() const{
            sin.Take();
            sne.Take();
            snu.Take();
        }
};

class ColdPatient{
    public:
        void TakeCONTAC600(const CONTAC600 &cap) const{ //CONTAC600을 매개변수로 받아서 사용하고있음
            cap.Take();
        }
};

int main(){
    CONTAC600 cap;
    ColdPatient sufferer;

    sufferer.TakeCONTAC600(cap);
    return 0;
}