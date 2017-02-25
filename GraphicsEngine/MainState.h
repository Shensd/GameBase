#pragma once
#ifndef MAIN_STATE_H
#define MAIN_STATE_H

#include "IState.h"
#include "StateManager.h"
#include "Graphics.h"

class MainState : public IState {
public:
	MainState(StateManager *man);
	void init(void);
	void update(void);
	void draw(Graphics *g);
	void destroy(void);
	void key_pressed(int k);
	void key_released(int k);
private:
	StateManager *manager;

	//Physics Variables
	float x, y, h, w;
	float velx, vely;
	float gravity;
	bool jumping, moving;
	bool left, right;
};

#endif