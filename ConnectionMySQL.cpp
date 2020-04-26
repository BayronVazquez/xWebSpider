#include "ConnectionMySQL.h"

ConexionMySQL::ConexionMySQL()
{
    //Default Port and Protocol
    this->PORT  = "3306";
    this->PROTO = "tcp";
    this->IP_SERVER = "127.0.0.1";
}

string ConexionMySQL::getIP_SERVER(){ return this->IP_SERVER; }
string ConexionMySQL::getDATABASE(){ return this->DATABASE; }
string ConexionMySQL::getPASSWORD(){ return this->PASSWORD; }
string ConexionMySQL::getUSERNAME(){ return this->USERNAME; }
string ConexionMySQL::getPROTO(){ return this->PROTO; }
string ConexionMySQL::getPORT(){ return this->PORT; }

void ConexionMySQL::setIP_SERVER(const string &value) { IP_SERVER = value; }
void ConexionMySQL::setDATABASE(const string &value) { DATABASE = value; }
void ConexionMySQL::setPASSWORD(const string &value) { PASSWORD = value; }
void ConexionMySQL::setUSERNAME(const string &value){ USERNAME = value;}
void ConexionMySQL::setPROTO(const string &value) { PROTO = value; }
void ConexionMySQL::setPORT(const string &value) { PORT = value; }

int ConexionMySQL::connectServer()
{
    try {
        this->driver = get_driver_instance();
        this->connection = this->driver->connect( PROTO+"://"+IP_SERVER+":"+PORT, this->USERNAME, this->PASSWORD );

        //Seleccion de la DB
        connection->setSchema(this->DATABASE);

        //Parte del consulta
        this->stmt = this->connection->createStatement();

    } catch (sql::SQLException &e) {
        cout << "ERROR: " << e.what() << endl;
        cout << "MySQL error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

sql::ResultSet* ConexionMySQL::executeQuery(const string &value)
{
    return this->resultset = this->stmt->executeQuery(value);
}

void ConexionMySQL::executeCommand(const string &value){
    this->stmt->execute(value);
}

ConexionMySQL::~ConexionMySQL()
{
    delete stmt;
    delete resultset;
    delete connection;
}
