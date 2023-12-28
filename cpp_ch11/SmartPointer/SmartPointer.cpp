#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0):xpos(x),ypos(y){
            cout<<"Create Object!!!"<<endl;
        }
        ~Point(){
            cout<<"객체 소멸"<<endl;
        }
        void SetPos(int x, int y){
            xpos = x;
            ypos = y;
        }
        friend ostream& operator<<(ostream& os, Point& pos);
};

ostream& operator<<(ostream& os, Point& pos){
    cout<<pos.xpos<<",  "<<pos.ypos<<endl;
    return os;
}

class SmartPtr{
    private:
        Point * posptr;
    public:
        SmartPtr(Point * ptr):posptr(ptr){}

        Point& operator*(){ //참조의 형태로 반환 (가르키는 값을 <객체를> 복사해서)
            return *posptr;
        }
        Point* operator->(){ // 포인터가 가르키는 실제 값을 반환
            return posptr; //포인터에 대한 연산이니까 -> 이걸해주고, 값을 원하니까 * 해준다.
        }
        ~SmartPtr(){
            delete posptr;
        }
};

int main(){
    SmartPtr sptr1 = new Point(1,2);
    SmartPtr sptr2 = new Point(3,4);
    SmartPtr sptr3 = new Point(5,6);

    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;

    sptr1->SetPos(10,20);
    sptr2->SetPos(30,40);
    sptr3->SetPos(50,60);

    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;
    return 0;
}