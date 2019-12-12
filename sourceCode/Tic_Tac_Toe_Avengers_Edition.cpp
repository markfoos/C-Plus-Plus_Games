#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';


void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
int askQuestion();
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>* const pBoard);
char winner(const vector<char>* const pBoard);
bool isLegal(const vector<char>* const pBoard, int move);
int humanMove(const vector<char>* const pBoard, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

// main function
int main()
{
    int move;
    const int NUM_SQUARES = 16;
    vector<char> board(NUM_SQUARES, EMPTY);

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(&board);

    while (winner(&board) == NO_ONE)
    {
        if (turn == human)
        {
			
			if (askQuestion() == 0)
			{

				move = humanMove(&board, human);
				board[move] = human;
			}
		}

        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(&board);
        turn = opponent(turn);
    }

    announceWinner(winner(&board), computer, human);
	system("PAUSE");
    return 0;
}

// functions
void instructions()
{
    cout << "Welcome to the ENDGAME, AVENGERS edition\n";
    cout << "I am THANOS, I will be your opponent today\n";
;
    cout << "In Tic Tac Toe Avengers Trivia\n\n";
;
    cout << "Answer a question from the Avengers series correct then\n\n";
    cout << "Make your move by entering a number, 0 - 15.  The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";
    
    cout << "       0 | 1 | 2 | 3      \n";
    cout << "       --------------\n";
    cout << "       4 | 5 | 6 | 7     \n";
    cout << "       --------------\n";
    cout << "       8 | 9 | 10| 11    \n";
	cout << "       --------------\n";
	cout << "       12| 13| 14| 15\n\n";


    cout << "Answer incorrectly and you are one more moment closer to the SNAP!\n\n";
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

int askQuestion()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 6;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"2", "How many infinity stones are on earth at the beginning \nof infinity war? [1, 2, 3, 4, 5"},
		{"D", "Which stone is part of Vision, on his forehead? \nA: Reality Stone\nB: Time Stone\nC: Soul Stone\nD: Mind Stone\n"},
		{"B", "Where is the soul stone located? \nA: Knowhere\nB: Vormir\nC: Zen-Whoberi\nD: Nidavellir\n"},
		{"A", "What is the name of the smith that Thor visits to rebuild his hammer?\nA: Eltri\nB: Okoye\nC: Corvus\nD: Ayo"},
		{"D", "Which of these characters are alive at the end of Infinity War? \nA: Spiderman\nB: Dr. Strange\nC: Gamora\nD: Black Widow"},
		{"A", "Which was the first Avenger to appear on Screen in Infinity War\nA: Thor\nB: Starlord\nC: Hulk\nD: Iron Man"}
	
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //word to guess
	string theHint = WORDS[choice][HINT]; //hint for word
	cout << "\n\n\n" << theHint;
	string guess;
	
	cout << "\n\nYour guess: ";
	
	cin >> guess;
	if (guess == theWord)
	{
		cout << "You narrowly made that work!\n\n";
		return 0;
	}
	else
	{
		cout << "All too easy.\n\n";
		return 1;
	}
}

int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y')
    {
        cout << "\nThen take the first move.  You will need it.\n";
        return X;
    }
    else
    {
        cout << "\nYour bravery will be your undoing... I will go first.\n";
        return O;
    }
}

char opponent(char piece)
{
    if (piece == X)
	{
        return O;
	}
    else
	{
        return X;
	}
}

void displayBoard(const vector<char>* const pBoard)
{
	cout << "\n\t" << (*pBoard)[0] << " | " << (*pBoard)[1] << " | " << (*pBoard)[2] << " | " << (*pBoard)[3];
	cout << "\n\t" << "-------------";
	cout << "\n\t" << (*pBoard)[4] << " | " << (*pBoard)[5] << " | " << (*pBoard)[6] << " | " << (*pBoard)[7];
	cout << "\n\t" << "-------------";
	cout << "\n\t" << (*pBoard)[8] << " | " << (*pBoard)[9] << " | " << (*pBoard)[10]<< " | " << (*pBoard)[11];
	cout << "\n\t" << "-------------";
	cout << "\n\t" << (*pBoard)[12] << " | " << (*pBoard)[13] << " | " << (*pBoard)[14] << " | "<< (*pBoard)[15];
	cout << "\n\n" << "-------------";
	
}

