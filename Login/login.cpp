#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <conio.h>  // perintah getch() terkait dgn library ini
#include <stdlib.h>  // perintah system("cls") terkait dengan library ini
#include "md5.h"
using namespace std;
void MenuUtama();
void LogInForm();
void LogIn();
MYSQL* DBConnect();


void LogIn(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES *res;
    MD5 md5;
    int qstate;
    long baris;
    string uname,pwd, en_pwd;

system("cls");
    cout<< "        APLIKASI PERPUSTAKAAN UMC        \n";
    cout<< " ----------------------------------------\n";
    cout<< "               USER LOGIN                \n";
    cout<< " ----------------------------------------\n";



    cout<<"enter Username: "<<endl; cin>>uname;
    cout<<"enter Password: "<<endl; cin>>pwd;
    char* p = const_cast<char*>(pwd.c_str());

    en_pwd=md5.digestString(p);

    string query="select * from user where username='"+uname+"' and pwd='"+en_pwd+"'";
    const char* q = query.c_str();
    qstate = mysql_query(conn,q);
    res = mysql_store_result(conn);
    baris=mysql_num_rows(res);

    if(baris>0){
        MenuUtama();
    } else {
        cout << "Login Not Valid" << endl;
    }

}

void LogInForm(){
    int choice;
MYSQL* a;
a=DBConnect();
system("cls");
    do
    {
        cout << endl
        << "        APLIKASI PERPUSTAKAAN UMC        \n"
        << " ----------------------------------------\n"
        << " 1 - Login.\n"
        << " 2 - Exit.\n"
        << " Pilihan Anda (1 / 2) dan tekan Enter: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            LogIn(a);
        break;
        case 2:
            cout << "End of Program.\n";
        break;
        default:
        cout << "Not a Valid Choice. \n"
        << "Choose again.\n";
        break;
        }

}while (choice !=2);

}
