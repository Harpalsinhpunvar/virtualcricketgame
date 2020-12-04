#include "game.h"
using namespace std;

int main() {

	Game game;
	game.welcome();

	cout << "\nPress Enter to Continue";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

	game.showAllPlayers();

	cout << "\nPress Enter to Continue";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

	game.selectPlayers();
	game.showTeamPlayers();

	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

	cout << "\nPress Enter to toss";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

	game.toss();

	game.startFirstInnings();

	game.startSecondInnings();
	game.showMatchSummary();




	return 0;
}
