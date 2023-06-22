[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-8d59dc4de5201274e310e4c54b9627a8934c3b88527886e3b421487c677d23eb.svg)](https://classroom.github.com/a/SSAmO0-c)

Para esta tarea se cuenta con la siguiente información:

Requerimientos
  
  -Implementa una aplicación que decodifique un paquete de TCP/IP.
  
  -El paquete de TCP/IP se obtendrá desde una archivo.
  
  -El nombre del archivo con el paquete TCP/IP, deberá ser pasado como argumento del ejecutable.
  
  -La aplicación deberá ser capaz de diferencias entre los encabezados de IP, TCP y UDP
  
  -La información que se mostrara del encabezado de IP es:
    
    +Versión
    
    +Tamaño Cabecera
    
    +Longitud Total
    
    +Protocolo
    
    +Suma de Control de Cabecera
    
    +Dirección IP de origen
    
    +Dirección IP de destino
  
  -La información que se mostrara del encabezado de TCP es:
    
    +Puerto de origen
    
    +Puerto de destino
    
    +Número de secuencia
    
    +Número de ACK
    
    +Longitud de la cabecera
    
    +Control
    
    +Checksum
    
    +Datos
  
  -La información que se mostrara del encabezado de UDP es:
    
    +Puerto Origen
    
    +Puerto Destino
    
    +Longitud del Mensaje
    
    +Suma de verificación
    
    +Datos

De acuerdo a lo anterior es como se trabajo para la realizacion de esta tarea, de la línea 35 a la 65 se hace la lectura e interpretación del archivo a decodificar en donde esta toda la información en hexadecimal que no se podra leer con un simple visor de texto como bloc de notas. 
Los protocolos TCP y UDP cuentan con 14 bytes dedicados para el Ethernet, luego viene el encabezado IP con todo lo que se pide en requerimientos. De aqui es cuando se pregunta que tipo de protocolo es; para esto debemos ir a la posicion 23 del arreglo de datos en el archivo "fuente" en donde viene toda la informacion en hexadecimal, comparamos si en esa posicion hay un valor "06" que representa al protocolo TCP o un valor "17" que equivale al protocolo UDP.
Lo que hicimos para imprimir los requerimientos o la información que se debe mostrar nos fijamos en las imagenes de encabezados:
![image](https://user-images.githubusercontent.com/125923972/228697503-1b839d4d-ac52-476f-b3e3-ca78f38628e4.png) IP
![image](https://user-images.githubusercontent.com/125923972/228697861-57e377d0-4325-46d7-bb4c-502dffbc0166.png) TCP
![image](https://user-images.githubusercontent.com/125923972/228697884-58f179a4-d17b-4f58-bc10-5b534fecd529.png) UDP

El encabezado IP tiene un tamaño de 15 bytes de acuerdo a la informacion a mostrar (NOTA: no siempre es este tamaño) para ambos protocolos TCP y UDP, entonces solo quedaba ver las posiciones de la matriz e imprimir esas posiciones para mostrarlos en hexadecimal, para tener su forma digital se hizo la conversión al momento de mostrar el dato con %d o hacer unos calculos para su equivalencia en decimal. 
