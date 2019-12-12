//Real lost fortune game
// A personalized disaster



#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
using std::string;

int main() 
{
	//identify variables and strings

	const int DOLLAR_AMOUNT = 50000;
	int yearsAfterGraduation, yearsHuman, netWorth, children, yearlyIncome;
	string name, otherName, invention;

	//get the variables
	cout << "Welcome to a true lost fortune story\n\n";
	cout << "Please enter the following for your personalized story \n\n";

	cout << "What is your name?: ";
	cin >> name;

	cout << "Well " << name << ", you graduated ASUMH, congrats you are now working \nas a full time developer.";
	cout << "\n\nHow many years has it been since you graduated?: ";
	cin >> yearsAfterGraduation;

	cout << "\nYou meet a bueatiful human being. \nHow long ago did you meet this person in years?:";
	cin >> yearsHuman;

	cout << "\nAnd what is their name?:";
	cin >> otherName;


	cout << "\nWell " << name << ", you also end up having children with " << otherName <<".";
	cout << "\nHow many children do you have?:";
	cin >> children;

	cout << "\nDuring your time after ASUMH you create\nan awesome idea/invention.";
	cout << "\nWhat is the name of this invention?:";
	cin >> invention;
	
	netWorth = yearsAfterGraduation * 9000;
	yearlyIncome = 50000;
	

	
	//tell the story


	cout << "\n\n\nThis is the story of " << name << "\n\n";
	cout << name << " showed a lot promise.\n" << name << " graduated ASUMH " << yearsAfterGraduation << " years ago.\n";
	cout << name << " got a job shortly after that making good money.\n";
	cout << "\nAlong the way, " << name << " met " << otherName << " " << yearsHuman << " years ago and they hit it off.\n";
	cout << "They ended up having " << children << " children.";
	cout << "\nThen one day " << name << " had an awesome idea and createD: " << invention << ".\n";
	cout << "\n" << invention << " becomes a worldwide hit. Everyone loves it.\n";
	cout << "\n" << name << " ends up getting comsumed from the success of " << invention << ".\n\n";
	cout << name << " stops paying attention to " << otherName << " and the " << children << " children.\n";
	cout << name << " and " << otherName << " end up filing for divorce.\n";
	cout << otherName << " gets custody of the children\n\n";
	cout << "During " << name << "'s professional life. " << name << " made " << netWorth << " dollars.\n";
	cout << name << " also made " << DOLLAR_AMOUNT << " from " << invention << ".\n";
	cout << "Now " << name << " has to pay " << otherName << " " << (DOLLAR_AMOUNT + netWorth) / 2 << " dollars in the divorce.\n";
	cout << name << " also has to pay " << otherName << " " << yearlyIncome / 12 * children << " dollars (rough estimate) a month in child support.";
	cout << "\n\nNow, " << name << " has lost most of his fortune as well as his family.\n";
	cout << "If only " << name << " didn't get comsumed by his own success, he could have been a happy man.\n\n\n\n";


	system("PAUSE");

	return 0;
}