char winner(const vector<char>* const pBoard)
{
    // all possible winning rows
    const int WINNING_ROWS[24][3] = { {0, 1, 2},
                                     {4, 5, 6},
                                     {8, 9, 10},
                                     {12, 13, 14},
                                     {1, 2, 3},
                                     {5, 6, 7},
                                     {9, 10, 11},
                                     {13, 14, 15}, 
									 {0, 4, 8},
                                     {1, 5, 9},
                                     {2, 6, 10},
                                     {3, 7, 11},
                                     {4, 8, 12},
                                     {5, 9, 13},
                                     {6, 10, 14},
                                     {7, 11, 15},
									 {2, 5, 8},
                                     
                                     {0, 5, 10},
                                     {3, 6, 9},
                                     {7, 10, 13},
                                     {5, 10, 15},
                                     {4, 9, 14},
                                     {6, 9, 12},
									 
                                     {1, 6, 11} };
    const int TOTAL_ROWS = 24;

    // if any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( ((*pBoard)[WINNING_ROWS[row][0]] != EMPTY) &&
             ((*pBoard)[WINNING_ROWS[row][0]] == (*pBoard)[WINNING_ROWS[row][1]]) &&
             ((*pBoard)[WINNING_ROWS[row][1]] == (*pBoard)[WINNING_ROWS[row][2]]) )
        {
            return (*pBoard)[WINNING_ROWS[row][0]];
        }
    }

    // since nobody has won, check for a tie (no empty squares left)
    if (count(pBoard->begin(), pBoard->end(), EMPTY) == 0)
        return TIE;

    // since nobody has won and it isn't a tie, the game ain't over
    return NO_ONE;
}

inline bool isLegal(int move, const vector<char>* pBoard)
{
    return ((*pBoard)[move] == EMPTY);
}

int humanMove(const vector<char>* const pBoard, char human)
{
	cout << "\n\n";
	cout << "       0 | 1 | 2 | 3      \n";
    cout << "       --------------\n";
    cout << "       4 | 5 | 6 | 7     \n";
    cout << "       --------------\n";
    cout << "       8 | 9 | 10| 11    \n";
	cout << "       --------------\n";
	cout << "       12| 13| 14| 15\n\n";
    int move = askNumber("Where will you move?", (pBoard->size() - 1));
	while (!isLegal(move, pBoard))
    {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", (pBoard->size() - 1));
    }
    cout << "Fine...\n";
    return move;
}

int computerMove(vector<char> board, char computer)
{ 
    unsigned int move = 0;
    bool found = false;

    //if computer can win on next move, that’s the move to make
    while (!found && move < board.size())
    {
        if (isLegal(move, &board))
        {
			//try move
            board[move] = computer;
            //test for winner
            found = winner(&board) == computer;   
			//undo move
            board[move] = EMPTY;
        }

        if (!found)
        {
            ++move;
        }
    }
  
    //otherwise, if opponent can win on next move, that's the move to make
    if (!found)
    {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size())
        {
            if (isLegal(move, &board))
            {
				//try move
				board[move] = human;  
				//test for winner
                found = winner(&board) == human;     
			    //undo move
				board[move] = EMPTY;        
            }

            if (!found)
            {
                ++move;
            }
        }
    }

    //otherwise, moving to the best open square is the move to make
    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {0, 3, 12, 15, 5, 6, 9, 10};
        //pick best open square
        while (!found && i <  board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal(move, &board))
            {
                found = true;
            }

            ++i;
        }
    }

    cout << "I shall take square number " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I, Thanos, am triumphant once more\n";
        cout << "now watch as I turn another half of your population to DUST.\n";
    }

	else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no!  It cannot be!  Somehow you beat me, human.\n";
        cout << "But never again!  I, Thanos, so swear it!\n";
    }

	else
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
	}
}










