#include "leds_simulator.h"

int main (void)
{
  boolean_t isEvent = TRUE;
  char event;
  STATE states_array[] =
  {
    {'0',states_array,act_routine0},
    {'1',states_array,act_routine1},
    {'2',states_array,act_routine2},
    {'3',states_array,act_routine3},
    {'4',states_array,act_routine4},
    {'5',states_array,act_routine5},
    {'6',states_array,act_routine6},
    {'7',states_array,act_routine7},
    {'t',states_array,act_routinet},
    {'c',states_array,act_routinec},
    {'s',states_array,act_routines},
    {FIN_TABLA,states_array,reset_FSM},
  };
  STATE *p_state = &states_array[0];

  changemode(BUFFERED_OFF);

  while (event != END_OF_SIM )
  {

    if ((isEvent = kbhit()))
    {
      event = getch();
      p_state = leds_fsm(p_state, event);

      print_port('A');
    }

  }

  changemode(BUFFERED_ON);

  printf("Simulación terminada\n");

  return 0;
}



/*********************************************************************************************************
                                    INTÉRPRETE FSM
*********************************************************************************************************/
STATE* leds_fsm(STATE *p_state, char event)
{
  while (p_state->evento != event && p_state->evento != FIN_TABLA)
  {
    ++p_state;
  }

  (*p_state->p_rut_accion)();
  p_state = p_state->proximo_estado;

  return(p_state);
}



/*********************************************************************************************************
                                    RUTINAS DE ACCIÓN
*********************************************************************************************************/
void act_routine0(void)
{
  bitToggle('A', 0);
}

void act_routine1(void)
{
  bitToggle('A', 1);
}

void act_routine2(void)
{
  bitToggle('A', 2);
}

void act_routine3(void)
{
  bitToggle('A', 3);
}

void act_routine4(void)
{
  bitToggle('A', 4);
}

void act_routine5(void)
{
  bitToggle('A', 5);
}

void act_routine6(void)
{
  bitToggle('A', 6);
}

void act_routine7(void)
{
  bitToggle('A', 7);
}

void act_routinet(void)
{
  maskToggle('A', 0xFF);
}

void act_routinec(void)
{
  maskOff('A', 0xFF);
}

void act_routines(void)
{
  maskOn('A', 0xFF);
}

void reset_FSM(void)
{

}

/*******************************************/

STATE states_array[] =
{
  {'0',states_array,act_routine0},
  {'1',states_array,act_routine1},
  {'2',states_array,act_routine2},
  {'3',states_array,act_routine3},
  {'4',states_array,act_routine4},
  {'5',states_array,act_routine5},
  {'6',states_array,act_routine6},
  {'7',states_array,act_routine7},
  {'t',states_array,act_routinet},
  {'c',states_array,act_routinec},
  {'s',states_array,act_routines},
  {FIN_TABLA,states_array,reset_FSM},
};