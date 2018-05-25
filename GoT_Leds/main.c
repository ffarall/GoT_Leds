#include "main.h"

int main (void)
{
/********************INITIALIZATION OF VARIABLES***************************/
    boolean_t isEvent = TRUE;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *background = NULL;
    icon_t starkSigil, targaryenSigil, lannisterSigil, baratheonSigil, arrynSigil, tullySigil, greyjoySigil, tyrellSigil;
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
    
    if(al_init()) 
    {
        if(al_install_keyboard()) 
        {
            timer = al_create_timer(1.0 / FPS);
            if(timer) 
            {
                event_queue = al_create_event_queue();
                if(event_queue) 
                {
                    if(al_init_image_addon())
                    {
                        background = al_load_bitmap(BACKGROUND_GOT);
                        if(background) 
                        {
                              display = al_create_display(DIS_WIDTH, DIS_HEIGHT);
                                if(!display) 
                                {
                                    fprintf(stderr, "failed to create display!\n");
                                    al_destroy_event_queue(event_queue);
                                    al_destroy_timer(timer);
                                    al_destroy_bitmap(background);
                                    return -1;
                                }
                        }
                        else
                        {
                            fprintf(stderr, "failed to create background!\n");
                            al_destroy_event_queue(event_queue);
                            al_destroy_timer(timer);
                            return -1;
                        }
                    }
                    else
                    {
                        fprintf(stderr, "failed to initialize image addon !\n");
                        al_destroy_event_queue(event_queue);
                        al_destroy_timer(timer);
                        return -1;
                    }
                }
                else
                {
                    fprintf(stderr, "failed to create event_queue!\n");
                    al_destroy_timer(timer);
                    return -1;
                }
            }
            else
            {
                fprintf(stderr, "failed to create timer!\n");
                return -1;
            }
        }
        else
        {
            fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
        }
    }
    else
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }


    
    starkSigil.bitmap = al_load_bitmap(STARK_SIGIL);
    if(starkSigil.bitmap)
    {
        targaryenSigil.bitmap = al_load_bitmap(TARGARYEN_SIGIL);
        if(targaryenSigil.bitmap)
        {
            baratheonSigil.bitmap = al_load_bitmap(BARATHEON_SIGIL);
            if(baratheonSigil.bitmap)
            {
                lannisterSigil.bitmap = al_load_bitmap(LANNISTER_SIGIL);
                if(lannisterSigil.bitmap)
                {
                    arrynSigil.bitmap = al_load_bitmap(ARRYN_SIGIL);
                    if(arrynSigil.bitmap)
                    {
                        tullySigil.bitmap = al_load_bitmap(TULLY_SIGIL);
                        if(tullySigil.bitmap)
                        {
                            greyjoySigil.bitmap = al_load_bitmap(GREYJOY_SIGIL);
                            if(greyjoySigil.bitmap)
                            {
                                tyrellSigil.bitmap = al_load_bitmap(TYRELL_SIGIL);
                                if(!tyrellSigil.bitmap)
                                {
                                    fprintf(stderr, "failed to create targaryenSigil!\n");
                                    al_destroy_event_queue(event_queue);
                                    al_destroy_timer(timer);
                                    al_destroy_bitmap(background);
                                    al_destroy_display(display);
                                    al_destroy_bitmap(starkSigil.bitmap);
                                    al_destroy_bitmap(targaryenSigil.bitmap);
                                    al_destroy_bitmap(baratheonSigil.bitmap); 
                                    al_destroy_bitmap(lannisterSigil.bitmap);
                                    al_destroy_bitmap(arrynSigil.bitmap); 
                                }
                            }
                            else
                            {
                                fprintf(stderr, "failed to create targaryenSigil!\n");
                                al_destroy_event_queue(event_queue);
                                al_destroy_timer(timer);
                                al_destroy_bitmap(background);
                                al_destroy_display(display);
                                al_destroy_bitmap(starkSigil.bitmap);
                                al_destroy_bitmap(targaryenSigil.bitmap);
                                al_destroy_bitmap(baratheonSigil.bitmap); 
                                al_destroy_bitmap(lannisterSigil.bitmap);
                                al_destroy_bitmap(arrynSigil.bitmap); 
                            }
                        }
                        else
                        {
                            fprintf(stderr, "failed to create targaryenSigil!\n");
                            al_destroy_event_queue(event_queue);
                            al_destroy_timer(timer);
                            al_destroy_bitmap(background);
                            al_destroy_display(display);
                            al_destroy_bitmap(starkSigil.bitmap);
                            al_destroy_bitmap(targaryenSigil.bitmap);
                            al_destroy_bitmap(baratheonSigil.bitmap); 
                            al_destroy_bitmap(lannisterSigil.bitmap);
                            al_destroy_bitmap(arrynSigil.bitmap);
                        }
                    }
                    else
                    {
                        fprintf(stderr, "failed to create targaryenSigil!\n");
                        al_destroy_event_queue(event_queue);
                        al_destroy_timer(timer);
                        al_destroy_bitmap(background);
                        al_destroy_display(display);
                        al_destroy_bitmap(starkSigil.bitmap);
                        al_destroy_bitmap(targaryenSigil.bitmap);
                        al_destroy_bitmap(baratheonSigil.bitmap); 
                        al_destroy_bitmap(lannisterSigil.bitmap);
                    }
                }
                else
                {
                    fprintf(stderr, "failed to create targaryenSigil!\n");
                    al_destroy_event_queue(event_queue);
                    al_destroy_timer(timer);
                    al_destroy_bitmap(background);
                    al_destroy_display(display);
                    al_destroy_bitmap(starkSigil.bitmap);
                    al_destroy_bitmap(targaryenSigil.bitmap);
                    al_destroy_bitmap(baratheonSigil.bitmap);


                }
            }
            else
            {
                fprintf(stderr, "failed to create targaryenSigil!\n");
                al_destroy_event_queue(event_queue);
                al_destroy_timer(timer);
                al_destroy_bitmap(background);
                al_destroy_display(display);
                al_destroy_bitmap(starkSigil.bitmap);
                al_destroy_bitmap(targaryenSigil.bitmap);
            }
        }
        else
        {
            fprintf(stderr, "failed to create targaryenSigil!\n");
            al_destroy_event_queue(event_queue);
            al_destroy_timer(timer);
            al_destroy_bitmap(background);
            al_destroy_display(display);
            al_destroy_bitmap(starkSigil.bitmap);
        }
    }
    else 
    {
        fprintf(stderr, "failed to create starkSigil!\n");
        al_destroy_event_queue(event_queue);
        al_destroy_timer(timer);
        al_destroy_bitmap(background);
        al_destroy_display(display);
    }
   
    al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background),0, 0, DIS_WIDTH, DIS_HEIGHT, 0);
    al_draw_tinted_scaled_bitmap(starkSigil.bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(starkSigil.bitmap), al_get_bitmap_height(starkSigil.bitmap),LEDS_POS_X, LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    al_draw_tinted_scaled_bitmap(targaryenSigil.bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(targaryenSigil.bitmap), al_get_bitmap_height(targaryenSigil.bitmap), LEDS_POS_X+ICON_WIDTH+25, LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    al_draw_tinted_scaled_bitmap(lannisterSigil.bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(lannisterSigil.bitmap), al_get_bitmap_height(lannisterSigil.bitmap), LEDS_POS_X+2*(ICON_WIDTH+25), LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    al_draw_tinted_scaled_bitmap(baratheonSigil.bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(baratheonSigil.bitmap), al_get_bitmap_height(baratheonSigil.bitmap), LEDS_POS_X+3*(ICON_WIDTH+25), LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    al_draw_tinted_scaled_bitmap(arrynSigil.bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(arrynSigil.bitmap), al_get_bitmap_height(arrynSigil.bitmap), LEDS_POS_X+4*(ICON_WIDTH+25), LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    al_draw_tinted_scaled_bitmap(tullySigil.bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(tullySigil.bitmap), al_get_bitmap_height(tullySigil.bitmap), LEDS_POS_X+5*(ICON_WIDTH+25), LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    al_draw_tinted_scaled_bitmap(greyjoySigil.bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(greyjoySigil.bitmap), al_get_bitmap_height(greyjoySigil.bitmap), LEDS_POS_X+6*(ICON_WIDTH+25), LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    al_draw_tinted_scaled_bitmap(tyrellSigil.bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(tyrellSigil.bitmap), al_get_bitmap_height(tyrellSigil.bitmap), LEDS_POS_X+7*(ICON_WIDTH+25), LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_flip_display();
    al_start_timer(timer);
    
/***************************************************************************
    
    while(event != END_OF_SIM) 
    {
        if(al_get_next_event(event_queue, &event)) 
        {
            if(event.type == ALLEGRO_EVENT_TIMER) 
            {
                
            }
            
            else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
            {
                
            }
            
            else if(event.type == ALLEGRO_EVENT_KEY_CHAR) 
            {
                switch(event.keyboard.unichar) 
                {
                    case '0': ;break;
                    case '1': ;break;
                    case '2': ;break;
                    case '3': ;break;
                    case '4': ;break;
                    case '5': ;break;
                    case '6': ;break;
                    case '7': ;break;
                    case '8': ;break;
                    case '9': ;break;
                    case 'b': ;break;
                }
            }
        }
        
        if(al_is_event_queue_empty(event_queue)) 
        {
            background = al_load_bitmap(BACKGROUND);
            if(!background) 
            {
                fprintf(stderr, "failed to create background!\n");
                al_destroy_event_queue(event_queue);
                al_destroy_timer(timer);
                al_destroy_display(display);
                return -1;  
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
    
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_bitmap(background);
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