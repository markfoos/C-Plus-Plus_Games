#include "pch.h"
#include <iostream>
#include <string>


//mad-lib

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string professorName, string activity, string pluralObject1, string schoolSubject, 
	string properNoun1, string place, string singleOrPluralObject, string friendName, string verb1, string verb2,
	string bodyPart, string pluralObject2);

int main() {
	cout << "Welcome to Mad Lib\nASUMH Edition\n\n";
	cout << "Answer the following questions to help create a new story. \n";

	string professorName = askText("Please enter a name of your professor: ");
	string activity = askText("Please enter an activity (end in ing): ");
	string pluralObject1 = askText("Please enter a plural object (ending in s): ");
	string bodyPart = askText("Please enter a body part: ");
	string verb1 = askText("Please enter an action on object: ");
	string schoolSubject = askText("Please enter a school subject: ");
	string properNoun1 = askText("Please enter a proper noun: ");
	string place = askText("Please enter the name of a place: ");
	string singleOrPluralObject = askText("Please enter a single or plural object: ");
	string friendName = askText("Please enter the name of your friend: ");
	string verb2 = askText("Please enter another action on object: ");
	string pluralObject2 = askText("Plesae enter a plural object: ");

	tellStory(professorName, activity, pluralObject1, schoolSubject, 
		properNoun1, place, singleOrPluralObject, friendName, verb1, verb2, pluralObject2, bodyPart); 
	
	system("PAUSE");
	return 0;
}

string askText(string prompt) {
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}

void tellStory(string professorName, string activity, string pluralObject1, string schoolSubject,
	string properNoun1, string place, string singleOrPluralObject, string friendName, string verb1, string verb2
	, string pluralObject2, string bodyPart) {
	cout << "\nHere is the ASUMH edition Madlib!\n\n";
	cout << "So there you were in Professor " << professorName << "'s class.\n";
	cout << "Minding your own business, doing some " << activity << ".\n\n";
	cout << "All of a sudden, " << pluralObject1 << " fall through the ceiling.\n";
	cout << "With this being a " << schoolSubject << " class, this is highly abnormal.\n\n";
	cout << "Professor " << professorName << " gets up and yells:\n'What in the name of " << properNoun1 << "?'\n";
	cout << "'Everyone go to " << place << "!'\n";
	cout << "'And don\'t forget to grab your " << singleOrPluralObject << ".'\n\n";
	cout << "As more " << pluralObject1 << " keep falling through the ceiling,\n";
	cout << friendName << " gets an idea to " << verb1 << " the " << pluralObject1 << ".\n\n";
	cout << "As " << friendName << " is trying to " << verb1 << " the " << pluralObject1 << ",\n";
	cout << professorName << " stops " << friendName << " and tells " << friendName << " to stop " << verb1 << "ing and ";
	cout << "start " << verb2 << "ing. \n\nMiraculously, from " << verb2 << "ing the " << pluralObject1;
	cout << ". \nThe " << pluralObject1 << " subside and " << pluralObject2 << " start coming up through the";
	cout << " floor.\n\nAs you feel your " << bodyPart << " getting covered in " << pluralObject2;
	cout << ". \nYou wake up in " << professorName << "'s class. \n\nEveryone has left, but";
	cout << " somehow your " << bodyPart << " is covered in " << pluralObject2 << ".\n\n\n";
}


















/*
//taking damage function

int radiation(int health);

using namespace std;

int main() {
	int health = 80;
	cout << "Your Health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";

	return 0;
}

inline int radiation(int health) {
	return(health / 2);
}


*/












/*
//triple function overloading

using namespace std;

int triple(int number);
string triple(string text);

int main()
{
	cout << "Tripling 5: " << triple(5) << "\n\n";
	cout << "Tripling 'gamer': " << triple("gamer");

	return 0;
}

int triple(int number) {
	return (number * 3);
}

string triple(string text) {
	return (text + text + text);
}

*/


















/*
//give mea nubmer game

using namespace std;

int askNumber(int high, int low = 1);

int main() {
	int number = askNumber(5);
	cout << "Thanks for entering: " << number << "\n\n";
	
	number = askNumber(10, 5);
	cout << "Thanks for entering: " << number << "\n\n";

	return 0;
}
int askNumber(int high, int low) {
	int num;
	do
	{
		cout << "Pleasee enter a number" << "(" << low << "-" << high << "): ";
		cin >> num;
	} while (num > high || num < low);
	return num;
}

*/









/*using namespace std;

char askYesNo1();
char askYesNo2(string question);


int main()
{
	char answer1 = askYesNo1();
	cout << "thaanks for answering: " << answer1 << "\n\n";

	char answer2 = askYesNo2("Do you wish to save your game?");
	cout << "Thanks for answering: " << answer2 << "\n";
	
	return 0;
}

char askYesNo1() {
	char response1;
	do
	{
		cout << "Please enter 'y' or 'n': ";
		cin >> response1;
	} while (response1 != 'y' && response1 != 'n');
	return response1;
}

char askYesNo2(string question)
{
	char response2;
	do
	{cout << question << " (y/n): "; cin >> response2; } 
	while (response2 != 'y' && response2 != 'n');

	return response2;
}
*/
