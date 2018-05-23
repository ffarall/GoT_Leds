
#ifndef GETPORT_H
#define GETPORT_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
 #include <stdio.h>
 #include "types_def.h"
 #include <stdint.h>
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
 typedef struct
 {
   void * p2port;
   size_t portsize;
 }portinfo_t;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
 portinfo_t getPort (char);


 /***************************************************************************************************
 FUNCION getPort(): Tiene como objetivo aislar a las estructuras de los puertos del usuario
 Recibe: un caracter que indica el nombre del puerto al que se quiera acceder
 Devuelve:un puntero a void que apunta a el puerto deseado dentro de la estructura
 y NULL en caso de que se haya recibido un caracter invalido
 Requiere: correcta definicion de la estructura "port"
 **************************************************************************************************/



/*******************************************************************************
 ******************************************************************************/

#endif // GETPORT_H
