#include "hadware.h"

void refresh_leds(void)
{
    int ledN;
    
    if(!export_pins())
    {
        printf("Failed to export pins.\n");
    }
    if(!pins_as_output())
    {
        printf("Failed to set pins as output.\n");
    }
    
    for(ledN = 0; ledN < LEDS; ++ledN)
    {
        if(bitGet('A', ledN))
        {
            if(!set_pin(ledN, HIGH))
            {
                printf("Couldn't set pin %d as high.\n", ledN);
            }
        }
        else
        {
            if(!set_pin(ledN, LOW))
            {
                printf("Couldn't set pin %d as low.\n", ledN);
            }
        }
    }
    
    if(!unexport_pins())
    {
        printf("Failed to unexport pins.\n");
    }
}

static boolean_t export_pins(void)
{
    const char *pins[] = {D0, D1, D2, D3, D4, D5, D6, D7};
    int pin;
    int filedesc;
    
    for(pin = 0; pin < LEDS; ++pin)
    {
        filedesc = open(EXPORT_DIR, O_WRONLY | O_APPEND);
        if(filedesc < 0)
        {
            printf("Cannot open export file.\n");
            return FALSE;
        }
        if(write(filedesc, pins[pin], 3) != 3)
        {
            printf("Cannot export pin %s.\n", pins[pin]);    
            return FALSE;
        }
    }
    return TRUE;
}

static boolean_t pins_as_output(void)
{
    const char *pinDirections[] = {D0_DIRECTION, D1_DIRECTION, D2_DIRECTION, D3_DIRECTION, D4_DIRECTION, D5_DIRECTION, D6_DIRECTION, D7_DIRECTION};
    int pin;
    int filedesc;
    
    for(pin = 0; pin < LEDS; ++pin)
    {
        filedesc = open(pinDirections[pin], O_WRONLY | O_APPEND);
        if(filedesc < 0)
            printf("Cannot open pin's %d direction file.\n", pin);
            return FALSE;

        if(write(filedesc, "out", 4) <= 4)
        {
            printf("Cannot set pin %d as output.\n", pin);    
            return FALSE;
        }
    }
    return TRUE;
}

static boolean_t set_pin(int pinN, char state)
{
    const char *pinValues[] = {D0_VALUE, D1_VALUE, D2_VALUE, D3_VALUE, D4_VALUE, D5_VALUE, D6_VALUE, D7_VALUE};
    int filedesc;
    
    filedesc = open(pinValues[pinN], O_WRONLY | O_APPEND);
        if(filedesc < 0)
            printf("Cannot open pin's %d value file.\n", pinN);
            return FALSE;

        if(write(filedesc, state, 2) <= 2)
        {
            printf("Cannot set pin %d as %c.\n", pinN, state);    
            return FALSE;
        }
    
}

static boolean_t unexport_pins(void)
{
    const char *pins[] = {D0, D1, D2, D3, D4, D5, D6, D7};
    int pin;
    int filedesc;
    
    for(pin = 0; pin < LEDS; ++pin)
    {
        filedesc = open(UNEXPORT_DIR, O_WRONLY | O_APPEND);
        if(filedesc < 0)
            printf("Cannot open unexport file.\n");
            return FALSE;

        if(write(filedesc, pins[pin], 3) <= 3)
        {
            printf("Cannot unexport pin %s.\n", pins[pin]);    
            return FALSE;
        }
    }
    return TRUE;
}