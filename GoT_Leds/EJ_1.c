#include "EJ_1.h"
#define DEBUG   0

#if DEBUG
int main (void)
{
    maskOn ('A', 0x01);
    maskOn ('A', 0x0A);

    maskOn ('B', 0x0A);
    maskOff ('B', 0x02);

    maskOn ('d', 0x02);
    maskToggle ('d', 0x03);

    return 0;
}
#endif



/***************************************************************************************************
FUNCION bitSet()
Cambia el estado de un bit de un puerto especificado a 1, en caso de ya encontrarse en 1 queda igual
Recibe:un caracter que indica el nombre del puerto al que se quiera acceder y el numero de bit que se quiere cambiar
Devuelve: ---------
Requiere: funcion getPort()
**************************************************************************************************/
void bitSet (char port , int bit)
{
  portinfo_t myportinfo= getPort(port);

  if (myportinfo.portsize == 1)
  {
    *((uint8_t*)myportinfo.p2port) |= (uint8_t) 1 << bit;     //fuerzo el valor del bit utilizando
  }                                                           //mascaras distintas segun si es
  else if (myportinfo.portsize == 2)                          //un puerto de 8 o 16 bits
  {
    *((uint16_t*)myportinfo.p2port) |= (uint16_t) 1 << bit;
  }
}


/***************************************************************************************************
FUNCION bitClr()
Cambia el estado de un bit de un puerto especificado a 0, en caso de ya encontrarse en 0 queda igual
Recibe:un caracter que indica el nombre del puerto al que se quiera acceder y el numero de bit que se quiere cambiar
Devuelve: ---------
Requiere:funcion getPort()
**************************************************************************************************/

void bitClr (char port, int bit)
{
  portinfo_t myportinfo= getPort(port);

  if (myportinfo.portsize == 1)
  {
    *((uint8_t*)myportinfo.p2port) &= ~((uint8_t) 1 << bit); //fuerzo el valor del bit utilizando
  }                                                          //mascaras distintas segun si es
  else if (myportinfo.portsize == 2)                         //un puerto de 8 o 16 bits
  {
    *((uint16_t*)myportinfo.p2port) &= ~((uint16_t) 1 << bit);
  }
}

/***************************************************************************************************
FUNCION bitGet()
devuelve el valor de un bit de un puerto especificado
Recibe:Un caracter que indica el nombre del puerto al que se quiera acceder y el numero de bit que se quiere cambiar
Devuelve: el estado del bit
Requiere:funcion getPort()
**************************************************************************************************/



int bitGet (char port, int bit)
{
  portinfo_t myportinfo= getPort(port);
  int bitvalue;

  if (myportinfo.portsize == 1)
  {
    bitvalue = (*((uint8_t*)myportinfo.p2port) & ((uint8_t) 1 << bit)) ? 1:0;
  }
  else if (myportinfo.portsize == 2)
  {
    bitvalue = (*((uint16_t*)myportinfo.p2port) & ((uint16_t) 1 << bit)) ? 1:0;
  }
  return bitvalue;
}


/***************************************************************************************************
FUNCION bitToggle()
cambia el estado de un bit de un puerto especificado, de 0 a 1 o de 1 a 0, cada vez que es llamada
Recibe:Un caracter que indica el nombre del puerto al que se quiera acceder y el numero de bit que se quiere cambiar
Devuelve: ---------
Requiere:funcion getPort()
**************************************************************************************************/

void bitToggle (char port, int bit)
{
  portinfo_t myportinfo= getPort(port);

  if (myportinfo.portsize == 1)
  {
    *((uint8_t*)myportinfo.p2port) ^= (uint8_t) 1 << bit;
  }
  else if (myportinfo.portsize == 2)
  {
    *((uint16_t*)myportinfo.p2port) ^= (uint16_t) 1 << bit;
  }
}



