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
struct OccComparator
{
	bool operator()(const std::pair<S, int>& self, const std::pair<S, int> other) {
		return self.second > other.second; 
	}
};

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
				bool     found    = false;
				auto&    suffixes = table[std::make_pair(items[i], items[i + 1])];
				S const& third    = items[i + 2];

				for(auto suffix : suffixes) {
					if(suffix.first == third) {
						found = true;

						suffixes.erase(suffix);
						suffix.second += 1;
						suffixes.insert(suffix);

						break;
					}
				}

				if(!found)
					suffixes.insert(std::make_pair(third, 1));
			}
		}
	}


	vector<S> generate(int count, pair<S, S> start) { 
		vector<S> generated;

		if(!table.empty()) {
			for(int i = 0; i < count; ++i) {

				// Look up the set of suffixes for the pair start
				auto const& suffix = choose(table[start]);
				generated.push_back(suffix);

				// Set start to a pair consisting of the second part of the last 
				// Start pair and the value just added to the output vector
				start = std::make_pair(start.second, suffix);
			}
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
	S choose(set<pair<S, int>, OccComparator<S>> const& items) {

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

	map<pair<S, S>, set<pair<S, int>, OccComparator<S>>> table;
};

#endif