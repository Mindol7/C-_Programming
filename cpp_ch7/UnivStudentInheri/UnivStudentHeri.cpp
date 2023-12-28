#include <iostream>
#include <cstring>
using namespace std;

class Person{ //사람에 대한 클래스(기초클래스)
    private:
        int age;
        char name[50];
    public:
        Person(int myage, char * myname):age(myage){
            strcpy(name, myname);
        }
        void WhatYourNAme() const{
            cout<<"MY name is "<<name<<endl;
        }
        void HowOldAreYou() const{
            cout<<"My old is "<<age<<endl;
        }
};

class UnivStudent:public Person{ //사람 클래스를 상속하여 대학생 클래스 객채 정의
    private:
        char major[50];
    public:
        UnivStudent(char * myname, int myage, char * mymajor) //생성자를 호출할때 기초클래스의 생성자의 인자를 전달해서 기초클래스로 전달해준다
        //생성자는 각자 호출하도록 명시해주는 것임
            :   Person(myage, myname){
                strcpy(major, mymajor);
            }
        void WhoAreYou() const{
            WhatYourNAme();
            HowOldAreYou();
            cout<<"My major is "<<major<<endl<<endl;
        }
};

int main(){
    UnivStudent ustud1("Lee", 21, "Computer eng");
    ustud1.WhoAreYou();

    UnivStudent ustud2("Cho", 24, "Mobile eng");
    ustud2.WhoAreYou();
    return 0;
}