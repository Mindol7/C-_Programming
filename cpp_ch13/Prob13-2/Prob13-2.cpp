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

template <class T> 
class SmartPtr{ //클래스에 대한 템플릿 느낌있음
    private:
        T * posptr;
    public:
        SmartPtr(T * ptr);
        T& operator*();
        T* operator->();
        ~SmartPtr();
};

template <class T>
SmartPtr<T>::SmartPtr(T * ptr):posptr(ptr){}

template <class T>
T& SmartPtr<T>::operator*(){
    return *posptr;
}

template <class T>
T* SmartPtr<T>::operator->(){
    return posptr;
}

template <class T>
SmartPtr<T>::~SmartPtr(){
    delete posptr;
}



int main(){
    
    SmartPtr<Point> sptr2 = new Point(10,20);
    cout<<*sptr2;
    SmartPtr<Point> sptr4 = new Point(100,200);
    cout<<*sptr4;

    sptr2->SetPos(1,2);
    sptr4->SetPos(3,4);

    cout<<*sptr2;
    cout<<*sptr4;

    return 0;
}