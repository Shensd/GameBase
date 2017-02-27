#pragma once
#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <vector>

class IState;

#include "Graphics.h"

class StateManager {
public:
	StateManager();
	~StateManager();
	void set_state(int val);
	void init(void);
	void update(void);
	void draw(Graphics *g);
	void destroy(void);
	void key_pressed(int k);
	void key_released(int k);
private:
	std::vector<IState*> _states;
	int current_state;
};

#endif