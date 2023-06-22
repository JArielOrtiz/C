/*
Requerimientos
Implementa una aplicación que decodifique un paquete de TCP/IP.
El paquete de TCP/IP se obtendrá desde una archivo.
El nombre del archivo con el paquete TCP/IP, deberá ser pasado como argumento del ejecutable.
La aplicación deberá ser capaz de diferencias entre los encabezados de IP, TCP y UDP

La información que se mostrara del encabezado de IP es:
    Versión
    Tamaño Cabecera
    Longitud Total
    Protocolo
    Suma de Control de Cabecera
    Dirección IP de origen
    Dirección IP de destino

La información que se mostrara del encabezado de TCP es:
    Puerto de origen
    Puerto de destino
    Número de secuencia
    Número de ACK
    Longitud de la cabecera
    Control
    Checksum
    Datos

La información que se mostrara del encabezado de UDP es:
    Puerto Origen
    Puerto Destino
    Longitud del Mensaje
    Suma de verificación
    Datos
*/

#include <stdio.h>

#define ERROR_NOFILE 1
/* this is how we open a file from the terminal, ./file_name ./file_we_wanna_open 
in this case is ./Tarea_2 ./wanTCP, where "wanTCP" could be replaced by "localhostTCP" and other files
*remenber the files we wanna open must be in the same folder for make this step works: ./file_name ./file_we_wanna_open*/
int main (int argc, char* argv[])   /* char* argv[], donde argv es el identificador de un arreglo de punteros a caracteres  */
{
    FILE *fData;    /* el identificador fData es un puntero para manipular archivos tipo FILE de C */
    int lenData = 0;    /* longitud de los datos */
    unsigned char data [1500];  /* es un arreglo de 1500 elementos de tipo unsigned char (1 byte) con valor de 0 a 255*/

    if(argc > 1)    /* esto es cuando mandamos a llamar desde la linea de comandos */
    {
        printf("%s \n", argv[1]);   
        
        /* fopen es para abrir un archivo, en este caso de lectura binaria (read binari, rb) */
        fData = fopen(argv[1], "rb");   
    }
    else
    {
        /* cuando no se encuentra el archivo a abrir manda este mensaje */
        printf("%s \n", "falta archivo");
        return ERROR_NOFILE;
    }

    // size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
    /* instruccion para leer datos de un archivo abierto y almacenarlos en un arreglo con identificador data, 
    los bytes leidos se almacenan en lenData, maximo leeran 1500 elementos con size de 1 byte (data es unsigned char)
     */
    lenData = fread(data, 1, 1500, fData);

    /* aqui comienza el codigo, sabemos que los datos enviados ya tienen una "direccion" predefinida*/
    printf("\nEl encabezado de IP es:\n");
    /* sabemos que la posicion 14 corresponde a la version, pero la version tiene un size de 4 bits, 
    \por eso hacemos corrimiento para no mostrar el IHL*/
    printf("    -Version: %d\n", (unsigned char)data[14] >> 4);
    /* enmascaramiento (0x es para hexadecimal y 0F es 0000 1111)  para solo mostrar el IHL (Tamaño Cabecera)*/
    printf("    -Tamano Cabecera: %d\n", (unsigned char)data[14] & 0x0F); 
    printf("    -Longitud Total: %d\n", ((unsigned char)data[16]*256) + (unsigned char)data[17]); /* los pasamos a decimal */
    printf("    -Protocolo: %d\n", (unsigned char)data[23]);
    printf("    -Suma de Control de Cabecera: 0x%02x%02x\n", (unsigned char)data[24], (unsigned char)data[25]);
    printf("    -Direccion IP de origen: %d.%d.%d.%d\n", (unsigned char)data[26], (unsigned char)data[27], (unsigned char)data[28], (unsigned char)data[29]);
    printf("    -Direccion IP de destino: %d.%d.%d.%d\n", (unsigned char)data[30], (unsigned char)data[31], (unsigned char)data[32], (unsigned char)data[33]);
    
    /* Para saber si es TCP o UDP */
    if ((unsigned char)data[23] == 06) /* 06 corresponde a TCP */
    {
        printf("\nPara el encabezado de TCP es:\n");
        printf("    -Puerto de origen: %d\n", ((unsigned char)data[34]*256) + (unsigned char)data[35]);
        printf("    -Puerto de destino: %dx\n", ((unsigned char)data[36]*256) + (unsigned char)data[37]);
        /* lo de *256 es para pasarlo a decimal y no dejarlo en hexa, entre mas "datos tengamos se multiplica una vez mas *256, el ultimo dato va sin multiplicar"*/
        printf("    -Numero de secuencia: %u\n", ((unsigned char)data[38]*256*256*256) + ((unsigned char)data[39]*256*256) + ((unsigned char)data[40]*256) + (unsigned char)data[41]);
        /* lo dejamos en unsigned para que no mande numeros negativos */
        printf("    -Numero de ACK: %u\n", ((unsigned char)data[42]*256*256*256) + ((unsigned char)data[43]*256*256) + ((unsigned char)data[44]*256) + (unsigned char)data[45]);
        printf("    -Longitud de la cabecera: %d\n", (unsigned char)data[46] >> 4);   /* se hace un corrimiento para mostrar solo los primeros 4 */
        printf("    -Control: 0x%02x%02x\n", (unsigned char)data[46] & 0x0F, (unsigned char)data[47]); /* se conocen como flags tambien */
        printf("    -Checksum: 0x%02x%02x\n", (unsigned char)data[50], (unsigned char)data[51]);
        /* para los datos: */
        printf("    -Datos: ");
        for(int i = 66; i < lenData; i++)
        {
        printf("%02x ", (unsigned char)data[i]);    /* imprime el valor hexadecimal de 1 byte de cala valor de data */
        }
    }
    else if((unsigned char)data[23] == 17) /* 17 corresponde a UDP */
    {
        printf("\nPara el encabezado de UDP es:\n");
        printf("    -Puerto de origen: %d\n", ((unsigned char)data[34]*256) + (unsigned char)data[35]);
        printf("    -Puerto de destino: %d\n", ((unsigned char)data[36]*256) + (unsigned char)data[37]);
        printf("    -Longitud del Mensaje: %d\n", ((unsigned char)data[38]*256) + (unsigned char)data[39]);
        printf("    -Suma de verificacion: 0x%02x%02x\n", (unsigned char)data[40],  (unsigned char)data[41]);   /* se hace un corrimiento para mostrar solo los primeros 4 */
        printf("    -Datos: ");
        for(int i = 42; i < lenData; i++)
        {
        printf("%02x ", (unsigned char)data[i]);    /* imprime el valor hexadecimal de 1 byte de cala valor de data */
        }
    }
    else
    {
        printf("\nNo corresponde a TCP o UDP...");
    }

    return 0;
}
