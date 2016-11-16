#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Player;

class CalcHealth {
public:
	CalcHealth() {}
	virtual ~CalcHealth() {}

	virtual int calc(Player &player) = 0;
};

class Player {
	int health;
	CalcHealth *calc_strategy;

public:
	Player(CalcHealth *calc_strategy_, int health_ = 100) : calc_strategy(calc_strategy_), health(health_) {}
	~Player() { if (calc_strategy) delete calc_strategy; }

	int gethealth() {return health;}
	void calcHealth() { health = calc_strategy->calc(*this); }
	void showHealth() { printf("player health: %d\n", health); }
};

class LevelOneCalcHealth : public CalcHealth {
public:
	LevelOneCalcHealth() {}
	~LevelOneCalcHealth() {}

	int calc(Player &player) {
		int health = player.gethealth();
		health -= 20;

		return health;
	}
};

int main()
{
	Player player(new LevelOneCalcHealth);

	player.showHealth();
	player.calcHealth();
	player.showHealth();

	return 0;
}

