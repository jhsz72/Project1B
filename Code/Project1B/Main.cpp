//#include <iostream>
//#include <list>
#include "poly.h"
using namespace std;

void main() {
	poly p, q;
	poly r;

	p.addTerm(term(-5, 3));
	p.addTerm(term(5, 3));
	p.addTerm(term(3, 2));
	p.addTerm(term(2, 1));
	p.addTerm(term(1, 0));


	q.addTerm(term(3, 2));
	q.addTerm(term(2, 1));
	q.addTerm(term(1, 0));

	r = p + q;
	r = p.add(q);
	r.print();
	
	system("pause");
};