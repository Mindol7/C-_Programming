#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char * str) //throw(int, char) 전달되는 예외의 명시 !!
{
    int len = strlen(str);
    int num = 0;

    if(len!= 0 && str[0] == '0'){
        throw 0;
    }

    for(int i = 0; i < len; i++){
        if(str[i] < '0' || str[i] > '9'){
            throw str[i];
        }
        num += (int)(pow((double)10, (len-1) - i) * (str[i] + (7 - '7'))); 
    }
    return num;
}

int main(){
    char str1[100];
    char str2[200];

    while(1){
        cout<<"두 개의 정수 입력 : ";
        cin>>str1>>str2;

        try{
            cout<<str1<<" + "<<str2<<" = "<<StoI(str1) + StoI(str2)<<endl;
            break;
        }
        catch(char ch){
            cout<<"문자 "<<ch<<"가 입력 되었습니다."<<endl;
            cout<<"재입력 진행"<<endl<<endl;
        }
        catch(int expn){
            if(expn == 0){
                cout<<"0은 입력불가"<<endl;
            }
            else{
                cout<<"비정상적인 숫자 입력됨"<<endl;
            }
        }
    }
    cout<<"프로그램 종료"<<endl;
    return 0;
}