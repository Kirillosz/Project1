#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
}
void Competition(int choice)
{
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
				Race[i] -= rand() % 150;
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
		if (FinalPositions[i] == Riders()[choice-1])
		{
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
		SetConsoleTextAttribute(hConsole, 7);
		cout << i + 1 << ". " << FinalPositions[i] << endl;
	}
	if (FinalPositions[0] == Riders()[choice-1])
	{
		cout << "\nCongratulations, your horse win!" << endl;
	}
	else
	{
		cout << "\nSorry, but your horse lose." << endl;
	}

}
string choose(int choice)
{
	return Riders()[choice-1];
}
int main()
{
	Display();
	cout << "\nWhich rider are you wanna make a deposit?" << endl;
	int choice;
	cin >> choice;
	cout << "\nYou are bet for: ";
	cout << choose(choice);
	cout << "\nOkay, the riders has to start!\n";
	system("pause");
	Competition(choice);

	return 0;
}