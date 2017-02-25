#include "StateManager.h"
#include "IState.h"

#include "MainState.h"
#include "Graphics.h"

StateManager::StateManager() {
	StateManager::current_state = 0;
	StateManager::_states[0] = new MainState(this);

	_states[current_state]->init();
}

void StateManager::set_state(int val) {
	_states[current_state]->destroy();
	current_state = val;
	_states[current_state]->init();
}

void StateManager::init(void) {
	_states[current_state]->init();
}

void StateManager::update(void) {
	_states[current_state]->update();
}

void StateManager::draw(Graphics *g) {
	_states[current_state]->draw(g);
}

void StateManager::destroy(void) {
	_states[current_state]->destroy();
}

void StateManager::key_pressed(int k) {
	_states[current_state]->key_pressed(k);
}

void StateManager::key_released(int k) {
	_states[current_state]->key_released(k);
}