#ifndef TYPES_DEF
#define TYPES_DEF

#include <stdio.h>
#include <stdint.h>

/* ESTRUCTURAS PARA DEFINIR EL ACUMULADOR D
Para poder acceder a 2 bytes de distintas formas, definir:
port_t <nombrevariable>;
Para acceder a los 2 bytes enteros: <nombrevariable>.D;
Para acceder al bit i de los 2 bytes: <nombrevariable>.D.bi;
Para acceder al byte mas significativo: <nombrevariable>.byte.A
Para acceder al bit i del byte mas siginificativo: <nombrevariable>.byte.A.bi
De la misma forma para el byte menos significativo reemplazar A por B */
typedef struct
{
  uint8_t b0:1;
  uint8_t b1:1;
  uint8_t b2:1;
  uint8_t b3:1;
  uint8_t b4:1;
  uint8_t b5:1;
  uint8_t b6:1;
  uint8_t b7:1;
}eightbits_t;     //para manipulacion bit a bit de un solo byte

typedef struct
{
  eightbits_t B;
  eightbits_t A;
}twobytes_t;    //para tratar a cada byte como un registro en si mismo

typedef struct
{
  uint16_t b0:1;
  uint16_t b1:1;
  uint16_t b2:1;
  uint16_t b3:1;
  uint16_t b4:1;
  uint16_t b5:1;
  uint16_t b6:1;
  uint16_t b7:1;
  uint16_t b8:1;
  uint16_t b9:1;
  uint16_t b10:1;
  uint16_t b11:1;
  uint16_t b12:1;
  uint16_t b13:1;
  uint16_t b14:1;
  uint16_t b15:1;
} sixtnbit_t;    //para manipular bit a bit dos bytes juntos

typedef union
{
  sixtnbit_t D;
  twobytes_t byte;
} port_t;     //para poder manipular dos bytes como acumulador D, o A y B por separado.

#endif
