#include "game.h"
using namespace std;

Game :: Game() {

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}

void Game::welcome() {

	cout << "-------------------------------------"<< endl;
	cout << "|===============CRIC-IN==============|"<< endl;
	cout << "|                                    |"<< endl;
	cout << "|      Welcome to Virtual Game       |"<< endl;
	cout << "--------------------------------------"<< endl<< endl << endl;

	cout << "---------------------------------------"<< endl;
	cout << "|============ Instructions ===========|"<< endl;
	cout << "---------------------------------------"<< endl;
	cout << "|                                     |"<< endl;
	cout << "|1. Create 2 teams(Team A, Team B with|"<< endl;
	cout << "|4 players each) from 11 players.     |"<< endl;
	cout << "|2.Lead the toss and decide the play. |"<< endl;
	cout << "|3.Each innings will be of 6 balls.   |"<< endl;
}

void Game::showAllPlayers() {

	cout << endl;

	cout << "----------------------------------------"<< endl;
	cout << "|========== Pool of Players ===========|"<< endl;
	cout << "----------------------------------------"<< endl;
	cout << endl;

	for (int i=0; i < totalPlayers; i++) {
		cout << "\t\t[" << i << "] " << players[i] << endl;
	}

}

int Game::takeIntegerInput() {

	int n;

	while(!(cin >> n)) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Invalid input! Please try again with valid input: ";
	}
	return n;
}

bool Game::validateSelectedPlayer(int index) {

	int n;
	vector<Player>players;

	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
		if (players[i].id == index) {
			return false;
		}
	}

	players = teamB.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
		if (players[i].id == index) {
			return false;
		}
	}
	return true;
}

void Game::selectPlayers() {

	cout << endl;
	cout<< "------------------------------------"<<endl;
	cout<< "|==== Create Team-A and Team-B ====|"<<endl;
	cout<< "------------------------------------"<<endl;

	for(int i=0; i<playersPerTeam; i++) {
//A
	teamASelection:
		cout << endl << "Select player "<< i + 1 << " of Team A - ";
		int playerIndexTeamA = takeIntegerInput();

		if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
					cout << endl << "Please select from the given players" << endl;
			        goto teamASelection;
		}
		else if(!validateSelectedPlayer(playerIndexTeamA)) {
					cout << endl << "Player has been already selected. Select another player!\n";
			        goto teamASelection;
		}
		else {
			        Player teamAPlayer;
					teamAPlayer.id = playerIndexTeamA;
					teamAPlayer.name = players[playerIndexTeamA];
					teamA.players.push_back(teamAPlayer);
		}


//B
	teamBSelection:
		cout << endl << "Select player "<< i + 1 << " of Team B - ";

		int playerIndexTeamB = takeIntegerInput();

		if (playerIndexTeamB < 0 || playerIndexTeamB > 10) {
					cout << endl << "Please select from the given players" << endl;
			        goto teamBSelection;
		}
		else if (!validateSelectedPlayer(playerIndexTeamB)) {
					cout << endl << "Player has been already selected. Select another player!\n";
					goto teamBSelection;
		}
		else {
					Player teamBPlayer;
					teamBPlayer.id = playerIndexTeamB;
					teamBPlayer.name = players[playerIndexTeamB];
					teamB.players.push_back(teamBPlayer);
		}
	}
}

void Game::showTeamPlayers() {

	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;

	cout<< endl << endl;
	cout << "|------------------------|" << "\t\t" << "|------------------------|"<<endl;
	cout << "|---------Team A---------|" << "\t\t" << "|---------Team B---------|"<<endl;
	cout << "|------------------------|" << "\t\t" << "|------------------------|"<<endl;

	for (int i = 0; i < playersPerTeam; i++) {
		cout << "|\t" << "[" << i << "] " << teamAPlayers[i].name << "\t |"
			<<	"\t\t"
			<<	"|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;

	}
	cout << "|------------------------|" << "\t\t" << "|------------------------|"<<endl<<endl;

}

void Game::toss() {

	cout << endl;
	cout << "-------------------------------------"<<endl;
	cout << "--------------Let's Toss-------------"<<endl;
	cout << "-------------------------------------"<<endl<<endl;

	cout <<"Tossing the coin..." << endl << endl;

	srand(time(NULL));
	int randomValue = rand() % 2; // 0 or 1

	switch (randomValue) {
	case 0:
		cout << "Team A won the toss"<< endl;
		tossChoice(teamA);
		break;
	case 1:
		cout << "Team B won the toss"<< endl;
		tossChoice(teamB);
		break;
	}
}

