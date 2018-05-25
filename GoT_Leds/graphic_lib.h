/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef _TEMPLATE_H_GRAPHIC
#define _TEMPLATE_H_GRAPHIC

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "EJ_1.h"
#include "getPort.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#ifndef _ICON_DEFS
#define _ICON_DEFS
#define GOLD_FILTER 212, 175, 0.5, 1
#define ICON_WIDTH 520.0/4.8
#define ICON_HEIGHT 510.0/4.8
#define LEDS_POS_Y 450
#define LEDS_POS_X 60
#endif


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef const char file_name_t;
typedef struct iconT
{
    ALLEGRO_BITMAP *bitmap;
    float coordinates[2];
    int flags;
    file_name_t* file;
    ALLEGRO_COLOR tint;
    struct iconT *pNextIcon;    
} icon_t;


/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
int refresh_icons(ALLEGRO_DISPLAY* display, icon_t * icon);

/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
// +ej: char lcd_goto (int fil, int col);+


/*******************************************************************************
 ******************************************************************************/

#endif // _TEMPLATE_H_

