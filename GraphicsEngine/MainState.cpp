#include "MainState.h"
#include "Graphics.h"
#include <iostream>

typedef MainState ms;

ms::MainState(StateManager *man) {
	ms::manager = man;
	
	ms::init();
}

ms::~MainState() {}

void ms::init(void) {
	ms::x = 50;
	ms::y = (480 - 200);
	ms::h = 50;
	ms::w = 50;

	ms::velx = 0;
	ms::vely = 5;

	ms::gravity = 0.6;

	ms::jumping = true;
	ms::moving = false;

	ms::left = false;
	ms::right = false;
}

void ms::update(void) {
	std::cout << x << ", " << y << std::endl;
	if (jumping) {
		if ((y + h) + vely <= 480) {
			y += vely;
			vely += gravity;
		}
		else {
			y = 480 - h;
			vely = 0;
			jumping = false;
		}
	}
	if (moving) {

		if ((x + w) + velx > 640) {
			x = 640 - w;
		}
		else if (x + velx < 0) {
			x = 0;
		}
		else {
			x += velx;
		}
	}
}

void ms::draw(Graphics *g) {
	g->draw_rect(x, y, x + w, y + h, al_map_rgb(165, 25, 252));
}

void ms::destroy(void) {}

void ms::key_pressed(int k) {
	switch (k) {
	case ALLEGRO_KEY_SPACE:
		if (!jumping) {
			vely = -15;
			jumping = true;
		}
	case ALLEGRO_KEY_A:
		if (!moving) {
			velx = -8;
			moving = true;
			left = true;
		}
	case ALLEGRO_KEY_D:
		if (!moving) {
			velx = 8;
			moving = true;
			right = true;
		}
	}
}

void ms::key_released(int k) {
	switch (k) {
	case ALLEGRO_KEY_A:
		if (moving) {
			moving = false;
			left = false;
		}
		break;
	case ALLEGRO_KEY_D:
		if (moving) {
			moving = false;
			right = false;
		}
		break;
	}
}