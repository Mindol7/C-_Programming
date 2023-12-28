#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0):xpos(x), ypos(y){

        }

        void ShowPosition() const{
            cout<<"Xpos : ,,"<<xpos<<"Ypos : "<<ypos<<endl;
        }
        Point operator*(int times){
            Point pos(xpos*times, ypos*times);
            return pos;
        }
        friend Point operator*(int times, Point &ref);
};

Point operator*(int times, Point& ref){
    return (ref*times); //ref.operator*(3)과 동일
}

int main(){
    Point pos1(10,20);
    Point pos2 = 3*pos1; //operator*(3, pos1)과 동일
    Point pos3 = pos1*3; //pos1.operator*(3)과 동일
    pos3.ShowPosition();
    pos2.ShowPosition();

    pos2 = 2*pos1*3;
    pos2.ShowPosition();
    return 0;
}