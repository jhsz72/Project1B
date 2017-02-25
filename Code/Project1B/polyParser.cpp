#include "polyParser.h"
#include <iostream>
using std::string;

/** Position start and end so that start is the index of the start
    of the next token and end is the end.
*/
void polyParser::findNext(bool firstToken) {
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
	if (start == string::npos) {
		end = start;
	}
	else {
		end = polyString.find_first_of(termDelim, start + 1);
		//if the exponent has a + or - sign, skip to the next
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
	string okCoefficients = "+-0123456789";
	size_t found = string::npos;
	bool invalid = false;
	string strCoefficient = "";
	string strExponent = "";
	int tokenSize = 0;
	if (!hasMoreTerms()) {
		return false;
	}else
	{
		token = nextTerm();
		tokenSize = token.size();
		int i = 0;
		while ((toupper(token[i]) != 'X') && (i < tokenSize)) {
			found = okCoefficients.find(token[i]);
			if (found == string::npos) {
				throw Syntax_Error("Invalid coefficient value given in " + token);
				return false;
			}
			else {
				i++;
			}
		}
		strCoefficient = token.substr(0, i);
		if ((strCoefficient == "")||(strCoefficient == "+")) {
			coefficient = 1;
		}
		else if (strCoefficient == "-") {
			coefficient = -1;
		}
		else {
			coefficient = stoi(strCoefficient);
		}
		if (i == (tokenSize)) {
			exponent = 0;
		}
		else if (i == tokenSize - 1) {
			exponent = 1;
		}
		else {
			i++;
			if (token[i] != '^') {
				throw Syntax_Error("Invalid exponent value given in " + token);
				return false;
			}
			else {
				i++;
				strExponent = token.substr(i, tokenSize - i);
				exponent = stoi(strExponent);
			}
		}
		return true;
	}
}