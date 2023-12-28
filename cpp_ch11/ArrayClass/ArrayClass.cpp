#include <iostream>
using namespace std;

class BoundCheckIntArray{
    private:
        int * arr;
        int arrlen;
    public:
        BoundCheckIntArray(int len):arrlen(len){
            arr = new int[len];
        }
        int& operator[](int idx){
            if(idx<0 || idx>=arrlen){
                cout<<"Error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        ~BoundCheckIntArray(){
            delete []arr;
        }
};

int main(){
    BoundCheckIntArray arr_(5);
    for(int i = 0;i<5;i++){
        arr_[i] = (i+1)*11;
    }
    for(int i = 0;i<6;i++){
        cout<<arr_[i]<<endl;
    }
    return 0;
}