#include <iostream>
#include <cstring>
using namespace std;

class Book{
    private:
        char * title;
        char * isbn; //국제 표준 도서번호
        int price; //가격
    public:
        Book(char * b_title, char * b_isbn, int b_price):price(b_price){
            cout<<"Book is called"<<endl;
            title = new char[strlen(b_title)+1];
            strcpy(title, b_title);

            isbn = new char[strlen(b_isbn)+1];
            strcpy(isbn, b_isbn);
        }
        void ShowBookInfo(){
            cout<<"제목 : "<<title<<endl;
            cout<<"도서 번호 : "<<isbn<<endl;
            cout<<"가격 : "<<price<<endl;
        }
        ~Book(){
            delete []title;
            delete []isbn;
            cout<<"Delete Book"<<endl<<endl;
        }
};

class EBook: public Book{
    private:
        char * DRMkey; //인증 키
    public:
        EBook(char * b_title, char * b_isbn, int b_price, char * b_key)
            :   Book(b_title, b_isbn, b_price){
                cout<<"EBook is called"<<endl;
                DRMkey = new char[strlen(b_key)+1];
                strcpy(DRMkey, b_key);
            }
        void ShowBookInfo_2(){
            ShowBookInfo();
            cout<<"인증 키 : "<<DRMkey<<endl;
        }
        
        ~EBook(){
            delete []DRMkey;
            cout<<"Delete EBook"<<endl<<endl;
        }
};

int main(){
    Book book1("minhyuk", "2198", 10000);
    book1.ShowBookInfo();

    EBook e_book1("songhyun", "0337", 280000, "dwqhiodoi22");
    e_book1.ShowBookInfo_2();
    return 0;
}