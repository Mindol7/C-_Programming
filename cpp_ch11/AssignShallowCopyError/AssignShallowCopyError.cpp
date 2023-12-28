#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        char * name;
        int age;
    public:
        Person(char * myname, int myage):age(myage){
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
        }
        void ShowPersonInfo() const{
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<age<<endl;
        }

        Person& operator=(const Person &ref){
            delete []name; //기존 객체의 메모리 해제
            name = new char[strlen(ref.name)+1];
            strcpy(name, ref.name);
            age = ref.age;
            return *this;
        }
        ~Person(){
            delete []name;
            cout<<"Called Destructor"<<endl;
        }
};

int main(){
    Person man1("Cho", 24);
    Person man2("Song", 23);
    man2 = man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}