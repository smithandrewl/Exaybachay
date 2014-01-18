#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include <string>

#include "generator.h"

class TextGenerator {
public:
	TextGenerator();
	void init(std::string path);
	void init(vector<std::string> items);
	vector<std::string> generate(int count);
	void print();
private:
	Generator<std::string> generator;
};

#endif