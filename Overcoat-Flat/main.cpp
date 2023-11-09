#include "Task1.h"
#include "Task2.h"
#include <iostream>
#include <string>
using namespace std;

#pragma region SpecialAbilities

void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tFlat" << endl;
}
void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "Press enter to continue: "; getline(cin, enter);
	} while (!enter.empty());
}

#pragma endregion

int main() {

	int choice = 0;

	do {

		do {

			ClearScrean();
			cout << "Home work\n[1] - Overcoat\n[2] - Flat\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 2);

		ClearScrean();

		if (choice == 1)Task1();
		else if (choice == 2)Task2();

	} while (choice != 0);

	return 0;
}