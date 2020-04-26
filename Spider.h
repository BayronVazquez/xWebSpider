#ifndef SPIDER_H
#define SPIDER_H

#include <iostream>
#ifndef STRING_H
    #define STRING_H
    #include <string>
#endif
#include <curl/curl.h>

using namespace std;

class Spider
{
private:
    CURLcode curlcode;              //Codigos de Respuesta se Usa para manejar Errores
    CURL * curl;                    //Curl Handler instancia de la clase curl para hacer las peticiones HTTP
    FILE * stream;                  //Stream a donde se envian los datos (Archivos, Consola, etc) por default es STDOUT

    bool HEADERS_ENABLE;            //Valor logico que indica si los headers deben mostrarse en las Peticiones HTTP
    bool BODY_ENABLE;               //Valor Logico que indica si el body de las peticiones HTTP deben mostarse

    //Variables de Configuracion
    string Domain;                  //Indica el Dominio (URL)
    string Page;                    //Pagina en la cual se va a hacer la Peticion HTTP
    string BrowserUserAgent;        //User Agent a usar por default tiene el de mozilla firefox para evitar ser detectado como un bot
    string CookieFile;              //Archivo que almacena las cookies para lectura y escritura
    string RawCookies;              //Cookies alamacenadas en memoria las demas estan el fichero CookieFile
public:
    Spider();
    ~Spider();

    void setDomain(const string &DomainName);                   string getDomain();
    void setPage(const string &Page);                           string getPage();
    void setBrowserUserAgent(const string &BrowserAgent);       string getBrowserUserAgent();
    void setCookieFile(const string &CookieFile);               string getCookieFile();
    void setRawCookies(const string &RawCookies);               string getRawCookies();
    void setStream(FILE *value);                                FILE* getStream();

    //Peticiones HTTP Disponibles
    void HTTP_Post(const string &DataToPost);   // Realiza Peticion HTTP POST
    void HTTP_Get();                            // Realiza la Peticion HTTP GET
    void HTTP_Head();                           // Solo envia Headers

    //Pendiente Por Crear las 3 funciones
    void mapSite();
    void downloadPage();
    void downloadSite();
private:
    static size_t writeDataOnStream(void * buffer, size_t size, size_t nbytes, void * stream);
    static size_t extractLinks(void * buffer, size_t size, size_t nbytes, void * stream);
};
#endif // SPIDER_H
