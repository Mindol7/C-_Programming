#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x , int y ):xpos(x), ypos(y){

        }
        void ShowPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
        Point operator+(const Point &ref){
            Point pos(xpos+ref.xpos, ypos + ref.ypos);
            return pos;
        }

        Point operator-(const Point &ref2){
            Point pos(xpos-ref2.xpos, ypos-ref2.ypos);
            return pos;
        }

        Point operator*(const Point &ref2){
            Point pos(xpos*ref2.xpos, ypos*ref2.ypos);
            return pos;
        }
        Point operator/(const Point &ref2){
            Point pos(xpos/ref2.xpos, ypos/ref2.ypos);
            return pos;
        }
};

int main(){
    Point pos1(3,4);
    Point pos2(10,20);
    Point pos3 = pos1.operator+(pos2);
    Point pos4 = pos1.operator-(pos2);
    Point pos5 = pos1.operator*(pos2);
    Point pos6 = pos1.operator/(pos2);
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    pos4.ShowPosition();
    pos5.ShowPosition();
    pos6.ShowPosition();
    return 0;
}