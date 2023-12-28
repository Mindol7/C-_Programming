#include <iostream>
#include <cstring>
using namespace std;

//복사생성자와 대입연산자는 깊은 관계가 있지만 기존의 메모리를 소멸하고 새롭게 메모리를 할당받는다는 점에서 차이가 있음

class Gun{ //HAS-A 관계에서 깊은 복사
    private:
        int bullet;
    public:
        Gun(int bnum):bullet(bnum){}
        void Shot(){
            cout<<"BBANG!"<<endl;
            bullet--;
        }
};

class Police{
    private:
        int handcuffs; //수갑의 수
        Gun * pistol; //Gun 객체를 참조하는 pistol 포인터
    public:
        Police(int bnum, int bcuff):handcuffs(bcuff){ //생성자
            if(bnum > 0){
                pistol = new Gun(bnum); //총을 총으로써 바라보게 하는 객체의 동적할당
            }
            else{
                pistol = NULL;
            }
        }
        Police(const Police& ref):handcuffs(ref.handcuffs){ //복사생성자의 호출(객체에 대하여 깊은 복사를 진행하는..)
            if(ref.pistol != NULL){
                pistol = new Gun(*(ref.pistol)); //문자열이 아니고 객체니까 그냥 객체를 동적할당만 해주면됨(참조자의 실질적 값만큼)
            } //같은 메모리 아님
            else{
                pistol = NULL;
            }
        }
        void PutHandcuff(){
            cout<<"SNAP!"<<endl;
            handcuffs--;
        }
        void Shot(){
            if(pistol == NULL){
                cout<<"Hut BBANG!"<<endl;
            }
            else{
                pistol->Shot();
            }
        }
        
        Police& operator=(const Police& ref){
            if(pistol != NULL){
                delete pistol; //기존의 메모리 소멸
            }
            if(ref.pistol != NULL){
                pistol = new Gun(*(ref.pistol)); //새로운 메모리 할당
            }
            else{
                pistol = NULL;
            }

            handcuffs = ref.handcuffs;
            return *this;
        }
        
        ~Police(){
            if(pistol != NULL){
                delete pistol;
            }
        }
};

int main(){
    Police pman1(5,3);
    Police pman2(2,4);

    pman2 = pman1;

    pman2.PutHandcuff();
    pman2.Shot();

     
    Police pcpy(pman1); //복사생성자의 호출(복사생성자의 호출로 대입연산자가 진행되어버림)
    pcpy.PutHandcuff();
    pcpy.Shot();
    return 0;
}