/*
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void increase(int* const array, const int NUM_ELEMENTS);
void display(const int* const array, const int NUM_ELEMENTS);

int main()
{
	cout << "Creating an array of high scores. \n\n";
	const int NUM_SCORES = 3;
	int highScores[NUM_SCORES] = { 5000, 3500, 2700 };

	cout << "Displaying scores using array nme as a constat pointer.\n";
	cout << *highScores << endl;
	cout << *(highScores + 1) << endl;
	cout << *(highScores + 2) << "\n\n";

	cout << "Increasing scores by passing array as a constant pointer \n\n";
	increase(highScores, NUM_SCORES);

	cout << "Displaying scores by passing array as a constant pointer to a constant.\n";
	display(highScores, NUM_SCORES);

	return 0;
}

void increase(int* const array, const int NUM_ELEMENTS)
{
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		array[i] += 500;
	}
}

void display(const int* const array, const int NUM_ELEMENTS)
{
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		cout << array[i] << endl;
	}
}
*/








/* #include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string* ptrToElement(vector<string>* const pVec, int i);

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("sheild");

	cout << "Sending the object pointed to by returned pointer to cout: ";
	cout << *(ptrToElement(&inventory, 0)) << "\n\n";

	cout << "Assigning the returned pointer to another pointer.\n";
	string* pStr = ptrToElement(&inventory, 1);
	cout << "Sending the object pointed to by new pointer to cout: \n";
	cout << *pStr << "\n\n";

	cout << "Assigning object pointed to by pointer to a string object.\n";
	string str = *(ptrToElement(&inventory, 2));
	cout << "Sending the new string object to cout:\n";
	cout << str << "\n\n";

	cout << "Altering an object through a returned pointer. \n";
	*pStr = "Healing Potion";
	cout << "Sending the altered object to cout: \n";
	cout << inventory[1] << endl;

	return 0;
}

string* ptrToElement(vector<string>* const pVec, int i)
{
	return &((*pVec)[i]);
}
*/

/* #include "pch.h"
#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

int main()
{
	int myScore = 150;
	int yourScore = 1000;
	cout << "riginal values\n";
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n\n";
	
	cout << "Calling badSwap()\n";
	badSwap(myScore, yourScore);
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n\n";

	cout << "Calling goodSwap()\n";
	goodSwap(&myScore, &yourScore);
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n\n";

	return 0;
}

void badSwap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void goodSwap(int* const pX, int* const pY)
{
	int temp = *pX;
	*pX = *pY;
	*pY = temp;
}

*/




/*#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int* pAPointer;
	int* pScore = 0;
	int score = 1000;
	pScore = &score;

	cout << "Assinging &score to pScore\n\n";
	cout << "&score is: " << &score << "\n";
	cout << "pScore is: " << pScore << "\n";
	cout << "score is: " << score << "\n";
	cout << "pScore is: " << *pScore << "\n\n";

	cout << "Adding 500 to score\n";
	score += 500;
	cout << "score is: " << score << "\n";
	cout << "*pScore is: " << *pScore << "\n\n";

	cout << "Adding 500 to *pScore\n";
	*pScore += 500;
	cout << "score is: " << score << "\n";
	cout << "*pScore is: " << *pScore << "\n\n";

	cout << "Assigning &newScore to pScore\n";
	int newScore = 5000;
	pScore = &newScore;
	cout << "&newScore is: " << &newScore << "\n";
	cout << "pScore is: " << pScore << "\n";
	cout << "newScore is: " << newScore << "\n";
	cout << "*pScore is: " << *pScore << "\n\n";

	cout << "Assigning &str o pStr\n";
	string str = "score";
	string* pStr = &str;

	cout << "str is: " << str << "\n";
	cout << "*pStr is: " << *pStr << "\n";
	cout << "(*pStr).size() is: " << (*pStr).size() << "\n";
	cout << "pStr->size() is: " << pStr->size() << "\n";

	return 0;
}
*/
