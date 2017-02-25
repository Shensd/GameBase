#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_primitives.h>

#include "StateManager.h"
#include "Graphics.h"
#include <iostream>

int main() {
	StateManager sm;
	Graphics g;

	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	if (!al_init()) { return -1; }

	al_set_new_display_flags(ALLEGRO_WINDOWED);

	if (!al_init_primitives_addon()) { return -1; }

	al_install_keyboard();

	int FPS = 60;

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	if (!timer) { return -1; }

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(g.get_display()));

	al_start_timer(timer);
	
	bool done = false;

	while (!done) {
		bool update = false;

		while (!al_is_event_queue_empty(event_queue)) {
			ALLEGRO_EVENT events;
			al_wait_for_event(event_queue, &events);

			switch (events.type) {
			case ALLEGRO_EVENT_KEY_DOWN:
				sm.key_pressed(events.keyboard.keycode);
				break;
			case ALLEGRO_EVENT_KEY_UP:
				sm.key_released(events.keyboard.keycode);
				break;
			case ALLEGRO_EVENT_TIMER:
				update = true;
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				done = true;
				g.destroy();
				break;
			}
		}

		if (done) {
			break;
		}

		g.begin_draw();

		sm.draw(&g);

		g.end_draw();

		if (update) {
			sm.update();
		}
	}

	return 0;
}