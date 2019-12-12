//critter caretaker game, original implentation by CENGAGE 4th edition. Modified and built by Mark Foos at ASUMH
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

class Critter
{
public:
	Critter(int level = 1, int health = 10, int attack = 5, int defense = 5);
	void Heal();
	void LevelUp();
	void GetStats();
	void Battle();

private:
	int m_Level;
	int m_Health;
	int m_Attack;
	int m_Defense;

	int GetTrueAttack() const;
	int GetTrueDefense() const;
	int GetTrueHealth() const;
};

Critter::Critter(int level, int health, int attack, int defense) :
	m_Level(level),
	m_Health(health),
	m_Attack(attack),
	m_Defense(defense)
{}

inline int Critter::GetTrueAttack() const
{
	return((m_Level * m_Attack));
}

inline int Critter::GetTrueDefense() const
{ 
	return((m_Level * m_Defense)); 
} 

inline int Critter::GetTrueHealth() const
{
	if (m_Health < 0)
	{
		return 10;
	}
	else
	{
		return m_Health;
	}
}

void Critter::GetStats()
{
	int attack = GetTrueAttack();
	int defense = GetTrueDefense();
	int level = m_Level;
	int health = GetTrueHealth();
	sleep_for(100000000ns);
	cout << "Here are your Critter's current stats:\n\n";
	sleep_for(100000000ns);
	cout << "Current Level is: " << level << "\n";
	sleep_for(100000000ns);
	cout << "Current Health is: " << health << "\n";
	sleep_for(100000000ns);
	cout << "Current Attack is: " << attack << "\n";
	sleep_for(100000000ns);
	cout << "Current Defense is: " << defense << "\n\n";
	sleep_for(100000000ns);
}

void Critter::Heal()
{
	cout << "Healing Critter\n\n";
	m_Health = m_Health + 10;
	cout << "Current Health is now: " << m_Health << "\n\n";
}

void Critter::LevelUp()
{
	cout << "Leveling up Critter \n\n";
	m_Level = m_Level + 1;
	cout << "Current Level is now: " << m_Level << "\n\n";
}

void Critter::Battle()
{
	cout << "Your critter has entered a fight with another critter!\n\n";
		sleep_for(100000000ns);
	srand(static_cast<unsigned int>(time(0)));
	int oppLevel = rand() % 10 + 1;
	cout << "Opp Level is: " << oppLevel << "\n\n";	sleep_for(100000000ns);
	int oppHealth = oppLevel * 10;
	int oppAttack = oppLevel * 5;
	int oppDefense = oppLevel * 5;
	cout << "Here are the opponent critter's stats:\n";	sleep_for(100000000ns);
	cout << "Health is: " << oppHealth << "\n";	sleep_for(100000000ns);
	cout << "Attack is: " << oppAttack << "\n";	sleep_for(100000000ns);
	cout << "Defense is: " << oppDefense << "\n";	sleep_for(10000000ns);
	
	int battleDamage = (GetTrueAttack() - oppDefense);
	if (battleDamage > 0)
	{
		battleDamage = battleDamage;
	}
	else
	{
		battleDamage = 10;
	}
	//cout << "Battle Damage is: " << battleDamage << "\n";

	int damageTaken = (oppAttack - GetTrueDefense());
	if (damageTaken > 0)
	{
		damageTaken = damageTaken;
	}

	else
	{
		damageTaken = 10;
	}

	//cout << "damageTaken is: " << damageTaken << "\n";
	
do
{
	cout << "Entering Battle Sequence!\n\n";

	int choice;
	cout << "0 - get stats on your Critter\n";
	sleep_for(100000000ns);
	cout << "1 - attack enemy critter\n";
	sleep_for(100000000ns);
	cout << "2- defend against enemy critter\n";
	sleep_for(100000000ns);
	cout << "3 - run away from enemy critter\n";
	sleep_for(100000000ns);
	cin >> choice;
	switch (choice)
	{
	case 0:
		GetStats();
		break;
	case 1:
		cout << "Attacking enemy critter, enemy critter takes " << battleDamage << " damage";
		oppHealth = oppHealth - battleDamage;
		cout << "\n\nOpponent critter health is: " << oppHealth << "\n\n";
sleep_for(1000000000ns);
if (oppHealth <= 0)
{
cout << "Your critter defeated the enemy critter. Good job.\n";
cout << ".......................................................................\n\n\n";
	break;
}
cout << ".......................";
		sleep_for(100000000ns);
		cout << "....................";
sleep_for(1000000000ns);
				cout << "enemy critter STRIKES!\n\n";
			m_Health = m_Health - damageTaken;
			cout << "Your current health is now: " << m_Health << "\n\n";
				sleep_for(100000000ns);
				if (m_Health <= 0)
				{
					cout << "Your critter has passed out and has been taken to the nearest vet hospital";
				}
				else if (oppHealth <= 0)
				{
					cout << "Your critter defeated the enemy critter. Good job.";
				}
				else
				{
					break;
				}
	case 2:
		cout << "Defending against enemy critter, upping defense!\n\n";
			sleep_for(100000000ns);
		m_Defense = m_Defense + 15;
		cout << "...................................\n";
		sleep_for(100000000ns);
		cout << "...............................\n";
		sleep_for(1000000000ns);
		cout << "enemy critter STRIKES!\n";
			m_Health = m_Health - damageTaken;
			sleep_for(1000000000ns);
			cout << "Your current health is now: " << m_Health << "\n\n";
				sleep_for(100000000ns);
		if (m_Health <= 0)
				{
					cout << "Your critter has passed out and has been taken to the nearest vet hospital";
				}
		else if (oppHealth <= 0)
		{
			cout << "Your critter defeated the enemy critter. Good job.";
		}
		else
		{
			break;
		}
	case 3:
		oppHealth = 0;
		break;
	default:
		cout << "Enter a valid input";
		break;
	}



} while (oppHealth > 0 && m_Health > 0);

}




