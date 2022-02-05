#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;
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
	int Race[7];
	for (int i = 0; i < 7; ++i)
	{
		Race[i] = 3000;
	}
	while (Race[0] > 1 && Race[1] > 1 && Race[2] > 1 && Race[3] > 1 &&
		Race[4] > 1 && Race[5] > 1 && Race[6] > 1)
	{
		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i < 7; ++i)
		{
			if (Race[i] > 500)
			{
				cout << "Running..." << endl;
				Race[i] -= rand() % 150;
			}
			if (Race[i] < 500 && Race[i] > 1)
			{
				cout << "Running..." << endl;
				Race[i] -= rand() % Race[i];
			}
			if (Race[i] <= 1 && i == choice - 1)
			{
				cout << "Your horse already Win! Congrats! Ridername: ";
				cout << Riders()[i];
				break;
			}
			else if (Race[i] <= 1 && i != choice - 1)
			{
				cout << "Sorry your horse lose! The winner Ridername: ";
				cout << Riders()[i];
				break;
			}
		}
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