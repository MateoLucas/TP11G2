#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "port.h"
#define DISPLAYH (480)
#define DISPLAYW (1.6*640)
#define FPS (1.0 / 120.0)


void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(FPS);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    ALLEGRO_DISPLAY* disp = al_create_display(DISPLAYW, DISPLAYH);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_image_addon(), "image addon");
    
    
     ALLEGRO_BITMAP* on = al_load_bitmap("on.png");
    must_init(on, "on");
    
     ALLEGRO_BITMAP* off = al_load_bitmap("off.png");
    must_init(off, "off");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    
    int error = 0;
    uint_least16_t mask = 0xFFFF;
    
    while(1)
    {
        al_wait_for_event(queue, &event);

       switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // once again, no game logic. fishy? maybe.
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                if(event.keyboard.keycode == ALLEGRO_KEY_0)
                    if(!bitSet(0,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_1)
                    if(!bitSet(1,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_2)
                    if(!bitSet(2,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_3)
                    if(!bitSet(3,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_4)
                    if(!bitSet(4,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_5)
                    if(!bitSet(5,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_6)
                    if(!bitSet(6,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_7)
                    if(!bitSet(7,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_T)
                    if(!maskToggle(mask,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_C)
                    if(!maskOff(mask,'D'))
                    {
                       error++; 
                    }

                if(event.keyboard.keycode == ALLEGRO_KEY_S)
                    if(!maskOn(mask,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_B)
                    if(!bitSet(1,'D'))
                    {
                       error++; 
                    }
                if(event.keyboard.keycode == ALLEGRO_KEY_Q)
                    done = true;
                if(event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
                    break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
}

        if(done)
                break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(100, 100, 100));
            al_draw_text(font, al_map_rgb(255, 255, 255), 5, 5, 0, "Trabajo Práctico 11 -Grupo 2");
            al_draw_text(font, al_map_rgb(255, 255, 255), 15, 15, 0, "Presione un número del 0 al 7 para encenderlo.");
            al_draw_text(font, al_map_rgb(255, 255, 255), 15, 25, 0, "Presione 't' para invertir el valor de los leds.");
            al_draw_text(font, al_map_rgb(255, 255, 255), 15, 35, 0, "Presione 'c' para apagar todos los leds");
            al_draw_text(font, al_map_rgb(255, 255, 255), 15, 45, 0, "Presione 's' para encender todos los leds");
            al_draw_text(font, al_map_rgb(255, 255, 255), 15, 55, 0, "Presione 'b' para iniciar/finalizar el titileo de los leds");
            al_draw_text(font, al_map_rgb(255, 255, 255), 15, 65, 0, "Presione 'q' para cerrar el programa");
            
            
            if(bitGet(0,'D')==1)
            {
                al_draw_bitmap(on, 100, 100, 0);
            }else if(bitGet(0,'D')==0)
            {
                al_draw_bitmap(off, 100, 100, 0);
            }else
            {
                error++;
            }
            
            if(bitGet(1,'D')==1)
            {
                al_draw_bitmap(on, 200, 100, 0);
            }else if(bitGet(1,'D')==0)
            {
                al_draw_bitmap(off, 200, 100, 0);
            }else
            {
                error++;
            }
            
            if(bitGet(2,'D')==1)
            {
                al_draw_bitmap(on, 300, 100, 0);
            }else if(bitGet(2,'D')==0)
            {
                al_draw_bitmap(off, 300, 100, 0);
            }else
            {
                error++;
            }
             
            if(bitGet(3,'D')==1)
            {
                al_draw_bitmap(on, 400, 100, 0);
            }else if(bitGet(3,'D')==0)
            {
                al_draw_bitmap(off, 400, 100, 0);
            }else
            {
                error++;
            }
             
            if(bitGet(4,'D')==1)
            {
                al_draw_bitmap(on, 500, 100, 0);
            }else if(bitGet(4,'D')==0)
            {
                al_draw_bitmap(off, 500, 100, 0);
            }else
            {
                error++;
            }
             
            if(bitGet(5,'D')==1)
            {
                al_draw_bitmap(on, 600, 100, 0);
            }else if(bitGet(5,'D')==0)
            {
                al_draw_bitmap(off, 600, 100, 0);
            }else
            {
                error++;
            }
             
            if(bitGet(6,'D')==1)
            {
                al_draw_bitmap(on, 700, 100, 0);
            }else if(bitGet(6,'D')==0)
            {
                al_draw_bitmap(off, 700, 100, 0);
            }else
            {
                error++;
            }
             
            if(bitGet(7,'D')==1)
            {
                al_draw_bitmap(on, 800, 100, 0);
            }else if(bitGet(7,'D')==0)
            {
                al_draw_bitmap(off, 800, 100, 0);
            }else
            {
                error++;
            }
            /*
            al_draw_bitmap(on, 100, 100, 0);
            al_draw_bitmap(off, 200, 100,0);
            al_draw_bitmap(on, 300, 100, 0);
            al_draw_bitmap(off, 400, 100,0);
            al_draw_bitmap(on, 500, 100, 0);
            al_draw_bitmap(off, 600, 100,0);
            al_draw_bitmap(on, 700, 100, 0);
            al_draw_bitmap(off, 800, 100,0);
            */
            
            al_flip_display();

            redraw = false;
        }
    }

 
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}