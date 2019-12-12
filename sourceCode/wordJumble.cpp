// WordJumbleWeek3.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	char game = 'y';
	while (game == 'y') {

	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"Han_Solo", "He shot first!"},
		{"Death_Star", "'That is no space station.'"},
		{"Obi_Wan_Kenobi", "'Where did you dig up that old fossil.'"},
		{"Boba_Fett", "He's worth a lot of money to him to be kept alive"},
		{"Red_Leader", "Lock X foiles in attack position"},
		{"It's_a_trap", "'Admiral we have enemy ships in sector 3-7"},
		{"Millenium_Falcon", "'What a piece of junk.'"},
		{"Alderaan", "'I have chosen to test this station's destructive power on your home planet.'"},
		{"Darth_Vader", "'A pupil of mine until he turned to evil'"},
		{"Prequel_Trilogy", "Where things started to go downhill for George"},
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //word to guess
	string theHint = WORDS[choice][HINT]; //hint for word

	string jumble = theWord; //jumbled version of word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	
	

		cout << "\n\t\t\tWelcome to Word Jumble!\n\t\t\t  Star Wars Edition!\n\n";
		cout << "Unscramble the letters to make a word. \n";
		cout << "Enter 'use_the_force' to use force powers on a weak minded computer.\n";
		cout << "Enter 'quit' to quit the game.\n\n";
		cout << "The jumble is: " << jumble;


		string guess;
		cout << "\n\nYour guess: ";
		cin >> guess;

		while ((guess != theWord) && (guess != "quit") && (guess != "new_word")) {
			if (guess == "use_the_force")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry, that is not it.";
			}

			cout << "\n\nYour guess: ";
			cin >> guess;

		}

		if (guess == theWord) {
			cout << "\nThat's it! You guessed it!\n";
			cout << "\nThanks for playing. \n";
			cout << "Do you want to play again?(y/n)";
			cin >> game;
		}
		
		else if (guess == "new_word") {
			cout << "Do you want a new word (y) or quit (n)? (y/n)";
			cin >> game;
		}
		
		else {
			break;
		}
		
		
	}
		return 0;
		system("PAUSE");
	
}
