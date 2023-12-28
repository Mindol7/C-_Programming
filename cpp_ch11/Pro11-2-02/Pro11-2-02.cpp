#include <iostream>
#include <cstdlib>
using namespace std;

//2차원 배열 객체의 생성 매우 어려움 주의 (만약 킬러문제로 시험이 나온다면 이게 나오지 않을까?)
//기본 베이스 : 이중 포인터 사용, 아무것도 안하는 복사생성자, 대입연산자, 2차원 배열의 길이를 열의 길이(col_len)
//IDEA : 먼저 1차원 배열을 생성함, 그리고 각각의 인덱스마다 참조하는 1차원 배열을 하나 더 생성함(그림으로 이해하면 쉬움)

class BoundCheckIntArray{
    private:
        int * arr;
        int arrlen;
        BoundCheckIntArray(const BoundCheckIntArray& arr){}
        BoundCheckIntArray& operator=(const BoundCheckIntArray& arr){}
    public:
        BoundCheckIntArray(int len):arrlen(len){
            arr = new int[arrlen];
        }
        int& operator[](int idx){ 
            if(idx < 0 || idx >= arrlen){
                cout<<"error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int operator[](int idx) const{ 
            if(idx < 0 || idx >= arrlen){
                cout<<"error!"<<endl;
                exit(1);
            }
            return arr[idx];
        }
};

typedef BoundCheckIntArray* BI_PTR; //1차원 배열 객체를 가르키는 포인터

class BountCheck2DIntArray{
    private:
        BI_PTR * arr2d; //여기서 1차원하나 위에서 1차원 하나
        int arrlen;
        BountCheck2DIntArray(const BI_PTR& arr2d){}
        BountCheck2DIntArray& operator=(const BI_PTR& arr2d){}
    public:
        BountCheck2DIntArray(int col, int row):arrlen(col){
            arr2d = new BI_PTR[arrlen];
            for(int i = 0;i<col;i++){
                arr2d[i] = new BoundCheckIntArray(row);
            } //2차원 배열 생성
        }
        BoundCheckIntArray& operator[](int idx){ 
            if(idx < 0 || idx >= arrlen){
                cout<<"error!"<<endl;
                exit(1);
            }
            return *(arr2d[idx]);
        }
        ~BountCheck2DIntArray(){
            for(int i = 0;i<arrlen;i++){
                delete arr2d[i];
            }
            delete []arr2d;
        }
};

int main(){
    BountCheck2DIntArray arr2d(3,4); //세로길이가 3이고, 가로길이가 4인 객체를 만듦

    for(int n = 0;n<3;n++){
        for(int m = 0;m<4;m++){
            arr2d[n][m] = n+m; //2차원 배열에 데이터 저장
        }
    }

    for(int n = 0;n<3;n++){
        for(int m = 0;m<4;m++){
            cout<<arr2d[n][m]<<' ';
        }
        cout<<endl;
    }
    return 0;
}