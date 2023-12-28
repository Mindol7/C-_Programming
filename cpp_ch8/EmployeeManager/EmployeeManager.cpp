#include <iostream>
#include <cstring>
using namespace std;

enum RISK_LEVEL{
    RISK_A      = 30,
    RISK_B      = 20,
    RISK_C      = 10
};

//객체 생성이 불가능한 클래스 -> 추상 클래스
class Employee{
    private:
        char name[100];
    public:
        Employee(char * name){
            strcpy(this->name, name);
        }
        void ShowYourName() const{
            cout<<"name: "<<this->name<<endl;
        }
        /*
        순수 가상함수 (객체 생성이 목적<호출 목적이 아님>
        이 아니라
        클래스들간에 상속관계를 묶어주기 위한
        클래스 속 순수 가상함수)
        
        추상 클래스 라고도 불림
        */
       
        virtual int GetPay() const{
            return 0;
        } //virtual int GetPay() const =0; -> 객체 생성 불가능해짐
        virtual void ShowSalaryInfo() const{
        }
        //virtual int ShowSalaryInfo() const =0;
};

class PermanentWorker:public Employee{
    private:
        int salary;
    public:
        PermanentWorker(char * name, int money): Employee(name), salary(money){

        }
        int GetPay() const{
            return salary;
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout<<"Salary is: "<<GetPay()<<endl<<endl;
        }
};

class TemporaryWorker:public Employee{
    private:
        int workTime;
        int payPerHour;
    public:
        TemporaryWorker(char * name, int pay):Employee(name), workTime(0), payPerHour(pay){

        }
        void AddWorkTimt(int time){
        workTime += time;
        }
        int GetPay() const{
            return workTime*payPerHour;
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout<<"Salary : "<<GetPay()<<endl<<endl;
        }
};

class SalesWorker:public PermanentWorker{
    private:
        int salesResult;
        double bonusRatio; //상여금 비율
    public:
        SalesWorker(char * name, int money, double ratio):PermanentWorker(name, money),salesResult(0),bonusRatio(ratio){}
        void AddSalesResult(int value){ //가상함수 선언할 필요 있음
            salesResult+=value;
        }
        int GetPay() const{
            return PermanentWorker::GetPay()+(int)(salesResult*bonusRatio);
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout<<"Salary: "<<GetPay()<<endl<<endl;
        }
};

class ForeginSalesWorker:public SalesWorker{
    private:
        const int risk_cal;
    public:
        ForeginSalesWorker(char * name, int money, double ratio, int risk):SalesWorker(name, money, ratio),risk_cal(risk){
            
        }
        int GetRiskPay() const{
            return (int)(GetPay() * risk_cal * 0.01);
        }

        int GetPay() const{
            return SalesWorker::GetPay();
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout<<"Salary: "<<GetPay()<<endl;
            cout<<"risk pay : "<<GetRiskPay()<<endl;
            cout<<"sum : "<<GetPay() + GetRiskPay()<<endl<<endl;
        }


};

class EmployeeHandler{
    private:
        Employee * empList[50];
        int empNum;
    public:
        EmployeeHandler():empNum(0){}
        void AddEmployee(Employee * emp){
            empList[empNum++] = emp;
        }
        void ShowAllSalaryInfo() const{
            
            for(int i = 0; i<empNum;i++){
                empList[i]->ShowSalaryInfo(); //가상함수를 통해 포인터가 각각의 객체에 접근가능(오버라이딩)해지면서 호출하게됨
            }
            
        }
        void ShowTotalSalaryInfo() const{
            int sum = 0;
            
            for(int i = 0;i<empNum;i++){
                sum+=empList[i]->GetPay(); //가상함수를 통해 포인터가 각각의 객체에 접근가능(오버라이딩)해지면서 호출하게됨
            }
            
           cout<<"Salary sum: "<<sum<<endl;
        }
        ~EmployeeHandler(){
            for(int i=0;i<empNum;i++){
                delete empList[i];
            }
        }
};

int main(){
    /*
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker("KIM", 1000)); //가상함수를 통해 PermanentWorker 객체가 각각 생성되면서
    handler.AddEmployee(new PermanentWorker("Cho", 5000)); //각각의 함수를 호출하게됨
    handler.AddEmployee(new PermanentWorker("Song", 7000));
    handler.AddEmployee(new SalesWorker("jung", 1234, 0.8)); //가상함수를 통해 마지막으로 오버라이딩된 SalesWorker의 함수가 호출됨
    
    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalaryInfo();
    */

    EmployeeHandler handler;
    ForeginSalesWorker * fseller1 = new ForeginSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeginSalesWorker * fseller2 = new ForeginSalesWorker("Cho", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeginSalesWorker * fseller3 = new ForeginSalesWorker("Song", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();

    return 0;
}