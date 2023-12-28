#include <iostream>
#include <cstdlib>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0):xpos(x),ypos(y){}
        friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<pos.xpos<<" ,  "<<pos.ypos<<endl;
    return os;
}

typedef Point * POINT_PTR; //point객체를 참조하는 POINT_PTR포인터

class BoundCheckPointPtrArray{
    private:
        POINT_PTR * arr;
        int arrlen;
        BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr){}//아무것도 안하는 복사생성자
        BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr){} //아무것도 안하는 대입연산자
    public:
        BoundCheckPointPtrArray(int len):arrlen(len){
            arr = new POINT_PTR[arrlen]; //point객체를 참조하는 POINT_PTR포인터를 참조하는 arr 이중 포인터(그림을 그리면 이해하기 쉬움)
        }
        POINT_PTR& operator[](int idx){
            if(idx<0 || idx>=arrlen){
                cout<<"Error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        POINT_PTR operator[](int idx) const{
            if(idx<0 || idx>=arrlen){
                cout<<"Error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }

        int GetArrLen() const{
            return arrlen;
        }
        ~BoundCheckPointPtrArray(){
            delete []arr;
        }

};

int main(){ //이중 포인터에 대한 이해,,필요
    BoundCheckPointPtrArray arr_(3); //가르키도록함(객체의 대입, 복사가 아닌 주소값만 반환받음), (주소값을 통한 연산)
    arr_[0] = new Point(3,4); //arr이 아닌 arr[0] 이므로 arr이 가르키는 0번째 인덱스인 POINT_PTR이 Point(3,4) 객체를 가르키도록 함 (논리의 관점)
    arr_[1] = new Point(5,6); //arr_[0]은 arr이 가르키는 첫 번째 포인터 인덱스를 반환 받음(반환받은 포인터에게 Point(3,4)객체 가르키도록 지시) (반환의 관점)
    arr_[2] = new Point(7,8);
    for(int i = 0;i<arr_.GetArrLen();i++){
        cout<<*(arr_[i]); //ex) arr[0]이라면 arr포인터가 가르키는 0번째 인덱스인 POINT_PTR의 주소값을 반환받고 그 주소값이 실질적으로 가르키는 값을 반환받음
    }

    delete arr_[0];
    delete arr_[1];
    delete arr_[2];
    return 0;
}