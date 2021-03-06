/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef LEDS_SIMULATOR
#define LEDS_SIMULATOR

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "EJ_1.h"
#include "graphic_lib.h"
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "hadware.h"


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define TRUE 1
#define FALSE 0
#define END_OF_SIM 'q'
#define FIN_TABLA 0
#define FPS 60.0
#define DIS_WIDTH 1200
#define DIS_HEIGHT 675
#define BACKGROUND_GOT "GoT_background.jpeg"
#define STARK_SIGIL "Stark.png"
#define TARGARYEN_SIGIL "Targaryen.png"
#define LANNISTER_SIGIL "Lannister.png"
#define BARATHEON_SIGIL "Baratheon.png"
#define ARRYN_SIGIL "Arryn.png"
#define TULLY_SIGIL "Tully.png"
#define GREYJOY_SIGIL "Greyjoy.png"
#define TYRELL_SIGIL "Tyrell.png"
#define MAIN_THEME "Got_theme_song.wav"
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
typedef char boolean_t;
typedef struct state_diagram_edge STATE;

struct state_diagram_edge
{
  char evento;
  STATE *proximo_estado;
  void (*p_rut_accion)(void);
};


/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
void print_port (char);
void act_routine0(void);
void act_routine1(void);
void act_routine2(void);
void act_routine3(void);
void act_routine4(void);
void act_routine5(void);
void act_routine6(void);
void act_routine7(void);
void act_routinet(void);
void act_routinec(void);
void act_routines(void);
void reset_FSM(void);
STATE* leds_fsm(STATE *pstate, char event);
void image_to_display(ALLEGRO_BITMAP *bitmap, const char* filename, float dx, float dy, int flags);


/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
// +ej: char lcd_goto (int fil, int col);+


/*******************************************************************************
 ******************************************************************************/

#endif // LEDS_SIMULATOR
