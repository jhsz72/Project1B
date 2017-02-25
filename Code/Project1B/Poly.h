#ifndef POLY_H
#define POLY_H

#include <list>
#include <iostream>
#include "polyParser.h"

using namespace std;

class term {
private:
	int coefficient; //Holds the multiplier 
	int exponent; //Holds the exponent
public:
	void print(bool firstTerm); 
	term(int coe, int exp) : coefficient(coe), exponent(exp) {}; //initialization
	int getCoefficient() const { return coefficient; };
	int getExponent() const { return exponent; }
	void updateCoefficient(int coe) {
		int newCoefficient = coefficient + coe;
		coefficient = newCoefficient;
	}
	const bool operator>(const term &rhs) { return exponent > rhs.exponent; } //Greater than operator overload. Used to compare exponents
	const bool operator==(const term &rhs) { return exponent == rhs.exponent; } //Equal operator overload. Used to compare exponents
	const bool operator<(const term &rhs) { return exponent < rhs.exponent; } //Less than operator overload. Used to compare exponents
	const bool operator>=(const term &rhs) { return (exponent > rhs.exponent) || (exponent = rhs.exponent); } //Greater or equal operator overload. Used to compare exponents
	const bool operator<=(const term &rhs) { return (exponent < rhs.exponent)|| (exponent = rhs.exponent); } //Less or equal operator overload. Used to compare exponents
	const bool operator>(const int &exp) { return exponent > exp; } //Greater than operator overload. Used to compare exponents
	const bool operator==(const int &exp) { return exponent == exp; } //Equal operator overload. Used to compare exponents
	const bool operator<(const int &exp) { return exponent < exp; } //Less than operator overload. Used to compare exponents
	const bool operator>=(const int &exp) { return (exponent > exp) || (exponent = exp); } //Greater or equal operator overload. Used to compare exponents
	const bool operator<=(const int &exp) { return (exponent < exp) || (exponent = exp); } //Less or equal operator overload. Used to compare exponents

	term operator+(const term &rhs) {
		return term(coefficient + rhs.getCoefficient(), exponent);
	}

	friend const bool operator<(int exponent, const term &rhs) { return exponent < rhs.exponent; } //Less than operator overload. Used to compare exponents
};


class poly {
private:
	list<term> termList; //List that holds the terms of the polynomial
	void push_front(term newTerm); //Adds a new term to the front of the list, filters zero coefficients
	void addTerm(term NewTerm); //Adds a new term to the list, in proper position according to exponent sorting
public:
	poly(const poly& source);//copy constructor
	poly(string expression) { loadExpression(expression); }
	poly() {};
	~poly(){};
	void print(); //Prints properly formatted polynomial
	poly operator+(const poly &rhs);//Add 2 polynomials
	void loadExpression(string expression);
};


#endif /* POLY_H */#pragma once
