#include <iostream>
#include <cstring>
#include "Printer.h"
using namespace std;

void Printer::SetString(const char * str){
    strcpy(print, str);
}

void Printer::ShowString(){
    cout<<print<<endl;
}