#include "main.h"

int main (void)
{
/********************INITIALIZATION OF VARIABLES***************************/
    boolean_t isEvent = TRUE;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT event;
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
    
    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_timer(timer);
      return -1;
    }

    display = al_create_display(640, 480);
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_event_queue(event_queue);
        al_destroy_timer(timer);
        return -1;
    }

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_timer_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer();
    
/***************************************************************************/
    
    while(event != END_OF_SIM) {
        if(al_get_next_event(event_queue, &event)) {
            if(event.type == ALLEGRO_EVENT_TIMER) {
                
            }
            
            else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                
            }
            
            else if(event.type == ALLEGRO_EVENT_KEY_UP) {
                switch(event.keyboard.keycode) {
                    case ALLEGRO_KEY_0: ;break;
                    case ALLEGRO_KEY_1: ;break;
                    case ALLEGRO_KEY_2: ;break;
                    case ALLEGRO_KEY_3: ;break;
                    case ALLEGRO_KEY_4: ;break;
                    case ALLEGRO_KEY_5: ;break;
                    case ALLEGRO_KEY_6: ;break;
                    case ALLEGRO_KEY_7: ;break;
                    case ALLEGRO_KEY_8: ;break;
                    case ALLEGRO_KEY_9: ;break;
                }
            }
        }
    }
/*  changemode(BUFFERED_OFF);

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
*/
    
    
    al_destroy_timer(timer);
    al_destroy_display(display);
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