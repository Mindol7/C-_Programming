#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0):xpos(x), ypos(y){

        }
        void ShowPosition() const{
            cout<<"Xpos : "<<xpos<<",, Ypos : "<<ypos<<endl;
        }

        Point& operator++(){ //전위 증가
            xpos +=1;
            ypos +=1;
            return *this;
        }

        const Point operator++(int){ //(복사된 객체를 반환하니까 & 붙지 않음)
            const Point pos(xpos, ypos);
            xpos +=1;
            ypos +=1;
            return pos; //값을 반환하고 1씩 증가됨
        }

        friend Point& operator--(Point &ref);
        friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref){ //전위 감소 (참조자를 반환하니까 &가 붙음)
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point operator--(Point &ref, int){ //후위 감소 (복사된 객체를 반환하니까 & 붙지 않음)
    const Point pos(ref); //후위감소할때 객체를 생성하는 이유는 알겠음
    ref.xpos -= 1;          //근데 const를 해도되는것인지?
    ref.ypos -= 1;          
    return pos;
}

int main(void){
    Point pos(3,5);
    Point cpy;
    Point obj;
    cpy = pos--; //후위 감소
    cpy.ShowPosition();
    pos.ShowPosition();

    //(pos++)++ 컴파일 에러나는 이유를 알겠음 (반환되는 객체가 const인데 그다음 호출되는 함수는 const가 아님)

    cpy = pos++; //후위 증가
    cpy.ShowPosition();
    pos.ShowPosition();
    return 0;
}