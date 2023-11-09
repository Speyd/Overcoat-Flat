#include <iostream>
using namespace std;

class Overcoat {

private:

	char* type;
	char* size;
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

	Overcoat(const char* typeP,const char* sizeP, const double priceP) 
		:type{ nullptr }, size{ nullptr }, price{ priceP < 0 ? priceP * -1 : priceP } {
	

		AddCharArray(type, typeP);

		AddCharArray(size, sizeP);

	}

	Overcoat(const char* typeP, const char* sizeP)
		:Overcoat{ typeP,sizeP,0 } {}

	Overcoat(const char* typeP) :Overcoat{ typeP,nullptr,0 } {}

	Overcoat() :Overcoat{ nullptr,nullptr,0 } {}

	Overcoat(const Overcoat& overcoat) 
		:Overcoat{ overcoat.type,overcoat.size,overcoat.price}{}

	Overcoat(Overcoat&& overcoat) 
		:type{ overcoat.type }, size{ overcoat.size }, price{ overcoat.price } {

		overcoat.type = nullptr;
		overcoat.size = nullptr;
		overcoat.price = 0;

	}

	~Overcoat() {

		DeleteCharArray(type);

		DeleteCharArray(size);

		this->price = 0;
	}

	Overcoat& operator=(const Overcoat& overcoat) {
		if (this != &overcoat) {

			AddCharArray(type, overcoat.type);

			AddCharArray(size, overcoat.size);

			price = overcoat.price;

		}

		return *this;

	}

	Overcoat& operator=(Overcoat&& overcoat) {

		if (this != &overcoat) {

			delete[] type;
			type = overcoat.type;
			overcoat.type = nullptr;

			delete[] size;
			size = overcoat.size;
			overcoat.size = nullptr;

			price = overcoat.price;
			overcoat.price = 0;

		}

		return *this;

	}

	friend bool operator<(const Overcoat& overcoat1, const Overcoat& overcoat2) {

		return overcoat1.price < overcoat2.price;

	}

	friend bool operator>(const Overcoat& overcoat1, const Overcoat& overcoat2) {

		return overcoat1.price > overcoat2.price;

	}

	friend bool operator==(const Overcoat& overcoat1, const Overcoat& overcoat2) {
		return *overcoat1.type == *overcoat2.type;
	}

	string GetType() { return this->type != nullptr ? this->type : "Indefined"; }

	string GetSize() { return this->size != nullptr ? this->size : "Indefined"; }

	double GetPrice() { return this->price; }

	void PrintInfoOvercoat() {
		cout << "Overcoat(" << this->type << ") with size(" << this->size
			<< ") costs " << this->price << " dollars" << endl;
	}

};