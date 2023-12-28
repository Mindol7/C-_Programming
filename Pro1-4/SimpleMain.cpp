#include <iostream>
using namespace std;

class Plus{
    private:
        int num1, num2, sum;
    public:
        Plus(){}
        bool set_value(int n1, int n2){
            num1 = n1;
            num2 = n2;
            if(num1 == 0 && num2 == 0){
                return false;
            }
            else{
                return true;
            }
        }
        void sum_value(){
            sum = num1 + num2;
        }
        
        int show_info(){
            return sum;
        }
};

int main(){
    int a[10], b[10], count = 0;
    bool test;
    Plus * ptr = new Plus[10];
    while(true){
        cin>>a[count]>>b[count];
        test = ptr[count].set_value(a[count], b[count]);
        ptr[count].sum_value();
        if(!test){
            break;
        }
        count++;
    }

    for(int i = 0; i < count; i++){
        cout<<ptr[i].show_info()<<endl;
    }
    return 0;
}