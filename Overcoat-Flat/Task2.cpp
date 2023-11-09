#include "Flat.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma region SpecialAbilities

void ClearScreanTask2() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tFlat" << endl;
}
extern void Enter();

#pragma endregion

bool PrintAllFlat(vector<Flat>& flats) {

	if (flats.size() != 0) {

		for (int i = 0; i != flats.size(); i++) {
			cout << i + 1 << "-th "; flats[i].PrintInfoFlat();
		}

		return true;

	}
	else cout << "To work with flats need at least one flat in list!" << endl;
	return false;
}

Flat AddNewFlat() {

	char name[40];
	double square = 0;
	double price = 0;

	cin.ignore();
	cout << "Enter name flat: "; cin.getline(name, 40);

	cout << "Enter square(m^2) flat: "; cin >> square;
	cout << "Enter price(dollars) flat: "; cin >> price;

	return Flat{ name, square < 0 ? square * -1 : square, price < 0 ? price * -1 : price };
}

int ChoiceFlat(vector<Flat>& flats) {

	int choiceFlats = 1, size = flats.size();

	do {

		if (choiceFlats >= 1 && choiceFlats <= size)cout << "Enter your choice: ";
		else cout << "There is no such choice!\nEnter your choice again: ";

		cin >> choiceFlats;

		ClearScreanTask2();
		PrintAllFlat(flats);

	} while (choiceFlats < 1 || choiceFlats > size);

	return --choiceFlats;

}

void DeleteFlat(vector<Flat>& flats) {

	if (PrintAllFlat(flats) == true) {

		int index = ChoiceFlat(flats);

		flats.erase(flats.begin() + index);

		ClearScreanTask2();
		cout << "Delete was successful!" << endl;

	}

}

void IsEqualitySquare(vector<Flat>& flats) {

	if (PrintAllFlat(flats) == true) {

		int index[2];

		for (int i = 0; i != 2; i++) {
			cout << "\nYou fill out " << i + 1 << "-th flats(After any action this text will disappear)!" << endl;
			index[i] = ChoiceFlat(flats);
		}

		ClearScreanTask2();
		flats[index[0]].PrintInfoFlat();

		if (flats[index[0]] == flats[index[1]])cout << "square equal to square" << endl;
		else cout << "square not equal square" << endl;

		flats[index[1]].PrintInfoFlat();
		cout << endl;

	}
}

void ReworkInfoFlat(vector<Flat>& flats) {

	if (PrintAllFlat(flats) == true) {

		cout << "\nYou write down the number of the flats that will be altered"
			<< "(After any action this text will disappear)!" << endl;;
		int indexChang = ChoiceFlat(flats), choice = 1;

		do {

			ClearScreanTask2();
			cout << "Action\n[1] - Remake flats to match those already on the list"
				<< "\n[2] - Remake flats according to the filled in data" << endl;

			if (choice >= 1 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 1 || choice > 2);

		ClearScreanTask2();

		if (choice == 1) {

			PrintAllFlat(flats);
			int indexReplac = ChoiceFlat(flats);
			flats[indexChang] = flats[indexReplac];
		}
		else if (choice == 2) {

			flats[indexChang] = AddNewFlat();
		}

		cout << "The changes were successful!" << endl;
	}
}

void IsEqualityPrice(vector<Flat>& flats) {

	if (PrintAllFlat(flats) == true) {

		int index[2];

		for (int i = 0; i != 2; i++) {
			cout << "\nYou fill out " << i + 1 << "-th flats(After any action this text will disappear)!" << endl;
			index[i] = ChoiceFlat(flats);
		}

		ClearScreanTask2();
		flats[index[0]].PrintInfoFlat();

		if (flats[index[0]] < flats[index[1]])cout << "less for " << endl;
		else if (flats[index[0]] > flats[index[1]])cout << "more for " << endl;
		else cout << "equal to " << endl;

		flats[index[1]].PrintInfoFlat();
		cout << endl;

	}
}

int Task2() {

	vector<Flat> flats;
	int choice = 0;
	do {

		do {

			ClearScreanTask2();
			cout << "Action\n[1] - Add flats\n[2] - Print all flats\n"
				<< "[3] - Delete flats\n[4] - Checking the equality of flats square\n"
				<< "[5] - Transforming an flats into another\n"
				<< "[6] - Flats price equality\n[0] - Exit to menu" << endl;

			if (choice >= 0 && choice <= 6)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 6);

		ClearScreanTask2();

		switch (choice) {

		case 1: flats.push_back(AddNewFlat()); break;

		case 2: PrintAllFlat(flats); break;

		case 3: DeleteFlat(flats); break;

		case 4: IsEqualitySquare(flats); break;

		case 5: ReworkInfoFlat(flats); break;

		case 6: IsEqualityPrice(flats); break;
		}

		if (choice != 0)Enter();

	} while (choice != 0);

	return 0;
}