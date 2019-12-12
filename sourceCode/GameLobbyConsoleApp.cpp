//Game Lobby simulation for advanced classes, original concept by Cengage 4th edition
//Created by Mark Foos

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player(const string& name = "");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);

private:
	string m_Name;
	Player* m_pNext;
};

Player::Player(const string& name) :
	m_Name(name),
	m_pNext(0)
{}

string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}

class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);

public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player* m_pHead;
};

Lobby::Lobby():
m_pHead(0)
{}

Lobby::~Lobby()
{
	Clear();
}

void Lobby::AddPlayer()
{
	cout << "Please enter the name of the new player: ";
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name);

	if (m_pHead == 0)
	{
		m_pHead = pNewPlayer;
	}

	else
	{
		Player* pIter = m_pHead;
		while (pIter->GetNext() != 0)
		{
			pIter = pIter->GetNext();
		}
		pIter->SetNext(pNewPlayer);
	}
}

void Lobby::RemovePlayer()
{
	if (m_pHead == 0)
	{
		cout << "The game lobby is empty. No one to remove!\n";
	}
	else
	{
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

void Lobby::Clear()
{
	while (m_pHead != 0)
	{
		RemovePlayer();
	}
}

ostream& operator<<(ostream& os, const Lobby& aLobby)
{
	Player* pIter = aLobby.m_pHead;

	os << "\nHere's who's in the game lobby: \n";
	if (pIter == 0)
	{
		os << "The lobby is empty. \n";
	}
	else
	{
		while (pIter != 0)
		{
			os << pIter->GetName() << endl;
			pIter = pIter->GetNext();
		}
	}
	return os;
}

int main()
{
	Lobby myLobby;
	int choice;

	do
	{
		cout << myLobby;
		cout << "\nGAME LOBBY\n";
		cout << "0 - Exit Program.\n";
		cout << "1 - Add a player to the lobby.\n";
		cout << "2 - Remove a player from the lobby.\n";
		cout << "3 - Clear the lobby.\n";
		cout << endl << "Enter Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0: cout << "Good-bye.\n"; break;
		case 1: myLobby.AddPlayer(); break;
		case 2: myLobby.RemovePlayer(); break;
		case 3: myLobby.Clear(); break;
		default: cout << "That was not a valid choice.\n";
		}
	} while (choice != 0);
	system("PAUSE");
	return 0;
}
/* #include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Critter
{
	friend void Peek(const Critter& aCritter);
	friend ostream& operator<<(ostream& os, const Critter& aCritter);

public:
	Critter(const string& name = "");

private:
	string m_Name;
};

Critter::Critter(const string& name):
m_Name(name)
{}

void Peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);

int main()
{
	Critter crit("Poochie");

	cout << "Calling Peek() to access crit's private data member, m_Name: \n";
	Peek(crit);

	cout << "\nSending crit object to cout with the << operator: \n";
	cout << crit;

	return 0;
}

void Peek(const Critter& aCritter)
{
	cout << aCritter.m_Name << endl;
}

ostream& operator<<(ostream& os, const Critter& aCritter)
{
	os << "Critter Object - ";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}

*/





/*#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Critter
{
public:
	Critter(const string& name = "");
	string GetName() const;

private:
	string m_Name;
};

Critter::Critter(const string& name) :
	m_Name(name)
{}
inline string Critter::GetName() const
{
	return m_Name;
}

class Farm
{
public:
	Farm(int spaces = 1);
	void Add(const Critter& aCritter);
	void RollCall() const;

private:
	vector<Critter> m_Critters;
};

Farm::Farm(int spaces)
{
	m_Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter)
{
	m_Critters.push_back(aCritter);
}

void Farm::RollCall() const
{
	for (vector<Critter>::const_iterator iter = m_Critters.begin();
		iter != m_Critters.end();
		++iter)
	{
		cout << iter->GetName() << " here.\n";
	}
}


int main()
{
	Critter crit("Poochie");
	cout << "My critter's name is " << crit.GetName() << endl;

	cout << "Creating critter farm\n";
	Farm myFarm(3);

	cout << "\nAdding three critters to the farm. \n";
	myFarm.Add(Critter("Moe"));
	myFarm.Add(Critter("Larry"));
	myFarm.Add(Critter("Curly"));

	cout << "\nCalling ROll... \n";
	myFarm.RollCall();
	return 0;
}


*/