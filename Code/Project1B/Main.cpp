//#include <iostream>
//#include <list>
#include "poly.h"
#include "polyParser.h"
using namespace std;

void main() {
	string a = "-X+5+X^2-10";
	string b = "5X-5X^-2+10-5X+X^2";
	poly p(a);
	poly q(b);
	p.print();
	q.print();
	poly r = p + q;
	r.print();

	system("pause");
};