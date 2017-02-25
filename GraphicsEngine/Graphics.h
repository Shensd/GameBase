#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_primitives.h>

class Graphics {
public:
	Graphics();
	ALLEGRO_DISPLAY *get_display();
	void begin_draw();
	void end_draw();
	void destroy();
	void draw_rect(int x, int y, int x_max, int y_max, ALLEGRO_COLOR color = al_map_rgb(255, 0, 0), float thickness = 2.0);
private:
	ALLEGRO_DISPLAY *display = NULL;
};

#endif