#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x, int y):xpos(x),ypos(y){}
        void ShowPosition() const{ //const 멤버함수 -> 값을 변경하지 않는다는 의지 보여줌
            cout<<'['<<xpos<<",  "<<ypos<<']'<<endl;
        }

        Point& operator++(){
            xpos+=1;
            ypos+=1;
            return *this;
        }
        friend Point& operator--(Point &ref);
};

Point& operator--(Point &ref){
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

int main(){
    Point pos(1,2);
    ++pos;
    pos.ShowPosition();
    --pos; 
    pos.ShowPosition();

    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();

    return 0;
}