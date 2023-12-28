#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        char * name;
        int age;
    public:
        Person(char * myname, int myage):age(myage){
            int len = strlen(myname)+1;
            name = new char[len];
            strcpy(name, myname);
        }
        //디폴트 복사 생성자(우리 눈에는 안보임)

        Person(Person &copy){ //깊은 복사를 하는 복사생성자(디폴트 아님)
            name = new char[strlen(copy.name)+1]; //복사생성자의 내용을 우리가 정의함으로써 깊은 복사 수행!
            strcpy(name, copy.name);
        }

        void ShowPersonInfo() const{
            cout<<"이름 : "<<name<<endl;
            cout<<"나이 : "<<age<<endl;
        }

        ~Person(){ //소멸자 ~Person()에서 이론상 두번 호출되면서 두번 삭제되어야하는데 한번만 호출되면서 에러가 발생하게됨 ---> 깊은 복사가 필요
            delete []name;
            cout<<"Called Destructor"<<endl;
        }
};


int main(){
    Person man1("Cho Min Hyuk", 24);
    Person man2(man1);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}