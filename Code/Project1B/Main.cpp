#include "poly.h"
using namespace std;

void main() {
	char YN;
	bool exit = false;
	string poly1 = "", poly2 = "";
	while (!exit) {
		system("CLS");
		cout << "Enter polynomial 1: " << endl;
		cin >> poly1;
		cout << "Enter polynomial 2: " << endl;
		cin >> poly2;
		try {
			poly p1(poly1);
			poly p2(poly2);
			cout << "Polynomial 1: ";
			p1.print();
			cout << "Polynomial 2: ";
			p2.print();
			cout << "Sum: ";
			poly p3(p1 + p2);
			p3.print();
			cout << endl;
			cout << "Do you wish to exit? (Y/N)" << endl;
			cin >> YN;
			if (toupper(YN) == 'Y') {
				exit = true;
			}
		}
		catch (const std::invalid_argument& ia) {
			cout << ia.what() << '\n';
			cout << "Do you wish to exit? (Y/N)" << endl;
			cin >> YN;
			if (toupper(YN) == 'Y') {
				exit = true;
			}
		}
	}

	system("pause");
};