void Game::tossChoice(Team tossWinnerTeam) {

	cout << "Enter 1 to bat or 2 to bowl first."<<endl
	     <<"1. Bat"<<endl
		 <<"2. Bowl"<<endl;

	int tossInput = takeIntegerInput();

	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
	case 1:
		cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first"<<endl <<endl;

		if (tossWinnerTeam.name.compare("Team-A") == 0) {
			battingTeam = &teamA;
			bowlingTeam = &teamB;
		} else {
			battingTeam = &teamB;
			bowlingTeam = &teamA;

		}
		break;
	case 2:
		cout << endl << tossWinnerTeam.name << " won the toss and elected to bowl first"<<endl <<endl;

		if (tossWinnerTeam.name.compare("Team-A") == 0) {
			bowlingTeam = &teamA;
			battingTeam = &teamB;
		} else {
			bowlingTeam = &teamB;
			battingTeam = &teamA;

		}
		break;
	default:
		cout << endl << "Invalid input. Please try again: "<< endl << endl;
		tossChoice(tossWinnerTeam);
		break;
	}

}

void Game::startFirstInnings() {

	cout<<"\t\t ||| FIRST INNINGS STARTS ||| " <<endl <<endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

void Game::startSecondInnings() {

	cout<<"\t\t ||| SECOND INNINGS STARTS ||| " <<endl <<endl;

	isFirstInnings = false;

//	Team tempTeam = *battingTeam;
//	*battingTeam = *bowlingTeam;
//	*bowlingTeam = tempTeam;

	initializePlayers();
	playInnings();
}

void Game::initializePlayers() {

	batsman = &bowlingTeam->players[0];
	bowler = &battingTeam->players[0];

	cout << battingTeam->name << "-" << batsman->name << " is batting "<< endl;
	cout << bowlingTeam->name << "-" << bowler->name << " is bowling "<< endl<< endl;

}

void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		getchar();

		bat();

		if(!validateInningsScore()) {
			break;
		}
	}

}

void Game::bat() {

	srand(time(NULL));
	int runsScored = rand() % 7;
//batsman score update
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

//bowler scored update
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;



	if (runsScored != 0) {

		cout << endl << bowler->name <<" to "<<batsman->name << " " << runsScored << " runs!" << endl<< endl;
		showGameScorecard();

	} else {

		cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

		battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
		bowler->wicketsTaken = bowler->wicketsTaken + 1;

		showGameScorecard();

		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex];

	}

}

bool Game::validateInningsScore() {

	if (isFirstInnings) {
		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS END ||| " <<endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
						<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
						<<")"<<endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}


	} else {


	}
	return true;
}

void Game::showGameScorecard() {

	cout << "--------------------------------------------------------------------"<<endl;

	cout << "\t"<< battingTeam->name << " "<< battingTeam->totalRunsScored << " - "
			<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") |" << batsman->name
			<< " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
			<< bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

	cout << "-------------------------------------------------------------------"<<endl;
}

void Game::showMatchSummary() {

	cout << "\t\t ||| MATCH ENDS ||| " << endl << endl;

	cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;

    cout << "==========================================" << endl;
    cout << "| PLAYER \t BATTING \t BOWLING |" << endl;

   for (int j = 0; j < playersPerTeam; j++) {
	   Player player = battingTeam->players[j];
	   cout << "|----------------------------------------|" << endl;
	   cout << "| " << "[" << j << "] " << player.name << "  \t"
			   <<player.runsScored << "(" << player.ballsPlayed << ") \t\t"
			   <<player.ballsBowled << "-" << player.runsGiven << "-"
			   <<player.wicketsTaken << "\t |" << endl;

	   cout << "==========================================" << endl << endl;
	   cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << endl;

	   cout << "==========================================" << endl;
	       cout << "| PLAYER \t BATTING \t BOWLING |" << endl;
	       for (int i = 0; i < playersPerTeam; i++) {
	       	Player player = bowlingTeam->players[i];
	           cout << "|----------------------------------------|" << endl;
	           cout << "| " << "[" << i << "] " << player.name << "  \t "
	               << player.runsScored << "(" << player.ballsPlayed << ") \t\t "
	               << player.ballsBowled << "-" << player.runsGiven << "-"
	   			<< player.wicketsTaken << "\t |" << endl;
	       }
	       cout << "==========================================" << endl << endl;
	   }
