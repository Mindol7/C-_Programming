#include <iostream>
using namespace std;

class Point{
    private:
        int xpos; //중심
        int ypos;
    public:
        Point(const int &x1, const int &y1){
            xpos = x1;
            ypos = y1;
        }
        void ShowPointInfo() const{
            cout<<"["<<xpos<<"," <<ypos<<"]"<<endl;
        }
};

class Circle{
    private:
        Point circle_point;
        int radius;
    public:
        Circle(const int &x, const int &y, int &r):circle_point(x, y){
            radius = r;
        }
        void ShowCircleInfo() const{
            cout<<"radius : "<<radius<<endl;
            circle_point.ShowPointInfo();
        }
};

class Ring{
    private:
        Circle circle;
        Circle circle2;
    public:
        Ring(const int &xp1, const int &yp1, int r1, const int &xp2, const int &yp2, int r2):circle(xp1, yp1, r1),circle2(xp2, yp2, r2){};
        void ShowRingInfo() const{
            cout<<"Inner Circle Info ..."<<endl;
            circle.ShowCircleInfo();
            cout<<"Outter Circle Info ..."<<endl;
            circle2.ShowCircleInfo();
        }
};

int main(){
    Ring ring(2,3,4,20,30,40);
    ring.ShowRingInfo();
    return 0;
}