#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0):xpos(x),ypos(y){

        }
        void ShowPosition(){
            cout<<"Xpos : "<<xpos<<", Ypos : "<<ypos<<endl;
        }
        Point operator-(){
            Point pos(-xpos, -ypos);
            return pos;
        }

        friend Point operator~(const Point &ref);
};

Point operator~(const Point &ref){
    Point pos(-ref.xpos, -ref.ypos);
    return pos; //객체의 복사본이 반환
}

int main(){
    Point pos1(10,20);
    pos1.ShowPosition();
    Point pos2 = -pos1; //pos1.operator-();
    pos2.ShowPosition();
    (~pos2).ShowPosition(); //operator-(pos2);
    pos2.ShowPosition();
    return 0;
}