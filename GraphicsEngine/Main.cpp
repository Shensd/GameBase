#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_primitives.h>

#include "StateManager.h"
#include "Graphics.h"
#include <iostream>

void init(void);
void loop(void);
void kill(void);

int main() {
	init();
	loop();
	kill();

	return 0;
}

StateManager sm;
Graphics g;

ALLEGRO_TIMER *timer;
ALLEGRO_EVENT_QUEUE *event_queue;

void init(void) {
	timer = NULL;
	event_queue = NULL;

	if (!al_init()) { return; }

	al_set_new_display_flags(ALLEGRO_WINDOWED);

	if (!al_init_primitives_addon()) { return; }

	al_install_keyboard();

	int FPS = 60;

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	if (!timer) { return; }

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(g.get_display()));
}

void loop(void) {
	al_start_timer(timer);

	bool done = false;

	while (!done) {
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
				sm.update();
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				done = true;
				g.destroy();
				break;
			}
		}

		if (done) { break; }

		g.begin_draw();

		sm.draw(&g);

		g.end_draw();
	}
}

void kill() {
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
}