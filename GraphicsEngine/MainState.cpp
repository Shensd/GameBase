#include "MainState.h"
#include "Graphics.h"
#include <iostream>

MainState::MainState(StateManager *man) {
	MainState::manager = man;
	
	MainState::init();
}

void MainState::init(void) {
	MainState::x = 50;
	MainState::y = (480 - 200);
	MainState::h = 50;
	MainState::w = 50;

	MainState::velx = 0;
	MainState::vely = 5;

	MainState::gravity = 0.6;

	MainState::jumping = true;
	MainState::moving = false;

	MainState::left = false;
	MainState::right = false;
}

void MainState::update(void) {
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

void MainState::draw(Graphics *g) {
	g->draw_rect(x, y, x + w, y + h, al_map_rgb(165, 25, 252));
}

void MainState::destroy(void) {}

void MainState::key_pressed(int k) {
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

void MainState::key_released(int k) {
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