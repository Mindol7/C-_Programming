#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS{
    enum{
        CLERK       = 4,
        SENIOR      = 3,
        ASSIST      = 2,
        MANAGE      = 1
    };
}

class NameCard{
    private:
        char * name;
        char * company_name;
        char * phone_number;
        int rank;
        char his_rank[10];
    public:
        NameCard(char * n, char * c, char * p, int r):rank(r){
            name = new char[strlen(n)+1];
            strcpy(name, n);

            company_name = new char[strlen(c)+1];
            strcpy(company_name, c);

            phone_number = new char[strlen(p)+1];
            strcpy(phone_number, p);

            switch (rank)
            {
            case 4:
                strcpy(his_rank, "사원");
                break;
            case 3:
                strcpy(his_rank, "주임");
                break;
            case 2:
                strcpy(his_rank, "대리");
                break;
            case 1:    
                strcpy(his_rank, "과장");
                break;
            }
        }
        void ShowNameCardInfo() const{
            cout<<"Name : "<<name<<endl;
            cout<<"Company : "<<company_name<<endl;
            cout<<"Phone : "<<phone_number<<endl;
            cout<<"Rank : "<<his_rank<<endl;
            cout<<endl;
        }

        ~NameCard(){
            delete []name;
            delete []company_name;
            delete []phone_number;
        }
};

int main(){
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodCamp", "010-5555-6666", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
   
    return 0;
}