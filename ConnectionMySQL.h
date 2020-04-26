#ifndef ConexionMySQL_H
#define ConexionMySQL_H

#ifndef STRING_H
    #define STRING_H
    #include <string>
#endif
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class ConexionMySQL
{
private:
    string USERNAME;
    string PASSWORD;
    string DATABASE;
    string IP_SERVER;
    string PROTO;
    string PORT;

    sql::Driver * driver;
    sql::Connection * connection;
    sql::Statement * stmt;
    sql::ResultSet * resultset;
public:
    ConexionMySQL();

    string getIP_SERVER();
    string getDATABASE();
    string getPASSWORD();
    string getUSERNAME();
    string getPROTO();
    string getPORT();

    void setIP_SERVER(const string &value);
    void setDATABASE(const string &value);
    void setPASSWORD(const string &value);
    void setUSERNAME(const string &value);
    void setPROTO(const string &value);
    void setPORT(const string &value);

    int connectServer();
    sql::ResultSet* executeQuery(const string &value);
    void executeCommand(const string &value);

    ~ConexionMySQL();
};

#endif // ConexionMySQL_H
