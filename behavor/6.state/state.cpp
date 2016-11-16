#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class PlayerState;

class State {
	string stateDes;

public:
	State(string stateDes_) : stateDes(stateDes_) {}
	~State() {}

	virtual void pressButton(PlayerState &context) = 0;
	void showState() {printf("state: %s\n", stateDes.c_str());}
};

class PlayerState {
	State *state;

public:
	PlayerState(State *state_) : state(state_) { state->showState(); }

	void setState(State *state_) {
		state = state_;
		state->showState();
	}

	State * getState() {return state;}

	void pressButton() {
		state->pressButton(*this);
	}
};

class PlayingState : public State {
public:
	PlayingState() : State("playing") {}

	void pressButton(PlayerState &context) override final;
};

class PausedState : public State {
public:
	PausedState() : State("paused") {}

	void pressButton(PlayerState &context) override final;
};


void PausedState::pressButton(PlayerState &context) {

	context.setState(new PlayingState);
}

void PlayingState::pressButton(PlayerState &context){
	context.setState(new PausedState);
}



int main()
{
	PlayerState *ps = new PlayerState(new PausedState());
	ps->pressButton();
	ps->pressButton();

	return 0;
}

