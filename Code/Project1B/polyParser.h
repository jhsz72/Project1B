#ifndef POLY_PARSER_H
#define POLY_PARSER_H
#include <string>
#include "Syntax_Error.h"
/** The polynomial parser class splits a string into terms,
	then extracts the coefficient and exponent from each term
*/
class polyParser
{
public:
	/** Constructor
	@param source The string to be split into terms
	@param delim The string containing the delimeters. If
	this parameter is omitted, + and - characters assumed.
	*/
	polyParser(std::string source, std::string delim = "+-") :
		polyString(source), termDelim(delim), start(0), end(0) {
		findNext(true);
	}

	/** Determine if there are more terms
	@return true if there are more terms
	*/
	bool hasMoreTerms();

	/** Retrieve the next term
	@return The coefficient and exponent of the next term. If there are no more terms, an empty
	string is returned.
	*/
	bool nextTerm(int &coefficient, int &exponent);
private:
	std::string nextTerm(); //Returns the string value of the next term

	void findNext(bool firstterm = false);//The first term is created in the constructor event
	/** The string to be split into terms */
	std::string polyString;
	/** The string of delimeters */
	std::string termDelim;
	/** The index of the start of the next term */
	size_t start;
	/** The index of the end of the next term*/
	size_t end;
};

#endif
