#include "Spider.h"

Spider::Spider()
{
    //Configuracion Por Default (Default Configuration)
    HEADERS_ENABLE = true;
    BODY_ENABLE = true;
    CookieFile = "Cookies.txt";
    BrowserUserAgent = "Mozilla/5.0 (X11; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0";
    stream = stdout;

    if ( (curl = curl_easy_init()) != NULL){
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, this->stream);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeDataOnStream);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, this->BrowserUserAgent.c_str());
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, this->CookieFile.c_str());      //For Reading
        curl_easy_setopt(curl, CURLOPT_COOKIEJAR, this->CookieFile.c_str());       //For writing
        curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
    }
}

Spider::~Spider(){
    if( curl != NULL)
        curl_easy_cleanup(curl);
    fclose(stream);
}

string Spider::getDomain(){ return this->Domain; }
string Spider::getPage(){ return this->Page; }
string Spider::getBrowserUserAgent(){ return this->BrowserUserAgent; }
string Spider::getCookieFile(){ return this->CookieFile; }
string Spider::getRawCookies(){return this->RawCookies;}
FILE *Spider::getStream(){ return this->stream; }

void Spider::setDomain(const string &value)
{
    Domain = value;
    curl_easy_setopt(curl, CURLOPT_URL, Domain.c_str());
}

void Spider::setPage(const string &Page)
{
    string uri = Domain + Page;
    curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());
}

void Spider::setBrowserUserAgent(const string &value)
{
    BrowserUserAgent = value;
    curl_easy_setopt(curl, CURLOPT_USERAGENT, BrowserUserAgent.c_str());
}

//Pendiente agregar la documentacion
void Spider::setCookieFile(const string &value)
{
    CookieFile = value;
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, &value);      //For Reading
    curl_easy_setopt(curl, CURLOPT_COOKIEJAR, &value);       //For writing
}

void Spider::setRawCookies(const string &value)
{
    RawCookies = value;
    curl_easy_setopt(curl, CURLOPT_COOKIE, RawCookies.c_str());
}

void Spider::setStream(FILE *value)
{
    stream = value;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stream);
}

void Spider::HTTP_Post(const string &value){
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, value.c_str());
    curlcode = curl_easy_perform(curl);
}

void Spider::HTTP_Get(){
    this->BODY_ENABLE = true;
    this->curlcode = curl_easy_setopt( this->curl, CURLOPT_NOBODY, 0L );    //Indicamos que se incluya el BODY en la Peticion HTTP
    this->curlcode = curl_easy_perform( this->curl );                       //Ejecutamos la Peticion
}

void Spider::HTTP_Head(){
    BODY_ENABLE = false;              this->curlcode = curl_easy_setopt( this->curl, CURLOPT_NOBODY, 1L);
    HEADERS_ENABLE = true;            this->curlcode = curl_easy_setopt( this->curl, CURLOPT_HEADER, 1L);
    curlcode = curl_easy_perform( this->curl );
}

size_t Spider::writeDataOnStream(void * buffer, size_t size, size_t nbytes, void * stream){
    size_t bytes_written = fwrite( buffer, size, nbytes, (FILE *) stream);
    return bytes_written;
}

size_t Spider::extractLinks(void * buffer, size_t size, size_t nbytes, void * stream){
    //size_t bytes_written = fwrite( buffer, size, nbytes, (FILE *) stream);
    return nbytes;
}

void Spider::mapSite(){
}

void Spider::downloadPage(){
}

void Spider::downloadSite(){
}
