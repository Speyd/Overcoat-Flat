#include <iostream>
using namespace std;

class Flat {

private:

	char* name;
	double square;
	double price;

	void AddCharArray(char*& charArray, const char* newText) {
		if (newText != nullptr) {

			charArray = new char[strlen(newText) + 1];
			strcpy_s(charArray, strlen(newText) + 1, newText);
		}
	}
	void DeleteCharArray(char*& charArray) {
		if (charArray != nullptr)delete[] charArray;
	}

public:

	Flat(const char* nameP, const double squareP, const double priceP)
		:name{ nullptr }, square{ squareP < 0 ? squareP * -1: squareP }, price{ priceP < 0 ? priceP * -1 : priceP } {

		AddCharArray(name, nameP);

	}

	Flat(const char* nameP, const double squareP)
		:Flat{ nameP,squareP,0 } {}

	Flat(const char* nameP) :Flat{ nameP,0,0 } {}

	Flat() :Flat{ nullptr,0,0 } {}

	Flat(const Flat& overcoat)
		:Flat{ overcoat.name,overcoat.square,overcoat.price } {}

	Flat(Flat&& overcoat)
		:name{ overcoat.name }, square{ overcoat.square }, price{ overcoat.price } {

		overcoat.name = nullptr;
		overcoat.square = 0;
		overcoat.price = 0;

	}

	~Flat() {

		DeleteCharArray(name);

		this->square = 0;

		this->price = 0;
	}

	Flat& operator=(const Flat& flat) {
		if (this != &flat) {

			AddCharArray(name, flat.name);

			square = flat.square;

			price = flat.price;

		}

		return *this;

	}

	Flat& operator=(Flat&& flat) {

		if (this != &flat) {

			delete[] name;
			name = flat.name;
			flat.name = nullptr;

			square = flat.square;
			flat.square = 0;

			price = flat.price;
			flat.price = 0;

		}

		return *this;

	}

	friend bool operator==(const Flat& flat1, const Flat& flat2) {

		return flat1.square == flat2.square;

	}

	friend bool operator<(const Flat& flat1, const Flat& flat2) {

		return flat1.price < flat2.price;

	}

	friend bool operator>(const Flat& flat1, const Flat& flat2) {

		return flat1.price > flat2.price;

	}

	string GetName() { return this->name != nullptr ? this->name : "Indefined"; }

	double GetSquare() { return this->square; }

	double GetPrice() { return this->price; }

	void PrintInfoFlat() {
		cout << "Flat(" << this->name << ") with size(" << this->square
			<< " m^2) costs " << this->price << " dollars" << endl;
	}

};