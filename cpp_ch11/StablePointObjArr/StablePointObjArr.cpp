#include <iostream>
#include <cstdlib>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0):xpos(x),ypos(y){

        }
        friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<pos.xpos<<"  ,   "<<pos.ypos<<endl;
    return os;
}

class BoundCheckPointArray{
    private:
        Point * arr;
        int arrlen;
        BoundCheckPointArray(const BoundCheckPointArray& arr){} //복사와 대입을 원척적으로 막음(배열의 유일성 보장을 위해)
        BoundCheckPointArray& operator=(const BoundCheckPointArray& arr){}
    public:
        BoundCheckPointArray(int len):arrlen(len){
            arr = new Point[len];
        }
        Point operator[](int idx) const{ //참조자는 const되면서 객체변경이 불가해짐 이를 위해 배열인덱스 연산자가 const됨
                                        //근데 이렇게 되면 배열객체의 저장자체가 불가능해져서 오버로딩이 필요함(const 오버로딩)
            if(idx < 0 || idx >= arrlen){ //int형으로 반환함으로써 참조가 아닌 값만 전달함으로써 객체의 변경이 불가하도록 함
                cout<<"Error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        Point& operator[](int idx) { 
            if(idx < 0 || idx >= arrlen){
                cout<<"Error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int GetArrlen() const{
            return arrlen;
        }
        ~BoundCheckPointArray(){
            delete []arr;
        }
};

int main(){
    BoundCheckPointArray arr(3);
    arr[0] = Point(1,2);
    arr[1] = Point(3,4);
    arr[2] = Point(5,6);

    for(int i = 0; i<arr.GetArrlen();i++){
        cout<<arr[i];
    }
    return 0;
}