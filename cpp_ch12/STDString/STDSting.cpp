#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class String{//초안
    private:
        char * s1;
    public:
        String(){
            s1 = NULL;
        }
        String(char * str){ //생성자 호출
            cout<<"Constructor called ! "<<endl;
            s1 = new char[strlen(str)+1];
            strcpy(s1, str);
        }

        String(const String& ref){ //복사생성자 호출
            cout<<"Copy Constructor called ! "<<endl;
            s1 = new char[strlen(ref.s1)+1];
            strcpy(s1, ref.s1);
        }
        String& operator=(const String& ref){ //대입 연산자 호출
            cout<<"operator=() called ! "<<endl;
            if(s1 != NULL){
                delete s1; //메모리 해제
            }
            s1 = new char[strlen(ref.s1)+1];
            strcpy(s1, ref.s1);
            return *this;
        }
        String& operator+(const String& ref){
            cout<<"operator+() called !"<<endl;
            char * temp = new char[strlen(s1)+strlen(ref.s1)+1];
            temp = s1;
            strcat(ref.s1, temp);
            delete temp;
            return *this;
        }

        String& operator+=(const String& ref){
            cout<<"operator+=() called !"<<endl;
            char * temp = new char[strlen(s1)+strlen(ref.s1)+1];
            strcpy(temp, s1);
            strcat(temp, ref.s1);
            if(s1 != NULL){
                delete s1;
            }
            s1 = temp;
            delete temp;
            return *this;
        }

        bool operator==(const String& ref){
            cout<<"operator==() called !"<<endl;
            return strcmp(s1, ref.s1) ? false:true;
        }
        ~String(){
            cout<<"~String() called !"<<endl;
            if(s1 != NULL){
                delete s1;
            }
        }
        friend ostream& operator<<(ostream& os, const String& str); //전역함수로 선언
        friend istream& operator>>(istream& os, String& str);
};

ostream& operator<<(ostream& os, const String& str){
    os<<"operator<<(,) called!"<<endl;
    os<<str.s1;
    return os;
}

istream& operator>>(istream& is, String& str){
    is>>str.s1;
    cout<<"operator>>(,) called!"<<endl;
    return is;
}


int main(){
    String str1 = "I like ";
    String str2 = "SongHyun so much";
    String str3;
    String str5 = "minhyuk";
    /*
    string str1 = "I like ";
    string str2 = "SongHyun so much";
    string str3;
    str3 = str1 + str2; //어떻게 operator+가 정의되어 있을까? -> 일단 해결
    */
   
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1 += str2;
    if(str1 == str3){
        cout<<"Same !"<<endl;
    }
    else{
        cout<<"Diffrent !"<<endl;
    }
    str1 = str5;
    cout<<str1<<endl;
    String str4;
    cout<<"Input your string : ";
    cin>>str4;
    cout<<"String is : "<<str4<<endl;
    return 0;
}