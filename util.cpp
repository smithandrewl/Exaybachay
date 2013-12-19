#include <string>
#include <vector>
#include <cctype>

#include "util.h"

using std::vector;
using std::string;

vector<string> split(const string& str, const string& delimiters) {
	std::vector<std::string> result;
	
	string::size_type pos1, pos2 = 0;
	
	string word;
	
	pos1 = str.find_first_not_of(delimiters, pos2);
	
	while(pos1 != string::npos) {
		if((pos2 = str.find_first_of(delimiters, pos1)) == string::npos) {
			word = str.substr(pos1);
			pos1 = pos2;
		} else {
		    word = str.substr(pos1, pos2 - pos1);
			pos1 = str.find_first_not_of(delimiters, pos2);
		}
		
		result.push_back(word);
	}
	
	return result;
}

string toLower(const string& str) {
	string result;

	for(char chr : str)
		result.push_back(tolower(chr));

	return result;
}

string toAlphaNumeric(const string& str) {
	string result;

	for(char chr : str)
		if(isalnum(chr))
			result.push_back(chr);

	return result;
}