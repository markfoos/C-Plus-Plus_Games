//Guess the Number Game


#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	
	//seed random number	
	srand(static_cast<unsigned int>(time(0)));

	//random number between 1 and 100 and set integer variables
	int secretNumber = rand() % 100 + 1;
	int tries = 0;
	int guess;
	char newGame = 'y';

		cout << "\tWelcome to Guess My Number\n\n";


		do {
			cout << "Enter a guess: ";
			cin >> guess;
			++tries;

			if (guess > secretNumber) {
				cout << "That guess is too high!\n\n";
			}
			else if (guess < secretNumber) {
				cout << "That guess is too low!\n\n";
			}
			else {
				cout << "\nThat's it! You got it in " << tries << " guesses!\n";
				cout << "Do you want to play again? (y/n)" << endl;
				cin >> newGame;
			}
		} while (guess != secretNumber && newGame == 'y');

	system("PAUSE");
	return 0;
	
}

