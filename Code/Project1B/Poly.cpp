#include "poly.h"
using namespace std;

void term::print(bool firstTerm){
	if (!firstTerm && (coefficient > 0)) {
		cout << '+';
	}
	cout << coefficient;
	if (exponent == 0) {
		return;
	}
	cout << 'X';
	if (exponent != 1) {
		cout << '^' << exponent;
	}
	return;
}

void poly::addTerm(term newTerm) {
	if (newTerm.getCoefficient() == 0) {//Ignore zero coefficient term 
		return;
	}
	if (termList.empty()||(newTerm > termList.front())) {//Highest degree goes to the front
		termList.push_front(newTerm); //push the current at the end
		currentDegree = newTerm.getExponent(); //Current degree is new term's degree
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
		//If we reached the end, push it on the front of the list
		if (iter == termList.end()) {
			termList.push_front(newTerm);
			return;
		}
		//If node exists with matching exponent, just update the coefficient
		else if (*iter == newTerm) {
			iter->updateCoefficient(newTerm.getCoefficient());
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
	bool first = true; //initialize for first term to suppress + if necessary
	for (list<term>::reverse_iterator iter = termList.rbegin(); iter != termList.rend(); iter++) {
		iter->print(first);
		first = false; //after printing first term, first = false
	}
	return;
} //Prints properly formatted polynomial
const poly poly::operator+(const poly &rhs) {
	poly sum;
	//list<term>::reverse_iterator lIter = termList.rbegin();
	//list<term>::reverse_iterator rIter = rhs.termList.rbegin();

	////Walk the lhs and rhs lists in parallel, from lowest to highest order, building a sum from the combined terms
	////while (lIter != termList.rend()|| rIter != rhs.termList.rend())//Continue until the end of both lists have been reached
	//{
	//	if (rIter == rhs.termList.rend() || (*lIter<*rIter) )
	//	//If the current left term is less than the current right term, or we've reached the end of the right list,
	//	//Add the left term to the front of the sum
	//	{
	//		sum.addTerm(*lIter);
	//		lIter++; //We added a term from the left so increment the left

	//	} else if (lIter == termList.rend() || (*rIter<*lIter))
	//	//If the current right term is less than the current left term, or we've reached the end of the left list,
	//	//Add the right term to the front of the sum
	//	{
	//		sum.addTerm(*rIter);
	//		rIter++;//We added a term from the right so increment the right
	//	} else if (*rIter==*lIter)
	//	//Left and right terms have equal degree so add them and add to the front
	//	{
	//		sum.addTerm(*lIter + *rIter);
	//		lIter++;
	//		rIter++;
	//	}
	//}
	return sum; //return the resultant sum
}

void poly::push_front(term newTerm) {
	if (newTerm.getCoefficient() == 0){
		return;
	}
	termList.push_front(newTerm);
}; 

