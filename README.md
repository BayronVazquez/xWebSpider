# xWebSpider
Web Spider.

#### Objetivos:
	* Mapear un sitio WEB
	* Descargar todos los recursos de un Sitio WEB (Imagenes, CSS, JS, etc)
	* Buscar enlaces Rotos (Broken Links)
	* Almacenar y Crear Catalogos en MySQL Server o Maria DB
	* Indexar Sitios WEB
	
#### Dependencias:
	* Lib cURL				https://curl.haxx.se/
	* Boost C++ Libraries			https://www.boost.org/	
	* MySQL C++ Connector			https://dev.mysql.com/downloads/connector/cpp/8.0.html
	* Google V8 JavaScript Engine		https://v8.dev

__Procedimineto de Instalacion__

El objetivo de este proyecto es crear una libreria que te permita incluir las funciones de un web spider 
en tus proyectos cotidianos de la manera mas simple como realizar un #include <xspider>

Para compilar e instalar en tu sistema utilizaremos la herramieta GNU Make, o qmake. Sin embargo aun no 
esta terminado el proyecto y por lo tanto no tiene sentido poder compilarlo, en un futuo se creara el
archivo makefile para realizar la instalacion como la mayoria de los proyectos en github.

__Documentacion de la Clase Spider__


**setDomain( string domain)**

Parametros
	domain: Es un string que indica el FQDN "Fully Qualified Domain Name" Nombre de Dominio completo
	por ejemplo, www.mydominio.com.
Descripcion
	Esta Funcion solo establece el dominio en el cual va a trabajar la spider, para evitar tener que
	estar indicando el dominio en cada peticion se indica una sola vez y se almacena el valor en la 
	clase spider y todas las operaciones posteriores seran en funcion de este dominio a menos que se
	establesca otro diferente de nuevo con esta funcion.

**setPage( string page)**

Parametros
	page: un string que indica la pagina que se quiere consultar ya sea por el procedimiento POST o GET del
	protocolo HTTP.
Descripcion
	NOTA es importante aclarar que el nombre de la pagina debe ser relativo a la ruta del dominio principal,
	por ejemplo, si se quiere pedir la pagina "index.php" del dominio "www.mydomain.com" se llamaria a la 
	funcion de la siguiente manera setPage("index.php");

**setBrowserUserAgent( string agent)**

Descripcion
	Esta Funcion asigna el "user agent" que es un string con informacion del software (navegador web) del
	cliente que se va a incluir en las cabeceras de todas las peticiones posteriores, se incluyo en la clase
	ya que algunos servidores no aceptan peticiones HTTP si esta cabecera no se ha indicado y lo detecta 
	como un BOT.

**setRawCookies( string rawcookie)**

Descripcion
	Indica las cookies que son permantes y no cambian en las peticiones, Por ejemplo: las cookies de session.
	Estas cookies deben estar en formato crudo como se muestra a continuacion: var=valor&var2=valor2. Tambien
	se pueden indicar en la funcion HTTP_Post directamente como parametro pero es recomendable usarlo solo para
	otros datos como los de formularios. Si no entiendes esta funcion investiga como es el formato de las 
	cookies en el siguiente enlace https://curl.haxx.se/docs/http-cookies.html

**setStream( FILE * stream)**

Descripcion
	Indica el stream a donde se van a enviar los datos, el constructor de la clase por default asigna el stream
	stdout (salida por pantalla), si deseas que los datos se escriban en un fichero puedes crear una instancia
	de FILE y pasarle ese puntero a esta funcion para que escriba la informacion en un archivo de texto plano.
	por ejemplo:

	FILE * file;
	file = fopen("page.txt","w+");
	setStream( file );

**HTTP_Get()**

Descripcion
	Realiza una peticion http get al dominio establecido con la funcion setDomain() y pide la pagina establecida
	con la funcion setPage() si no se establece ninguna pagina se solicita el index del dominio.

**HTTP_Post( string DataToPost)**

Descripcion
	Realiza un POST del protocolo HTTP y envia los datos al dominio establecido con la funcion setDomain() y a la
	pagina indica con setPage() los datos que se envian se pasan como argumento y deben estar en formato crudo.
	Mirar el protocolo post y como se envian los datos.

**HTTP_Head()**

Descripcion
	Envia solo los headers.
