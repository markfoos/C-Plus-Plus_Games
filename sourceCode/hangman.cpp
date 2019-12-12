#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

//main loop
int main()
{
	//establish max wrong guesses
	const int MAX_WRONG = 8;

	//establish vector of strings to use as word bank
	vector<string> words;
	words.push_back("HARLEY_QUINN");
	words.push_back("FLASH");
	words.push_back("SUPERMAN");
	words.push_back("CATWOMAN");
	words.push_back("ZATANNA");
	words.push_back("HAWKGIRL");
	words.push_back("CYBORG");
	words.push_back("GREEN_ARROW");

	words.push_back("BATMAN");
	words.push_back("SUPERMAN");
	words.push_back("WONDER_WOMAN");
	words.push_back("GREEN_LANTERN");
	words.push_back("ROBIN");
	words.push_back("AQUAMAN");
	words.push_back("BOOSTER_GOLD");
	words.push_back("BLUE_BEETLE");


	//randomize the vector of strings
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	//pick out the first word after the random shuffle
	const string THE_WORD = words[0];
	int wrong = 0;
	
	//create new string equal to the size of the word replace with "-"
	string soFar(THE_WORD.size(), '-');
	
	//blank string for guesses
	string used = "";
	
	//if there is a blank space to guess, fill it in
	if (THE_WORD.find("_") != string::npos)
	{
		int i;
		i = THE_WORD.find("_");
		soFar[i] = '_';
	}
	
	cout << "Welcome to Hangman, DC Comic Book Character Edition!\n";
	
	//main game loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		char guess;


		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is :\n" << soFar << endl;

		cout << "\n\nEnter your Guess: ";
	
		cin >> guess;
		guess = toupper(guess);
		
		//if guess has already been guessed go to this loop
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;

		//if guess is in THE_WORD loop
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		//if the guess is NOT in the THE_WORD
		else
		{
			cout << "Sorry. " << guess << "isn't in the word.\n";
			++wrong;
		}

	}
	
	//end game
	if (wrong == MAX_WRONG)
	{
		cout << "\nYou've been hanged!";
	}
	else
	{
		cout << "\nYou guessed it!";
	}
	
	cout << "\nThe word was " << THE_WORD << endl;
	
	system("PAUSE");
	
	return 0;
}
