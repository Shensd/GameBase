#include <vector>

#include "StateManager.h"
#include "IState.h"
#include "MainState.h"
#include "Graphics.h"

typedef StateManager sm;

sm::StateManager() {
	sm::current_state = 0;
	sm::_states.push_back(new MainState(this));

	_states[current_state]->init();
}

sm::~StateManager() {
	for (int i = 0; i < _states.size(); i++) {
		delete _states[i];
	}
}

void sm::set_state(int val) {
	if (val > _states.size()) {
		return;
	}

	_states[current_state]->destroy();
	current_state = val;
	_states[current_state]->init();
}

void sm::init(void) {
	_states[current_state]->init();
}

void sm::update(void) {
	_states[current_state]->update();
}

void sm::draw(Graphics *g) {
	_states[current_state]->draw(g);
}

void sm::destroy(void) {
	_states[current_state]->destroy();
}

void sm::key_pressed(int k) {
	_states[current_state]->key_pressed(k);
}

void sm::key_released(int k) {
	_states[current_state]->key_released(k);
}