#pragma once
#ifndef ISTATE_H
#define ISTATE_H

#include "StateManager.h"
#include "Graphics.h"

class IState {
public:
	virtual void init(void) = 0;
	virtual void update(void) = 0;
	virtual void draw(Graphics *g) = 0;
	virtual void destroy(void) = 0;
	virtual void key_pressed(int k) = 0;
	virtual void key_released(int k) = 0;
protected:
	StateManager *manager;
};

#endif