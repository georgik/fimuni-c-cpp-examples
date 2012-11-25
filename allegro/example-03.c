/**
 * Example 02 - Allegro 5
 * Display image based on keyboard events.
 *
 * Juraj Michalek - http://georgik.sinusgear.com
 */

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>


int main()
{
	bool isStopSignal = false;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_DISPLAY *display;
	
	ALLEGRO_EVENT event;
	ALLEGRO_BITMAP *image;

    ALLEGRO_MOUSE_STATE msestate;
    ALLEGRO_KEYBOARD_STATE kbdstate;

	ALLEGRO_COLOR white = al_map_rgb_f(1.0, 1.0, 1.0);

	al_init();
	al_install_keyboard();
	al_init_image_addon();
	
	display = al_create_display(640, 480);
	if (!display)
	{
		return 2;
	}

	// Create Event queue
        event_queue = al_create_event_queue();

	// Register Keyboard to queue
    al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

    // Register Mouse
    al_install_mouse();

	// Clear screen
	al_clear_to_color(white);
	
	// Load and display image
	image = al_load_bitmap("smajlik.png");
	if (image == NULL)
	{
		printf("No bitmap.\n");
		return 1;
	}

	
	do {
        al_get_mouse_state(&msestate);
        al_get_keyboard_state(&kbdstate);
        
	    al_clear_to_color(white);	
		al_draw_bitmap(image, msestate.x, msestate.y, 0);
	
		al_flip_display();
	} while (!al_key_down(&kbdstate, ALLEGRO_KEY_ESCAPE));

	// Release
	al_destroy_bitmap(image);
    al_uninstall_mouse();
	al_uninstall_keyboard();
	al_uninstall_system();
	return 0;
}


