#ifndef GENERATOR_H
#define GENERATOR_H

#include <map>
#include <utility>
#include <vector>
#include <set>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using std::map;
using std::vector;
using std::pair;
using std::set;
using std::ostream;

template<typename S>
class Generator {
public:
	Generator() {
		srand(time(NULL)); 
		table = { };
	}

	void init(vector<S> const& items) { 
		table.clear();

		if(items.size() > 2) {
			for(int i = 0; i < items.size() - 2; ++i) {
				auto     prefix = std::make_pair(items[i], items[i + 1]);
				S const& suffix = items[i + 2];

				table[prefix][suffix]++;
			}
		}
	}

	vector<S> generate(int count) {
		auto it = table.begin();

		std::advance(it, rand() % table.size());

		return generate(count, it->first);
	}

	vector<S> generate(int count, pair<S, S> prefix) { 
		vector<S> generated;

		if(table.empty()) 
			return generated;
			
		for(int i = 0; i < count; ++i) {


			// Choose a random suffix for the pair prefix and add it to generator
			auto suffix = choose(table[prefix]);
			generated.push_back(suffix);

			// Set prefix to a pair consisting of the second part of the last 
			// prefix pair and the value just added to the output vector
			prefix = std::make_pair(prefix.second, suffix);
		}

		return generated; 
	}

	void print() {
		for(auto& pair : table) {
			std::cout << pair.first.first << ' ' << pair.first.second;

			std::cout << " : [";

			for(auto const& suffix : pair.second)
				std::cout << suffix.first << ':' << suffix.second << ", ";

			std::cout << ']' << std::endl;
		}
	}

private:
	S choose(map<S, int> const& items) {

		S result;

		int  total  = 0;
		int  rnd    = 0;
		bool chosen = false;

		for(auto const& item : items)
			total+= item.second;

		rnd = rand() % total;

		for(auto& item : items) {
			if(rnd < item.second) {
				result = item.first;
				chosen = true;
				break;
			} else {
				rnd -= item.second;
			}
		}
		
		assert(chosen);
		return result;
	}

	map<pair<S, S>, map<S, int>> table;
};

#endif