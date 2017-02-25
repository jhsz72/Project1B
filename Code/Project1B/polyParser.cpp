#include "polyParser.h"
#include <iostream>
using std::string;


void polyParser::findNext(bool firstToken) {
	//Finds the start and end positions of the next term

    // Find the first character that is not a delimeter
	//if this is the first term in the string there may not be a '+' at the beginning 
	//so always start at position zero
	if (firstToken) {
		start = 0;
	}
	else {
		start = polyString.find_first_of(termDelim, end);
	}
	// Find the next delimeter

	//If start wasn't found, don't look for end
	if (start == string::npos) {
		end = start;
	}
	else {
		end = polyString.find_first_of(termDelim, start + 1);
		//if the exponent portion has a + or - sign, we want to skip. 
		//So use ^ as an escape for this
		if ((end != string::npos) && (polyString[end - 1] == '^')) {
			end = polyString.find_first_of(termDelim, end + 1);
		}
	}
}

/** Determine if there are more tokens
    @return true if there are more tokens
*/
bool polyParser::hasMoreTerms() {
  return start != string::npos;
}

/** Retrieve the next token 
    @return the next token. If there are no more
    tokens, an empty string is returned
*/
string polyParser::nextTerm() {
  // Make sure there is a next token
  if (!hasMoreTerms())
    return "";
  // Save the next token in return_value
  string term = polyString.substr(start, end - start);

  // Find the following term
  findNext();
  // Return the next term
  return term;
}

bool polyParser::nextTerm(int &coefficient, int &exponent){
	string token = "";
	string okCoefficients = "+-0123456789"; //Coefficients can only contain these chars
	size_t found = string::npos;
	bool invalid = false;
	string strCoefficient = "";
	string strExponent = "";
	int tokenSize = 0;

	//No more tokens, exit
	if (!hasMoreTerms()) {
		return false;
	}else
	{
		//Get the string value and size of the next token
		token = nextTerm();
		tokenSize = token.size();

		//Look for an 'X' in the tokan
		int i = 0;
		while ((toupper(token[i]) != 'X') && (i < tokenSize)) {
			//Validate each character ip to the X
			found = okCoefficients.find(token[i]);
			if (found == string::npos) {
				throw Syntax_Error("Invalid coefficient value given in " + token);
				return false;
			}
			else {
				i++;
			}
		}
		//Get the string portion from the beginning to the X. This represents the coefficient
		strCoefficient = token.substr(0, i);

		//Blank or + means coefficient of 1
		if ((strCoefficient == "")||(strCoefficient == "+")) {
			coefficient = 1;
		}
		//'-' Means coefficient of -1
		else if (strCoefficient == "-") {
			coefficient = -1;
		}
		//Convert coefficient to integer
		else {
			coefficient = stoi(strCoefficient);
		}

		//i is at the end so no X was present, therefore the exponent was zero
		if (i == (tokenSize)) {
			exponent = 0;
		}
		//i is second to last, therefore the last character is X. Exponent is one
		else if (i == tokenSize - 1) {
			exponent = 1;
		}
		else {
			//Proceed past the X in order to get the numeric exponent
			i++;
			//if the next character is not ^ then this is not proper format
			if (token[i] != '^') {
				throw Syntax_Error("Invalid exponent value given in " + token);
				return false;
			}
			else {
				//Proceed past the ^ to the end. This represents the exponent
				i++;
				strExponent = token.substr(i, tokenSize - i);

				try
				{
					//Convert the exponent to int
					exponent = stoi(strExponent);
				}
				catch (std::exception)
				{
					//It didn't convert so throw an error
					throw Syntax_Error("Invalid exponent value given in " + token);
					return false;
				}
				
			}
		}
		return true;
	}
}