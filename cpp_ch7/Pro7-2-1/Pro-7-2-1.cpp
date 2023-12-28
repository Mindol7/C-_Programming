#include <iostream>
using namespace std;

class Rectangle{
    private:
        int x;
        int y;
    public:
        Rectangle(int x1, int y1):x(x1), y(y1){
            cout<<"Rectangle is called!"<<endl;
        }
        void ShowAreaInfo(){
            cout<<"면적: "<<this->x * this->y<<endl;
        }
};

class Square: public Rectangle{
    private:
        int n;
    public:
        Square(int len): Rectangle(len, len),n(len){
            cout<<"Squre is Called!"<<endl;
        }
};


int main(){
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}