/************************************************************************************************************************
 * FUNCIÓN maskOn: Dado un puerto y una máscara, debe prender todos aquellos bits que estén prendidos en la máscara,
 * sin cambiar el estado de los restantes
 * Recibe: un caracter indicando el nombre del puerto y una máscara con los bits prendidos de los bits del puerto que 
 * quieren prenderse. Se asume que la máscara será de 16 bits, en caso de trabajar con 8 bits, se castea.
 * Devuelve: nada.
************************************************************************************************************************/  
void maskOn (char port,uint16_t mask)
{
    portinfo_t port_data = getPort (port); /*Se recibe una estructura con el tamaño del puerto y un puntero al puerto*/

    if (sizeof(mask) > port_data.portsize) /*Puertos de 8 bits*/
    {
        #if DEBUG
        printf("%x\n", *(uint8_t*)port_data.p2port);
        #endif
        *(uint8_t*)port_data.p2port |= (uint8_t)mask; /*Se trabajará con un puntero de 8 bits*/
        #if DEBUG
        printf("%x\n", *(uint8_t*)port_data.p2port);
        #endif
    }

    else if (sizeof(mask) == port_data.portsize) /*Puertos de 16 bits*/
    {
        #if DEBUG
        printf("%x\n", *(uint16_t*)port_data.p2port);
        #endif
        *(uint16_t*)port_data.p2port |= mask; /*Se trabajará con un puntero de 16 bits*/
        #if DEBUG
        printf("%x\n", *(uint16_t*)port_data.p2port);
        #endif
    }
}



/************************************************************************************************************************
 * FUNCIÓN maskOff: Dado un puerto y una máscara, debe apagar todos aquellos bits que estén prendidos en la máscara,
 * sin cambiar el estado de los restantes.
 * Recibe: un caracter indicando el nombre del puerto y una máscara con los bits prendidos de los bits del puerto que 
 * quieren prenderse. Se asume que la máscara será de 16 bits, en caso de trabajar con 8 bits, se castea.
 * Devuelve: nada.
************************************************************************************************************************/  
void maskOff (char port,uint16_t mask)
{
    portinfo_t port_data = getPort (port); /*Se recibe una estructura con el tamaño del puerto y un puntero al puerto*/

    if (sizeof(mask) > port_data.portsize) /*Puertos de 8 bits*/
    {
        #if DEBUG
        printf("%x\n", *(uint8_t*)port_data.p2port);
        #endif
        *(uint8_t*)port_data.p2port &= ~(uint8_t)mask; /*Se trabajará con un puntero de 8 bits*/
        #if DEBUG
        printf("%x\n", *(uint8_t*)port_data.p2port);
        #endif
    }

    else if (sizeof(mask) == port_data.portsize) /*Puertos de 16 bits*/
    {
        #if DEBUG
        printf("%x\n", *(uint16_t*)port_data.p2port);
        #endif
        *(uint16_t*)port_data.p2port &= ~mask; /*Se trabajará con un puntero de 16 bits*/
        #if DEBUG
        printf("%x\n", *(uint16_t*)port_data.p2port);
        #endif
    }
}



/************************************************************************************************************************
 * FUNCIÓN maskToggle: Dado un puerto y una máscara, debe cambiar el estado de todos aquellos bits que estén prendidos
 * en la máscara al opuesto, sin cambiar el estado de los restantes
 * Recibe: un caracter indicando el nombre del puerto y una máscara con los bits prendidos de los bits del puerto que 
 * quieren prenderse. Se asume que la máscara será de 16 bits, en caso de trabajar con 8 bits, se castea.
 * Devuelve: nada.
************************************************************************************************************************/  
void maskToggle (char port,uint16_t mask)
{
    portinfo_t port_data = getPort (port); /*Se recibe una estructura con el tamaño del puerto y un puntero al puerto*/

    if (sizeof(mask) > port_data.portsize) /*Puertos de 8 bits*/
    {
        #if DEBUG
        printf("%x\n", *(uint8_t*)port_data.p2port);
        #endif
        *(uint8_t*)port_data.p2port ^= (uint8_t)mask; /*Se trabajará con un puntero de 8 bits*/
        #if DEBUG
        printf("%x\n", *(uint8_t*)port_data.p2port);
        #endif
    }

    else if (sizeof(mask) == port_data.portsize) /*Puertos de 16 bits*/
    {
        #if DEBUG
        printf("%x\n", *(uint16_t*)port_data.p2port);
        #endif
        *(uint16_t*)port_data.p2port ^= mask; /*Se trabajará con un puntero de 16 bits*/
        #if DEBUG
        printf("%x\n", *(uint16_t*)port_data.p2port);
        #endif
    }
}