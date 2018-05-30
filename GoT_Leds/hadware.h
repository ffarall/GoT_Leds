/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef HARDWARE
#define HARDWARE

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <glib-2.0/glib.h>
#include <unistd.h>
#include <fcntl.h>
#include "EJ_1.h"



/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define D0 17
#define D1 4
#define D2 18
#define D3 23
#define D4 24
#define D5 25
#define D6 22
#define D7 27
#define EXPORT_DIR "/sys/class/gpio/export"
#define UNEXPOT_DIR "/sys/class/gpio/unexport"
#define LEDS 8
#define HIGH '1'
#define LOW '0'
#define D0_DIRECTION "/sys/class/gpio/gpio17/direction"
#define D1_DIRECTION "/sys/class/gpio/gpio4/direction"
#define D2_DIRECTION "/sys/class/gpio/gpio18/direction"
#define D3_DIRECTION "/sys/class/gpio/gpio23/direction"
#define D4_DIRECTION "/sys/class/gpio/gpio24/direction"
#define D5_DIRECTION "/sys/class/gpio/gpio25/direction"
#define D6_DIRECTION "/sys/class/gpio/gpio22/direction"
#define D7_DIRECTION "/sys/class/gpio/gpio27/direction"
#define D0_VALUE "/sys/class/gpio/gpio17/value"
#define D1_VALUE "/sys/class/gpio/gpio4/value"
#define D2_VALUE "/sys/class/gpio/gpio18/value"
#define D3_VALUE "/sys/class/gpio/gpio23/value"
#define D4_VALUE "/sys/class/gpio/gpio24/value"
#define D5_VALUE "/sys/class/gpio/gpio25/value"
#define D6_VALUE "/sys/class/gpio/gpio22/value"
#define D7_VALUE "/sys/class/gpio/gpio27/value"


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/


// +ej: extern unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
void refresh_leds(void);
static boolean_t export_pins(void);
static boolean_t pins_as_output(void);
static boolean_t set_pin(int pinN, char state);
static boolean_t unexport_pins(void);



/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
// +ej: char lcd_goto (int fil, int col);+


/*******************************************************************************
 ******************************************************************************/

#endif // HARDWARE
