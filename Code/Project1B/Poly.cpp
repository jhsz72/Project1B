#include "poly.h"
using namespace std;

void term::print(bool firstTerm){
//Print the term in proper format 

	//Suppress the '+' on the first term
	if (!firstTerm && (coefficient > 0)) {
		cout << '+';
	}
	//Suppress '1' if before X and coefficient is -1
	if ((coefficient == -1)&&(exponent != 0)) {
		cout << '-';
	}
	//Suppress 1 before X if coefficient is 1
	else if (!((coefficient==1) && (exponent != 0))) {
		cout << coefficient;
	}

	//Suppress X if exponent is zero
	if (exponent == 0) {
		return;
	}
	cout << 'X';

	//Suppress exponent if 1
	if (exponent != 1) {
		cout << '^' << exponent;
	}
	return;
}

poly::poly(const poly& source) {
	termList = source.termList;
};

void poly::addTerm(term newTerm) {
//Add a term to the list in its proper sorted position

	if (newTerm.getCoefficient() == 0) {//Ignore zero coefficient term 
		return;
	}
	if (termList.empty()||(newTerm > termList.front())) {//Highest degree goes to the front
		termList.push_front(newTerm); //push the current at the end
	}
	else
	{
		list<term>::iterator iter = termList.begin();
		//Iterate through the list from greatest to least degree until the 
		//new term is equal or less than the current list term or until the 
		//iterator reaches the end

		while (iter != termList.end() && newTerm < iter->getExponent()) {
			iter++;
		}
		//If we reached the end, push it on the back of the list
		if (iter == termList.end()) {
			termList.push_back(newTerm);
			return;
		}
		//If node exists with matching exponent, just update the coefficient
		else if (*iter == newTerm) {
			iter->updateCoefficient(newTerm.getCoefficient());
			if (iter->getCoefficient() == 0) {
				termList.erase(iter); //if the updated coefficient is now zero, remove it.
			}
			return;
		}
		//If node does not exist for this degree in the middle of the list, insert new node
		else {
			termList.insert(iter, newTerm);
			return;
		}
	}
} 
void poly::print() {
 //Prints properly formatted polynomial
	bool first = true; //initialize for first term to suppress + if necessary
	for (list<term>::iterator iter = termList.begin(); iter != termList.end(); iter++) {
		iter->print(first);
		first = false; //after printing first term, first = false
	}
	cout << endl;
	return;
}

poly poly::operator+(const poly &rhs) {
//Overload for adding 2 polynomials
	poly sum;
	list<term>::reverse_iterator lIter = termList.rbegin();
	list<term>::const_reverse_iterator rIter = rhs.termList.rbegin();

	//Walk the lhs and rhs lists in parallel, from lowest to highest order, building a sum from the combined terms
	while (lIter != termList.rend()|| rIter != rhs.termList.rend())//Continue until the end of both lists have been reached
	{
		if (rIter == rhs.termList.rend() || (*lIter<*rIter) )
		//If the current left term is less than the current right term, or we've reached the end of the right list,
		//Add the left term to the front of the sum
		{
			sum.push_front(*lIter);
			lIter++; //We added a term from the left so increment the left

		} else if (lIter == termList.rend() || (*lIter>*rIter))
		//If the current right term is less than the current left term, or we've reached the end of the left list,
		//Add the right term to the front of the sum
		{
			sum.push_front(*rIter);
			rIter++;//We added a term from the right so increment the right
		} else if (*lIter==*rIter)
		//Left and right terms have equal degree so add them and add to the front
		{
			sum.push_front(*lIter + *rIter);
			lIter++;
			rIter++;
		}
	}
	return sum; //return the resultant sum
};

void poly::push_front(term newTerm) {
//Add a term to the front, but no zero coefficients
	if (newTerm.getCoefficient() == 0){
		return;
	}
	termList.push_front(newTerm);
}; 

void poly::loadExpression(string expression) {
//Given a string expression, load into the list
	int coe, exp;

	polyParser p(expression, "+-");
	while (p.nextTerm(coe, exp)) {
		addTerm(term(coe, exp));
	}
};