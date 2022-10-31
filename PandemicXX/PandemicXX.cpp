#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>





using namespace std;



class entity {
public:
	// condition 1 = immune to disease
	// condition 2 = disease resistant but death by disease cannot occur
	// condition 3 = non-resistant to disease and death by disease can occur


	int sickFirstRound = 0;
	int condition;
	std::string gates;
	char health = 'O';
	//condition değeri hastalıklı bir entity'e condition gelme conditionu
	int encounter = 0;
	int days = 0;
	int recover = 0;
};

class turn {
public:
	int loc[2];
};

using namespace std;
int habitatSize;
int  entityCounter = 0, turnCounter = 0;
vector <vector <turn>> turns;
vector <entity> entities;
int currentTurn = 1;
int counted = 0;

// the function used to keep the dead entity constant in the event of death
void death(vector < vector <turn>>& vect, int turncount, int entityCount, int loca0, int loca1) {

	for (int i = 0; i < turnCounter - (counted); i++) {
		vect[turncount + i][entityCount].loc[0] = loca0;
		vect[turncount + i][entityCount].loc[1] = loca1;

	}
}

// Function written to load the image of each turn to the turn file
void turnImage(vector <turn> vec) {
	counted++;
	for (int i = 0; i < entityCounter; i++) {

		if (entities[i].encounter == 1) {
			entities[i].days++;
		}
		if (entities[i].days == 3 && (entities[i].condition == 2 || entities[i].condition == 3)) {
			entities[i].health = 'X';
		}
		if ((entities[i].days == 18 && entities[i].condition == 3) && entities[i].sickFirstRound != 1) {
			entities[i].health = 'D';
			death(turns, counted, i, vec[i].loc[0], vec[i].loc[1]);
		}
		if ((entities[i].days == 14 && entities[i].condition == 3) && entities[i].sickFirstRound == 1) {
			entities[i].health = 'D';
			death(turns, counted, i, vec[i].loc[0], vec[i].loc[1]);
		}
		if (entities[i].days == 30 && entities[i].condition == 2) {
			entities[i].health = 'O';
			entities[i].condition = 1;
			entities[i].recover = 1;
		}
		if ((entities[i].days == 23 && entities[i].condition == 3) && entities[i].sickFirstRound != 1) {
			entities[i].health = ' ';
		}
		if ((entities[i].days == 19 && entities[i].condition == 3) && entities[i].sickFirstRound == 1) {
			entities[i].health = ' ';
		}
	}

	vector <vector<char>> abd;
	abd.resize(habitatSize + 2);
	for (int i = 0; i < habitatSize + 2; i++) {
		abd[i].resize(habitatSize + 2);
	}
	for (int i = 0; i < (habitatSize + 2); i++) {
		for (int j = 0; j < habitatSize + 2; j++) {

			abd[i][j] = ' ';
		}

	}

	for (int k = 0; k < entityCounter; k++) {

		for (int i = 0; i < (habitatSize + 2); i++) {
			for (int j = 0; j < habitatSize + 2; j++) {
				if (i == 0 || i == habitatSize + 1 || j == 0 || j == habitatSize + 1) {
					abd[i][j] = '-';
				}
				else if ((vec[k].loc[0] == i && vec[k].loc[1] == j)) {
					abd[i][j] = entities[k].health;
				}

			}

		}
	}
	for (int i = 0; i < (habitatSize + 2); i++) {
		for (int j = 0; j < habitatSize + 2; j++) {
			cout << abd[i][j];
		}
		cout << endl;
	}
	ofstream writingFile("TURNS.TXT", ios::out | ios::app);


	if (writingFile.is_open()) {

		writingFile << "Turn " << currentTurn << ":" << endl;
		currentTurn++;
		for (int i = 0; i < (habitatSize + 2); i++) {

			for (int j = 0; j < habitatSize + 2; j++) {
				writingFile << abd[i][j];
			}
			writingFile << endl;
		}
		writingFile.close();

	}
}






	void main()
	{

		ifstream readFile;
		readFile.open("INPUT.txt");
		string line = "";



		int counter = 0;


		// inputun toplam kaç satır olduğunu buluyoruz




		if (readFile.is_open()) {



			while ((getline(readFile, line))) {



				// Habitat Boyutunu aliyoruz

				if (counter == 0) {

					string temporary = "";
					int l = line.length();

					for (int i = 0; i < line.length() - 5; i++, l++) {

						char a = line.at(l - (line.length() - 5));


						temporary = temporary + a;
					}


					habitatSize = stoi(temporary);

					cout << "habitatsize: " << habitatSize << endl;
				}



				// recording entity and turn amounts

				if ((counter >= 1)) {
					string type;
					int val;
					readFile >> type >> val;

					if (type == "entity") {
						entityCounter++;
					}
					else if (type == "turn") {
						turnCounter++;
					}
				}

				counter++;
			}
			readFile.close();
		}
		else
			cout << "file closed";








		// vector to hold the position of each entity in a turn

		turns.resize(turnCounter);
		for (int i = 0; i < turnCounter; i++) {
			turns[i].resize(entityCounter);
		}

		//We give this vector the turn values ​​in the input
		readFile.open("INPUT.txt");

		int counter3 = 0;
		int counter2 = 0;
		cout << "turns: " << turnCounter<< " entities: " << entityCounter << endl;
		if (readFile.is_open()) {
			while ((getline(readFile, line))) {

				if (counter2 >= (entityCounter + 1)) {


					vector <string> locations;
					locations.resize(entityCounter);
					string ab;
					readFile >> ab >> ab;


					for (int i = 0; i < entityCounter; i++) {
						readFile >> locations[i];

					}


					for (int j = 0; j < entityCounter; j++) {


						stringstream check1(locations[j]);
						string word;
						int k = 0;
						while (getline(check1, word, 'x'))
						{
							if (k % 2 == 0) {
								turns[counter3][j].loc[0] = stoi(word);

							}
							else {
								turns[counter3][j].loc[1] = stoi(word);

							}
							k++;
						}
					}

					counter3++;
				}

				counter2++;
			}

			readFile.close();
		}



		//create the vector to hold the entities and give the gates and sickness conditions

		entities.resize(entityCounter);

		readFile.open("INPUT.txt");
		int counter4 = 0;
		int counter5 = 0;
		if (readFile.is_open()) {
			while ((getline(readFile, line))) {

				if ((counter4 >= 1) && counter4 < (entityCounter + 1)) {
					string ab, ac;
					readFile >> ab >> ab;
					readFile >> ac;


					entities[counter5].gates = ac;




					counter5++;
				}

				counter4++;
			}

			readFile.close();
		}



		readFile.open("INPUT.txt");
		int counter6 = 0, counter7 = 0;
		if (readFile.is_open()) {
			while ((getline(readFile, line))) {

				if ((counter6 > 1) && counter6 < (entityCounter + 2)) {

					if (line.length() > 23) {

						entities[counter7].health = 'X';
						entities[counter7].sickFirstRound = 1;

					}
					counter7++;
				}
				counter6++;
			}

			readFile.close();
		}

		for (int i = 0; i < entityCounter; i++) {

			int abcd = 0;
			int ab = 0;
			for (int j = 0; j < 5; j++) {
				if (entities[i].gates.at(j) == 'A' || entities[i].gates.at(j) == 'B') {
					ab++;
				}
			}


			for (int j = 0; j < 5; j++) {
				if (entities[i].gates.at(j) == 'A' || entities[i].gates.at(j) == 'B' || entities[i].gates.at(j) == 'C' || entities[i].gates.at(j) == 'D') {
					abcd++;
				}
			}
			if (ab == 0) {
				entities[i].condition = 1;
			}
			else if (ab != 0 && abcd < 3) {
				entities[i].condition = 2;
			}
			else if (ab != 0 && abcd >= 3) {
				entities[i].condition = 3;
			}



		}


		// her bir turn'u sira sira ekrana bastiriyoruz ve o turn' deki hastalik bulasma conditionlarini kontrol ediyoruz.



		for (int i = 0; i < turnCounter; i++) {
			int oankiturn = i + 1;
			cout << "Turn " << oankiturn << ":" << endl;
			turnImage(turns[i]);

			for (int i = 0; i < entityCounter; i++) {
				if (entities[i].health == 'X') {
					entities[i].condition = 1;
				}
			}


			for (int k = 0; k < entityCounter; k++) {
				for (int l = 1; l < entityCounter; l++) {
					if (abs(turns[i][k].loc[1] - turns[i][l].loc[1]) <= 3) {

						if (abs(turns[i][k].loc[0] - turns[i][l].loc[0]) <= 3) {

							if (entities[k].health == 'X' || entities[k].health == 'D') {
								entities[l].condition = 1;
							}
							else if (entities[l].health == 'X' || entities[l].health == 'D') {
								entities[k].condition = 1;

							}
						}
					}


				}
			}



		}

		// writing thee output file

		ofstream writingFile1("OUTPUT.TXT", ios::out | ios::app);
		if (writingFile1.is_open()) {
			int normal = 0, infected = 0, dead = 0, recovered = 0;

			for (int i = 0; i < entityCounter; i++) {
				if (entities[i].health == 'O' && entities[i].recover == 0) {
					normal++;
				}
				else if (entities[i].health == 'X') {
					infected++;
				}
				else if (entities[i].health == 'O' && entities[i].recover == 1) {
					recovered++;
				}
				else if (entities[i].health == 'D' || entities[i].health == ' ') {
					dead++;
				}
			}

			writingFile1 << "Normal    :" << normal << endl << "Infected  :" << infected << endl << "Dead      " << dead << endl << "Recovered :" << recovered << endl;

			for (int i = 0; i < entityCounter; i++) {
				int j = i + 1;
				string k;
				int fq = turnCounter - 1;
				if (entities[i].health == 'O' && entities[i].recover == 0) {
					k = "normal";
				}
				else if (entities[i].health == 'X') {
					k = "infected";
				}
				else if (entities[i].health == 'O' && entities[i].recover == 1) {
					k = "recovered";
				}
				else {
					k = "dead";
				}
				writingFile1 << "entity " << j << " " << turns[fq][i].loc[0] << "x" << turns[fq][i].loc[1] << " " << k << endl;
			}

			writingFile1.close();

		}

	}
