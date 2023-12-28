#include <iostream>
#include <cstring>
using namespace std;

class Person{ //사람에 대한 클래스(기초클래스)
    private:
         char * name;
    public:
        Person(char * myname){
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
        }
        ~Person(){
            delete []name;
        }
        void WhatYourNAme() const{
            cout<<"MY name is "<<name<<endl;
        }
};

class UnivStudent:public Person{ //사람 클래스를 상속하여 대학생 클래스 객채 정의
    private:
        char * major;
    public:
        UnivStudent(char * myname, char * mymajor) //생성자를 호출할때 기초클래스의 생성자의 인자를 전달해서 기초클래스로 전달해준다
        //생성자는 각자 호출하도록 명시해주는 것임
            :   Person(myname){
                major = new char[strlen(mymajor)+1];
                strcpy(major, mymajor);
            }
        void WhoAreYou() const{
            WhatYourNAme();
            cout<<"My major is "<<major<<endl<<endl;
        }
};

int main(){
    UnivStudent ustud1("Lee", "Computer eng");
    ustud1.WhoAreYou();

    UnivStudent ustud2("Cho", "Mobile eng");
    ustud2.WhoAreYou();
    return 0;
}