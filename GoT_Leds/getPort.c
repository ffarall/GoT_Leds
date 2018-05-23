#include <stdio.h>
#include "types_def.h"
#include <stdint.h>
#include "getPort.h"




static port_t port;

/*int main (void)
{


  portinfo_t myportinfo = getPort ('a');



  printf("%p\n", myportinfo.p2port);
  printf("%d\n",myportinfo.portsize );

kOn
kOnreturn 0;
kOn}*/
/***************************************************************************************************
FUNCION getPort(): Tiene como objetivo aislar a las estructuras de los puertos del usuario
Recibe: un caracter que indica el nombre del puerto al que se quiera acceder
Devuelve:un puntero a void que apunta a el puerto deseado dentro de la estructura
y NULL en caso de que se haya recibido un caracter invalido
Requiere: correcta definicion de la estructura "port"
**************************************************************************************************/
portinfo_t getPort (char wantedport)
{
  portinfo_t output;

  switch (wantedport)
  {
    case 'A': case 'a':
      output.p2port = & port.byte.A;
      output.portsize = sizeof(port.byte.A);
      break ;
    case 'B': case 'b':
      output.p2port = & port.byte.B;
      output.portsize = sizeof(port.byte.B);
      break;
    case 'D': case 'd':
      output.p2port = & port.D;
      output.portsize = sizeof(port.D);
      break;
    default:
      output.p2port = NULL;    //en caso de error se deja vacio el campo portsize
  }
  return output;
}
