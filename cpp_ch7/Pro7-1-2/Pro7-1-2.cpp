#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo{
    private:
        char * name;
        int age;
    public:
        MyFriendInfo(char * friend_name, int friend_age):age(friend_age){
            name = new char[strlen(friend_name)+1];
            strcpy(name, friend_name);
        }
        void ShowMyFriendInfo(){
            cout<<"이름 : "<<name<<endl;
            cout<<"나이 : "<<age<<endl;
        }
        ~MyFriendInfo(){
            delete []name;
            cout<<"Delete MyFriendInfo()"<<endl;
        }
};

class MyFriendDetailInfo: public MyFriendInfo{
    private:
        char * addr;
        char * phone;
    public:
        MyFriendDetailInfo(char * n, int a,char * friend_addr, char * friend_phone):MyFriendInfo(n, a){
            addr = new char[strlen(friend_addr)+1];
            strcpy(addr, friend_addr);
            phone = new char[strlen(friend_phone)+1];
            strcpy(phone, friend_phone);
        }
        void ShowMyFriendDetailInfo(){
            ShowMyFriendInfo();
            cout<<"주소 : "<<addr<<endl;
            cout<<"번호 : "<<phone<<endl;
        }
        ~MyFriendDetailInfo(){
            delete []addr;
            delete []phone;
            cout<<"Delete MyFriendDetailInfo()"<<endl;
        }
};

int main(){
    MyFriendDetailInfo minhyuk("Cho", 24, "Hanam", "2198");
    minhyuk.ShowMyFriendDetailInfo();
    return 0;
}