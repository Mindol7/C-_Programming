#include <iostream>
using namespace std;

template <class T>
class Point{
    private:
        T xpos, ypos;
    public:
        Point(T x = 0, T y = 0):xpos(x), ypos(y){}
        void ShowPosition() const{
            cout<<xpos<<",   "<<ypos<<endl;
        }

        friend Point<int> operator+(const Point<int>&, const Point<int>&);
        friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2){
    Point<int> pos3;
    pos3.xpos = pos1.xpos + pos2.xpos;
    pos3.ypos = pos1.ypos + pos2.ypos;
    return pos3;
}

ostream& operator<<(ostream& os, const Point<int>& pos){
    os<<pos.xpos<<",   "<<pos.ypos;
    return os;
}

int main(){
    Point<int> pos1(10,20);
    Point<int> pos2(100,200);
    Point<int> pos3(pos1+pos2);
    cout<<pos1<<endl;
    cout<<pos2<<endl;
    cout<<pos1+pos2<<endl;
    cout<<pos3<<endl;
    return 0;
}