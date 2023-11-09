#include "Overcoat.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma region SpecialAbilities

void ClearScreanTask1() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tOvercoat" << endl;
}
extern void Enter();
#pragma endregion

bool PrintAllOvercoat(vector<Overcoat>& overcoats) {

	if (overcoats.size() != 0) {

		for (int i = 0; i != overcoats.size(); i++) {
			cout << i + 1 << "-th "; overcoats[i].PrintInfoOvercoat();
		}

		return true;

	}
	else cout << "To work with overcoats need at least one overcoat in list!" << endl;
	return false;
}

Overcoat AddNewOvercoat() {

	char type[40];
	char size[40];
	double price = 0;

	cin.ignore();
	cout << "Enter type overcoat: "; cin.getline(type, 40);
	cout << "Enter size(example: XL) overcoat: "; cin.getline(size, 40);

	cout << "Enter price(dollars) overcoat: "; cin >> price;

	return Overcoat{ type, size, price < 0 ? price * -1 : price };
}

int ChoiceOvercoat(vector<Overcoat>& overcoats) {

	int choiceOvercoat = 1, size = overcoats.size();

	do {

		if (choiceOvercoat >= 1 && choiceOvercoat <= size)cout << "Enter your choice: ";
		else cout << "There is no such choice!\nEnter your choice again: ";

		cin >> choiceOvercoat;

		ClearScreanTask1();
		PrintAllOvercoat(overcoats);

	} while (choiceOvercoat < 1 || choiceOvercoat > size);

	return --choiceOvercoat;

}

void DeleteOvercoat(vector<Overcoat>& overcoats) {

	if (PrintAllOvercoat(overcoats) == true) {

		int index = ChoiceOvercoat(overcoats);

		overcoats.erase(overcoats.begin() + index);

		ClearScreanTask1();
		cout << "Delete was successful!" << endl;

	}

}

void IsEqualityType(vector<Overcoat>& overcoats) {

	if (PrintAllOvercoat(overcoats) == true) {

		int index[2];

		for (int i = 0; i != 2; i++) {
			cout << "\nYou fill out " << i + 1 << "-th overcoat(After any action this text will disappear)!" << endl;
			index[i] = ChoiceOvercoat(overcoats);
		}

		ClearScreanTask1();
		overcoats[index[0]].PrintInfoOvercoat();

		if (overcoats[index[0]] == overcoats[index[1]])cout << "type equal to type" << endl;
		else cout << "type not equal type" << endl;

		overcoats[index[1]].PrintInfoOvercoat();
		cout << endl;

	}
}

void ReworkInfoOvercoat(vector<Overcoat>& overcoats) {

	if (PrintAllOvercoat(overcoats) == true) {

		cout << "\nYou write down the number of the overcoating that will be altered"
			<< "(After any action this text will disappear)!" << endl;;
		int indexChang = ChoiceOvercoat(overcoats), choice = 1;

		do {

			ClearScreanTask1();
			cout << "Action\n[1] - Remake overcoats to match those already on the list"
				<< "\n[2] - Remake overcoats according to the filled in data" << endl;

			if (choice >= 1 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 1 || choice > 2);

		ClearScreanTask1();

		if (choice == 1) {

			PrintAllOvercoat(overcoats);
			int indexReplac = ChoiceOvercoat(overcoats);
			overcoats[indexChang] = overcoats[indexReplac];
		}
		else if (choice == 2) {

			overcoats[indexChang] = AddNewOvercoat();
		}

		cout << "The changes were successful!" << endl;
	}
}

void IsEqualityPrice(vector<Overcoat>& overcoats) {

	if (PrintAllOvercoat(overcoats) == true) {

		int index[2];

		for (int i = 0; i != 2; i++) {
			cout << "\nYou fill out " << i + 1 << "-th overcoat(After any action this text will disappear)!" << endl;
			index[i] = ChoiceOvercoat(overcoats);
		}

		ClearScreanTask1();
		overcoats[index[0]].PrintInfoOvercoat();

		if (overcoats[index[0]] < overcoats[index[1]])cout << "less for " << endl;
		else if (overcoats[index[0]] > overcoats[index[1]])cout << "more for " << endl;
		else cout << "equal to " << endl;

		overcoats[index[1]].PrintInfoOvercoat();
		cout << endl;

	}
}

int Task1() {

	vector<Overcoat> overcoats;
	int choice = 0;
	do {

		do {

			ClearScreanTask1();
			cout << "Action\n[1] - Add overcoats\n[2] - Print all overcoats\n"
				<< "[3] - Delete overcoats\n[4] - Checking the equality of overcoathig types\n"
				<< "[5] - Transforming an item into another\n"
				<< "[6] - Overcoats price equality\n[0] - Exit to menu" << endl;

			if (choice >= 0 && choice <= 6)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 6);

		ClearScreanTask1();

		switch (choice) {

		case 1: overcoats.push_back(AddNewOvercoat()); break;

		case 2: PrintAllOvercoat(overcoats); break;

		case 3: DeleteOvercoat(overcoats); break;

		case 4: IsEqualityType(overcoats); break;

		case 5: ReworkInfoOvercoat(overcoats); break;

		case 6: IsEqualityPrice(overcoats); break;
		}

		if (choice != 0)Enter();

	} while (choice != 0);

	return 0;
}