int main()
{
	Critter crit;
		int choice;
	do
	{
		cout << "\nWelcome to Battle Critter!\n\n";
			sleep_for(10000000ns);
		cout << "I am your new battle critter critter! \n\n";
			sleep_for(10000000ns);
	crit.GetStats();


		cout << "0 - Quit\n";
			sleep_for(10000000ns);
		cout << "1 - Get Critter Stats\n";
			sleep_for(10000000ns);
		cout << "2 - Heal your Critter\n";
			sleep_for(10000000ns);
		cout << "3 - Level Up your Critter\n";
			sleep_for(10000000ns);
		cout << "4 - Battle your Critter\n\n";
	sleep_for(10000000ns);
		cout << "Choice: ";
			sleep_for(10000000ns);
			cin >> choice;
		
		switch (choice)
		{
		case 0:

			sleep_for(1000000000ns);
			cout << "...";
			sleep_for(1000000000ns);
			cout << "...";
			sleep_for(1000000000ns);
			cout << "...";
			sleep_for(1000000000ns);
			cout << "\nGood Bye \n";
			break;
		case 1:
			crit.GetStats();
			break;
		case 2:
			crit.Heal();
			break;
		case 3:
			crit.LevelUp();
			break;
		case 4:
			crit.Battle();
			break;
		default:
			cout << "\nSorry, but " << choice << "isn't valid.\n";
		}
	} while (choice != 0);
	system("PAUSE");
	return 0;
}

/*#include "pch.h"
#include <iostream>

using namespace std;

class Critter
{
public:
	static int s_Total;


	Critter(int hunger = 0);
	static int GetTotal();

private:
	int m_Hunger;
};

int Critter::s_Total = 0;

Critter::Critter(int hunger) :
	m_Hunger(hunger)
{
	cout << "A critter has been born" << endl;
	++s_Total;
}

int Critter::GetTotal()
{
	return s_Total;
}

int main()
{
	cout << "The total number of critters is: ";
	cout << Critter::s_Total << "\n\n";

	Critter crit1, crit2, crit3;

	cout << "\nThe total number of critters is: ";
	cout << Critter::GetTotal() << "\n";

	return 0;
}

*/



/*#include "pch.h"
#include <iostream>

using namespace std;

class Critter
{
public:
	Critter(int hunger = 0);
	int GetHunger() const;
	void SetHunger(int hunger);
private:
	int m_Hunger;
};

Critter::Critter(int hunger) :
	m_Hunger(hunger)
{
	cout << "A new critter has been born!" << endl;
}

int Critter::GetHunger() const
{
	return m_Hunger;
}

void Critter::SetHunger(int hunger)
{
	if (hunger < 0)
	{
		cout << "You can't set a critter's hunger to a negative number. \n\n";
	}
	else
	{
		m_Hunger = hunger;
	}
}

int main()
{
	Critter crit(5);
	cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";

	cout << "Calling SetHunger() with -1.\n";
	crit.SetHunger(-1);

	cout << "Calling SetHunger() with 9. \n";
	crit.SetHunger(9);
	cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";

	return 0;
}

*/




/*#include "pch.h"
#include <iostream>

using namespace std;

class Critter
{
public: 
	int m_Hunger;

	Critter(int hunger = 0);
	void Greet();
};

Critter::Critter(int hunger)
{
	cout << "A new critter has been born!" << endl;
	m_Hunger = hunger;
}

void Critter::Greet()
{
	cout << "Hi, Im a critter. My hunger level is " << m_Hunger << ".\n\n";
}

int main()
{
	Critter crit(7);
	crit.Greet();

	return 0;
}

*/




/* #include "pch.h"
#include <iostream>

using namespace std;

class Critter
{
public:
	int m_Hunger;
	void Greet();
};

void Critter::Greet()
{
	cout << "Hi, I'm a cretter. My hunger level is " << m_Hunger << ".\n";
}



int main()
{
	Critter crit1;
	Critter crit2;

	crit1.m_Hunger = 9;
	cout << "crit1's hunger level is " << crit1.m_Hunger << ".\n";

	crit2.m_Hunger = 3;
	cout << "crit2's hunger level is " << crit2.m_Hunger << ".\n\n";

	crit1.Greet();
	crit2.Greet();

	return 0;
}
*/
