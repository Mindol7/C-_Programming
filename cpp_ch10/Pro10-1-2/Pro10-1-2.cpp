#include <iostream>
using namespace std;

class Point{
    private:
        int xpos;
        int ypos;
    public:
        Point(int x, int y):xpos(x),ypos(y){}
        void ShowInfo(){
            cout<<"xpos : "<<xpos<<"   ypos : "<<ypos<<endl;
        }

        Point& operator+=(const Point &ref){
            xpos += ref.xpos;
            ypos += ref.ypos;
            return *this;
        }
        Point operator-=(const Point &ref){
            Point pos(xpos-=ref.xpos, ypos-=ref.ypos);
            return pos;
        }

        friend bool operator==(const Point &pos1, const Point &pos2);
        friend bool operator!=(const Point &pos1, const Point &pos2);
};

bool operator==(const Point &pos1, const Point &pos2){
    if(pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos){
        return true;
    }
    else{
        return false;
    }
}

bool operator!=(const Point &pos1, const Point &pos2){
    if(pos1.xpos != pos2.xpos && pos1.ypos != pos2.ypos){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Point pos1(10,20);
    Point pos2(30,40);
    (pos1+=pos2).ShowInfo();
    
    Point pos4 = pos1-=pos2;
    pos4.ShowInfo();

    Point pos5 = pos1.operator-=(pos2);
    Point pos6 = pos1-=pos2;
    pos5.ShowInfo();
    pos6.ShowInfo();

    bool b = operator!=(pos1, pos2);
    cout<<"bool : "<<b<<endl;

    bool b2 = operator==(pos1, pos2);
    cout<<"bool : "<<b2<<endl;
    return 0;
}