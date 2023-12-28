#include <iostream>
#include <cstring>
using namespace std;

template <class T>
T Max(T a, T b){
    return a>b?a:b;
}

template<>
char* Max<char*>(char * a, char * b){
    cout<<"Max<char*>(char * a, char * b) called!!!"<<endl;
    return strlen(a)>strlen(b)?a:b;
}

template<>
const char* Max<const char*>(const char * a, const char * b){
    cout<<"Max<const char*>(const char * a, const char * b) called!!!"<<endl;
    return strlen(a)>strlen(b)?a:b; 
}

int main(){
    cout<<Max(100,200)<<endl;
    cout<<Max(5.4,2.3)<<endl;
    cout<<Max('T', 'Q')<<endl;
    cout<<Max("Minhyuk", "SongHyun")<<endl;

    char str1[] = "Minhyuk";
    char str2[] = "Songhyun";

    cout<<Max(str1, str2)<<endl;
    return 0;
}