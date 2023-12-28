#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x, int y):xpos(x),ypos(y){}
        friend ostream& operator<<(ostream& os, const Point& pos);

        void* operator new(size_t size){ //메모리 할당을 직접 오버로딩 해줘야함
            cout<<"operartor new(size_t size) called!"<<endl;
            void * ptr = new char[size];
            return ptr;
        }

        void operator delete(void * ptr){
            cout<<"operator delete(void * ptr) called!"<<endl;
            delete []ptr;
        }
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<pos.xpos<<",  "<<pos.ypos<<endl;
    return os;
}
int main(){
    Point * p1 = new Point(3,4);
    cout<<*p1<<endl; //p1이 가르키고 있는 객체를 넘겨줌
    delete p1;
    return 0;
}