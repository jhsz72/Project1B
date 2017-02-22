#ifndef POLY_H
#define POLY_H

#include <list>
using namespace std;

class term {
private:
	long coefficient; //Holds the multiplier
	long exponent; //Holds the exponent
public:
	term(int coe, int exp) : coefficient(coe), exponent(exp) {}; //initialization
	bool operator>(const term &rhs) { return exponent > rhs.exponent; } //Greater operator overload. Used to compare exponents
	bool operator=(const term &rhs) { return exponent = rhs.exponent; } //Greater operator overload. Used to compare exponents
	bool operator<(const term &rhs) { return exponent < rhs.exponent; } //Greater operator overload. Used to compare exponents
};

#endif /* POLY_H */#pragma once
