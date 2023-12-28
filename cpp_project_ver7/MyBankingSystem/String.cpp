#include <iostream>
#include <cstring>
using namespace std;

#include "String.h"

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
    str = tempstr; //객체이름 얕은복사
    return *this;
}

bool String::operator==(const String& ref){
    return strcmp(str, ref.str)?false:true;
}

String String::operator+(const String& ref){
    char * tempstr = new char[len + ref.len -1];
    strcpy(tempstr, str);
    strcat(tempstr, ref.str);

    String temp(tempstr); //복사생성자로 복사본 전달, 문자열 결과는 같아도 메모리는 다름
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
};