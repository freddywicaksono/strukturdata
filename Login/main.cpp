#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <conio.h>  // perintah getch() terkait dgn library ini
#include <stdlib.h>  // perintah system("cls") terkait dengan library ini
using namespace std;
void MenuUtama();
void LogInForm();
void LogIn();
MYSQL* DBConnect();


int main()
{

    LogInForm();

return 0;
}
