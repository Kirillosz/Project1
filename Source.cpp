#include <iostream>
#include <vector>
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
	return 0;
}