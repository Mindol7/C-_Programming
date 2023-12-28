#include <iostream>
#include <cstring>
using namespace std;

class Book{
    private:
        char * title;
        char * isbn;
        int price;
    public:
        Book(char * title, char * isbn, int value):price(value){
            this->title = new char[strlen(title)+1];
            strcpy(this->title, title);
            this->isbn = new char[strlen(isbn)+1];
            strcpy(this->isbn, isbn);
        }
        Book(const Book& ref):price(ref.price){ //복사 생성자(깊은 복사를 진행하는 ,,), 복사생성자의 형식을 잘 봐야할듯
        //메모리를 버리지 않고 바로 새롭게 메모리를 할당함(애초에 객체가 생성될때 메모리가 생성된 객체는 메모리가 없긴햇음)
            this->title = new char[strlen(ref.title)+1];
            strcpy(this->title, ref.title);
            this->isbn = new char[strlen(ref.isbn)+1];
            strcpy(this->isbn, ref.isbn);
        }
         //기초클래스의 대입연산자 정의

        Book& operator=(Book &ref){
            cout<<"Book& operator=() called!"<<endl;
            delete []this->title;
            delete []this->isbn;
            this->title = new char[strlen(ref.title)+1];
            strcpy(this->title, ref.title);
            this->isbn = new char[strlen(ref.title)+1];
            strcpy(this->isbn, ref.isbn);
            price = ref.price;
            return *this;
        }
        void ShowBookInfo(){
            cout<<"제목 : "<<title<<endl;
            cout<<"ISBN : "<<isbn<<endl;
            cout<<"가격 : "<<price<<endl;
        }
        ~Book(){
            delete []title;
            delete []isbn;
        }
};

class EBook: public Book{
    private:
        char * DRMKey;
    public:
        EBook(char * title, char * isbn, int value, char * key):Book(title, isbn, value){
            DRMKey = new char[strlen(key)+1];
            strcpy(DRMKey, key);
        }
        EBook(const EBook& ref):Book(ref){ //복사생성자(깊은복사를 진행하는 ,,)
            DRMKey = new char[strlen(ref.DRMKey)+1];
            strcpy(DRMKey, ref.DRMKey);
        }
        EBook& operator=(EBook &ref){
            Book::operator=(ref); //Book을 상속하고 있는 ref를 전달해줌으로써 ref를 EBook이 아닌 Book으로써도 바라볼수있음(기초클래스의 대입연산자 호출)
            cout<<"EBook& operator=() called!"<<endl;
            delete []DRMKey; //1단계 : 기존의 메모리 해제
            DRMKey = new char[strlen(ref.DRMKey)+1]; //2단계 : 새로운 메모리 할당
            strcpy(DRMKey, ref.DRMKey); //3단계 : 복사를 함으로써 깊은 복사 완료
            return *this; //4단계 : 반환
        }
        void ShowEBookInfo(){
            ShowBookInfo();
            cout<<"인증키 : "<<DRMKey<<endl;
        }
        ~EBook(){
            delete []DRMKey;
        }
};

int main(){
    EBook e1("Halo", "20", 10000, "31231");
    
    EBook e2("H3213alo", "2330", 10000, "323211231");
    EBook cpy(e1); //복사 생성자의 호출로 깊은 복사
    e2 = e1; //대입 연산자로 깊은 복사
    e2.ShowEBookInfo();

    cpy.ShowEBookInfo();
    return 0;
}