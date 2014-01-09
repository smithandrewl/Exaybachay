#include "textgenerator.h"
#include "util.h"

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;

TextGenerator::TextGenerator(): generator() {}

void TextGenerator::init(string path) {
	ifstream       file(path, std::ios::in);
	string         line;
	vector<string> words;

	while(std::getline(file, line)) {
		for(string word : split(line, " ")) {
			words.push_back(word);
		}

		// restore the newline stripped off by getline
		words.push_back("\n");
	}



	file.close();

	this->init(words);
}

void TextGenerator::init(vector<string> items) {
	generator.init(items);
}

vector<string> TextGenerator::generate(int count) {
	return generator.generate(count);
}
vector<string> TextGenerator::generate(int count, pair<string, string> start) {
	return generator.generate(count, start);
}

void TextGenerator::print() {
	generator.print();
}
