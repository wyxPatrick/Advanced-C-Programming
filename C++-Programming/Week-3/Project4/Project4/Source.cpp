#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string inputOrder[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
string redWarrior[5] = { "iceman", "lion", "wolf", "ninja", "dragon" };
string blueWarrior[5] = { "lion", "dragon", "ninja", "iceman", "wolf" };
int redInitialHealth[5];
int blueInitialHealth[5];

class Warrior {
private:
	int id;
	int health;
	int attack;
	string type;
public:
	Warrior() {}
	Warrior(int id, int h, int atk, string type) : 
		id(id), health(h), attack(atk), type(type) {}
	int getHealth() {
		return health;
	}
	string getType() {
		return type;
	}
};

class Base {
private:
	string group;
	static int redHealth;
	static int blueHealth;
	static int redCount;
	static int blueCount;
	int numOfType[5] = { 0 };
	int warriorIndex;
	Warrior warrior[1000];
public:
	Base(string g) : group(g), warriorIndex(0) {}
	static void setHealth(int health) {
		redHealth = health;
		blueHealth = health;
	}
	static void ResetWarriorCount() {
		redCount = 0;
		blueCount = 0;
	}
	int makeWarrior();
};

int Base::redHealth = 0;
int Base::blueHealth = 0;
int Base::redCount = 0;
int Base::blueCount = 0;

int Base::makeWarrior() {
	static int notMadeCount = 0;
	if (group == "red") {
		string type = redWarrior[warriorIndex];
		int health = redInitialHealth[warriorIndex];
		if (redHealth - health >= 0) {
			notMadeCount = 0;
			redHealth -= health;
			warrior[redCount] = { redCount, health, 0, type };
			redCount++;
			numOfType[warriorIndex]++;
			cout << "red " << type << " " << redCount << " born with strength " << health << "," << numOfType[warriorIndex] << " " << type << " in red headquarter" << endl;
			++warriorIndex %= 5;
			return true;
		}
		else {
			notMadeCount++;
			++warriorIndex %= 5;
			if (notMadeCount > 5) {
				notMadeCount = 0;
				return false;
			}
			return this->makeWarrior();
		}
	}
	else if (group == "blue") {
		string type = blueWarrior[warriorIndex];
		int health = blueInitialHealth[warriorIndex];
		if (blueHealth - health >= 0) {
			notMadeCount = 0;
			blueHealth -= health;
			warrior[blueCount] = { blueCount, health, 0, type };
			blueCount++;
			numOfType[warriorIndex]++;
			cout << "blue " << type << " " << blueCount << " born with strength " << health << "," << numOfType[warriorIndex] << " " << type << " in blue headquarter" << endl;
			++warriorIndex %= 5;
		}
		else {
			notMadeCount++;
			++warriorIndex %= 5;
			if (notMadeCount > 5) {
				notMadeCount = 0;
				return false;
			}
			return this->makeWarrior();
		}
	}
}


int main() {
	int numOfTest = 0;
	cin >> numOfTest;

	for (int i = 1; i <= numOfTest; i++) {
		int M = 0;
		cin >> M;
		Base red("red"), blue("blue");
		Base::setHealth(M);
		Base::ResetWarriorCount();

		for (int j = 0; j < 5; j++) {
			int health;
			cin >> health;
			for (int k = 0; k < 5; k++) {
				if (inputOrder[j] == redWarrior[k]) {
					redInitialHealth[k] = health;
				}
			}
			for (int k = 0; k < 5; k++) {
				if (inputOrder[j] == blueWarrior[k]) {
					blueInitialHealth[k] = health;
				}
			}
		}

		cout << "Case:" << i << endl;
		bool redStop = false;
		bool blueStop = false;
		int time = 0;
		while (true) {
			if (!redStop) {
				cout << setw(3) << setfill('0') << time << " ";
				redStop = !red.makeWarrior();
				if (redStop) {
					cout << "red headquarter stops making warriors" << endl;
				}
			}
			if (!blueStop) {
				cout << setw(3) << setfill('0') << time << " ";
				blueStop = !blue.makeWarrior();
				if (blueStop) {
					cout << "blue headquarter stops making warriors" << endl;
				}
			}
			if (redStop && blueStop) {
				break;
			}
			time++;
		}
	}
	return 0;
}