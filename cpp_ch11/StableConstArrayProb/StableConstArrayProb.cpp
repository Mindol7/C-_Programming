#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray{
    private:
        int * arr;
        int arrlen;
        BoundCheckIntArray(const BoundCheckIntArray& arr){} //복사와 대입을 원척적으로 막음(배열의 유일성 보장을 위해)
        BoundCheckIntArray& operator=(const BoundCheckIntArray& arr){}
    public:
        BoundCheckIntArray(int len):arrlen(len){
            arr = new int[len];
        }
        int operator[](int idx) const{ //참조자는 const되면서 객체변경이 불가해짐 이를 위해 배열인덱스 연산자가 const됨
                                        //근데 이렇게 되면 배열객체의 저장자체가 불가능해져서 오버로딩이 필요함(const 오버로딩)
            if(idx < 0 || idx >= arrlen){ //int형으로 반환함으로써 참조가 아닌 값만 전달함으로써 객체의 변경이 불가하도록 함
                cout<<"Error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int& operator[](int idx) { 
            if(idx < 0 || idx >= arrlen){
                cout<<"Error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int GetArrlen() const{
            return arrlen;
        }
        ~BoundCheckIntArray(){
            delete []arr;
        }
};

void ShowAllData(const BoundCheckIntArray& ref){
    int len = ref.GetArrlen();
    for(int idx = 0; idx<len;idx++){
        cout<<ref[idx]<<endl;
    }
}

int main(){
    BoundCheckIntArray arr_(5);
    for(int i = 0;i<5;i++){
        arr_[i] = (i+1)*11;
    }
    ShowAllData(arr_);

    return 0;
}