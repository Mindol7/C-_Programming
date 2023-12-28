#include <iostream>
using namespace std;

class Car{
    private:
        int gasolineGauge;
    public:
        Car(int g):gasolineGauge(g){
            cout<<"Car is Called"<<endl;
        }
        int GetGasGauge(){
            return gasolineGauge;
        }
};

class HybridCar: public Car{
    private:
        int electricGauge;
    public:
        HybridCar(int g, int h): Car(g), electricGauge(h){
            cout<<"HybridCar is Called"<<endl;
        }
        int GetElecGauge(){
            return electricGauge;
        }
};

class HybridWaterCar: public HybridCar{
    private:
        int waterGauge;
    public:
        HybridWaterCar(int g, int h, int w): HybridCar(g, h),waterGauge(w){ //Car클래스까지 호출할필요 없이 Hybrid만 호출해주면 알아서 해준당
            cout<<"HybridWaterCar is called"<<endl;
        }
        void ShowCurrentGauge(){
            cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
            cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
            cout<<"잔여 워터량: "<<waterGauge<<endl;
        }
};

int main(){
    HybridWaterCar car1(10, 20, 30);
    car1.ShowCurrentGauge();
    return 0;
}