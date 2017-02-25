#include "Graphics.h"

Graphics::Graphics() {
	if (!al_init()) { return; }

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	Graphics::display = al_create_display(640, 480);
	al_set_window_title(display, "Game Window");
	if (!display) { return; }

	if (!al_init_primitives_addon()) { return; }

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
}

ALLEGRO_DISPLAY *Graphics::get_display() {
	return display;
}

void Graphics::begin_draw(void) {
	al_clear_to_color(al_map_rgb(35, 35, 35));
}

void Graphics::end_draw(void) {
	al_flip_display();
}

void Graphics::destroy() {
	al_destroy_display(display);
}

void Graphics::draw_rect(int x, int y, int x_max, int y_max, ALLEGRO_COLOR color, float thickness) {
	al_draw_rectangle(x, y, x_max, y_max, color, thickness);
}