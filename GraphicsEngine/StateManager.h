#pragma once
#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

class IState;

#include "Graphics.h"

class StateManager {
private:
	IState *_states[3];
	int current_state;
public:
	StateManager();
	void set_state(int val);
	void init(void);
	void update(void);
	void draw(Graphics *g);
	void destroy(void);
	void key_pressed(int k);
	void key_released(int k);
};

#endif