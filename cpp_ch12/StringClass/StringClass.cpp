#include <iostream>
#include <cstring>
using namespace std;

class String{
    private:
        int len;
        char * str;
    public:
        String();
        String(const char * ref);
        String(const String& ref);
        ~String();
        String& operator=(const String& ref);
        String& operator+=(const String& ref);
        bool operator==(const String& ref);
        String operator+(const String& ref);

        friend ostream& operator<<(ostream& os, const String& ref);
        friend istream& operator>>(istream& is, String& ref);
};

String::String(){
    int len = 0;
    str = NULL;
}

String::String(const char * s){
    len = strlen(s) + 1;
    str = new char[len];
    strcpy(str, s);
}

String::String(const String& ref){
    len = ref.len;
    str = new char(len+1);
    strcpy(str, ref.str);
}

String::~String(){
    if(str != NULL){
        delete []str;
    }
}

String& String::operator=(const String& ref){
    len = ref.len;
    if(str != NULL){
        delete []str;
    }
    str = new char[len+1];
    strcpy(str, ref.str);
    return *this;
}

String& String::operator+=(const String& ref){
    len += (ref.len - 1); //\n을 생각하여 1칸 제거
    char * tempstr = new char[len];
    strcpy(tempstr, str);
    strcat(ref.str, tempstr);

    if(str != NULL){
        delete []str;
    }
    str = new char[len]; //의심
    str = tempstr;
    delete []tempstr;
    return *this;
}

bool String::operator==(const String& ref){
    return strcmp(str, ref.str)?false:true;
}

String String::operator+(const String& ref){
    char * tempstr = new char[len + ref.len -1];
    strcpy(tempstr, str);
    strcat(tempstr, ref.str);

    String temp(tempstr);
    delete []tempstr;
    return temp;
}

ostream& operator<<(ostream& os, const String& ref){
    os<<ref.str;
    return os;
}

istream& operator>>(istream& is, String& ref){
    char str[100];
    is>>str;
    ref = String(str); //이름 없는 임시객체 전달
    return is;
}

int main(){
    String str1 = "I like ";
    String str2 = "Songhyun";
    String str3 = str1 + str2;

    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1 += str2;
    if(str1 == str3){
        cout<<"Same!"<<endl;
    }
    else{
        cout<<"Diff!"<<endl;
    }

    String str4;
    cout<<"Input : ";
    cin>>str4;
    cout<<"String is : "<<str4<<endl;
    return 0;
}