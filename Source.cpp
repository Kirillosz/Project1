#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
double Money = 5;
double* Cash = &Money;
static vector<string> Riders()
{
	vector<string> Riders;
	Riders.push_back("Caroline");
	Riders.push_back("Stefanie");
	Riders.push_back("Olga");
	Riders.push_back("Helga");
	Riders.push_back("Taomato");
	Riders.push_back("Gwen");
	Riders.push_back("Barbie");
	return Riders;
}
void Display()
{
	int i = Riders().size();
	int j = 0;
	while (j < i)
	{
		cout << j+1 << ". " << Riders()[j] << "\n";
		++j;
	}
	system("pause");
}
void Deposit(double* Cash)
{
	if (*Cash > 0)
	{
		cout << "\nYou have: " << *Cash << "$" << endl;
		system("pause");
	}
	else
		cout << "\nYour balance was: " << *Cash << "$, you can't make bet!" << endl;

}
void Competition()
{
	if (*Cash > 1)
	{
		Display();
		cout << "\nWhich rider are you wanna make a deposit?: ";
		int choice;
		cin >> choice;
		"\nOkay, the riders has to start!\n";
		system("pause");
		const int num_el = 7;
		int Race[num_el];
		string FinalPositions[num_el];
		int SetFinals = 0;
		for (int i = 0; i < num_el; ++i)
		{
			Race[i] = 3000;
		}
		while (Race[0] > 1 || Race[1] > 1 || Race[2] > 1 || Race[3] > 1 &&
			Race[4] > 1 || Race[5] > 1 || Race[6] > 1)
		{
			srand(static_cast<unsigned int>(time(0)));
			for (int i = 0; i <= num_el; ++i)
			{
				if (Race[i] > 500)
				{
					cout << "*-" << endl;
					Race[i] -= rand() % 150 + 5;
					system("cls");
					cout << "_*" << endl;
					system("cls");
				}
				if (Race[i] < 500 && Race[i] > 1)
				{
					cout << "*-" << endl;
					Race[i] -= rand() % Race[i];
					system("cls");
					cout << "_*" << endl;
					system("cls");
				}
				if (Race[i] == 1)
				{
					FinalPositions[SetFinals] = Riders()[i];
					SetFinals += +1;
					Race[i] = 0;
				}
			}
		}
		for (int i = 0; i < num_el; ++i)
		{
			if (FinalPositions[i] == Riders()[choice - 1])
			{
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
				SetConsoleTextAttribute(hConsole, 7);
			cout << i + 1 << ". " << FinalPositions[i] << endl;
		}
		if (FinalPositions[0] == Riders()[choice - 1])
		{
			cout << "\nCongratulations, your horse win!" << endl;
			*Cash = *Cash + (*Cash / 2);
			Deposit(Cash);
		}
		else
		{
			cout << "\nSorry, but your horse lose." << endl;
			*Cash = *Cash / 2;
			Deposit(Cash);
		}
	}
	else
	{
		cout << "Your balance was under 1$, you need much money on your deposite!\n" << endl;
		system("pause");
	}

}
string choose(int choice)
{
	return Riders()[choice-1];
}
int main()
{
	int menu = 0;
	while (menu != 4)
	{
		system("cls");
		cout << "Welcome to the sport bet-totalizator! Choose:\n " << endl;
		cout << "1. Check my cash account\n " << endl;
		cout << "2. Show the start positions\n " << endl;
		cout << "3. Make a bet and start the Game!\n " << endl;
		cout << "4. For exit\n" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1: system("cls"); Deposit(Cash); break;
		case 2: system("cls"); Display(); break;
		case 3: system("cls"); Competition(); break;
		case 4: break;
		default:
			break;
		}
	}
	return 0;
}