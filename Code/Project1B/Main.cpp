//#include <iostream>
//#include <list>
#include "poly.h"
#include "String_Tokenizer.h"
using namespace std;

void main() {
	//poly p, q;
	//poly r;

	//p.addTerm(term(-5, 3));
	//p.addTerm(term(5, 3));
	//p.addTerm(term(3, 2));
	//p.addTerm(term(2, 1));
	//p.addTerm(term(1, 0));


	//q.addTerm(term(3, 2));
	//q.addTerm(term(2, 1));
	//q.addTerm(term(1, 0));

	//r = p + q;
	//r = p.add(q);
	//r.print();
	
	string e = "5X^2+5X+3X^2+2-4+3X-2X^3";
	string token = "";
	String_Tokenizer s(e, "+-");
	string okCoefficients = "+-0123456789";
	size_t found = string::npos;
	bool invalid = false;
	int coefficient = 0;
	string strCoefficient = "";
	int exponent = 0;
	string strExponent = "";
	int tokenSize = token.size();
	while (s.has_more_tokens()&&!invalid) {
		token = s.next_token();
		cout << token << endl;
		int i = 0;
		while ((toupper(token[i]) != 'X')&&(i<tokenSize)) {
			found = okCoefficients.find(token[i]);
			if (found == string::npos) {
				cout << "Invalid coefficient value given in " << token;
				invalid = true;
			}
			else {
				i++;
			}
		}
		strCoefficient = token.substr(0, i);
		if (strCoefficient == "") {
			coefficient = 1;
		}
		else if (strCoefficient == "-") {
			coefficient - 1;
		}
		else {
			coefficient = stoi(strCoefficient);
		}
		if (i == tokenSize - 1) {
			exponent = 0;
		}
		else if (i == tokenSize - 2) {
			exponent = 1;
		}
	}


	//	How many monomials has the polynomial?
	int k = 1;
	for (int i = 1; i < strSize; ++i)
		if (str[i] == '+' || str[i] == '-')
			k++;
	int monoms = k;
	system("pause");
};