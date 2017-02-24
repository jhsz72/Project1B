#ifndef POLY_H
#define POLY_H

#include <list>
#include <iostream>
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
	void updateCoefficient(int coe) {coefficient += coe;}
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
		return term(exponent, coefficient + rhs.getCoefficient());
	}

	friend const bool operator<(int exponent, const term &rhs) { return exponent < rhs.exponent; } //Less than operator overload. Used to compare exponents
};


class poly {
private:
	list<term> termList; //List that holds the terms of the polynomial
	int currentDegree;
	void push_front(term newTerm); //Adds a new term to the front of the list
public:
	poly(const poly& source) {};//initialization
	~poly(){};
	poly() { currentDegree = 0; };
	void addTerm(term NewTerm); //Adds a new term to the list, in proper position according to exponent sorting
	void print(); //Prints properly formatted polynomial
	const poly operator+(const poly &rhs);
};


#endif /* POLY_H */#pragma once
