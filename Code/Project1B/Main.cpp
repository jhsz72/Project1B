//#include <iostream>
//#include <list>
#include "poly.h"
using namespace std;

void main() {
	poly p;

	p.addTerm(term(5, 3));
	p.addTerm(term(3, 2));
	p.addTerm(term(2, 1));
	p.addTerm(term(1, 0));

	p.print();
	
	system("pause");
};