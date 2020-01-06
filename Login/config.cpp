#include <windows.h>
#include <mysql.h>

MYSQL* DBConnect();

MYSQL* DBConnect(){
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","123","mca",0,NULL,0);
    return conn;
}
