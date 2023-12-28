#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num1;
        int num2;
    public:
        SoSimple(int n1, int n2):num1(n1),num2(n2){}
        explicit SoSimple(const SoSimple &copy):num1(copy.num1),num2(-(copy.num2)){ //const의 형태로 전달하는게 좋음, 값이 외부에서 멋대로 변환되면 안되기 때문!
            cout<<"Called SoSimple(SoSimple &copy)"<<endl;
        } //explicit을 통해 sim2 = sim1처럼 저장으로 오해하기 쉬운 형태로 쓰는걸 막음 sim2(sim1) 처럼 인자가 전달되는 형태로 전달되어야함!!

        void ShowSoSimple(){
            cout<<num1<<endl;
            cout<<num2<<endl;
        }
};

int main(){
    SoSimple sim1(15,20); //sim1이라는 객체에 15, 20을 주고 첫 번째 생성자를 통해 객체 생성
    cout<<"생성 및 초기화 직전"<<endl;
    SoSimple sim2(sim1); // SoSimple sim2(sim1); 으로 자동 변환, 평소에도 SoSimple sim2(sim1)으로 작성할 필요 있음,, sim1을 sim2에 복사한다!
                        //근데 그 복사 형태가 우리가 정의할 수 있는 것이다!
    cout<<"생성 및 초기화 직후"<<endl;
    sim2.ShowSoSimple();
    return 0; 
}