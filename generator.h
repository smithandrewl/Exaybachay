#ifndef GENERATOR_H
#define GENERATOR_H

#include <map>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include "util.h"

using std::map;
using std::vector;
using std::pair;
using std::set;
using std::ostream;
using std::unordered_map;

template<typename S>
class Generator {
public:
	Generator(): unique(), itemIndices(), table() {
		srand(time(NULL)); 
	}

	void init(vector<S> const& items) { 
		table.clear();
		unique.clear();
		itemIndices.clear();

		set<S> itemSet;

		// Build a collection containing every unique item
		for(int i = 0; i< items.size(); ++i)
		    itemSet.insert(items[i]);

		int idx = 0;

		// 1. Add every unique item to "items" at index "idx"
		// 2. Add a mapping from the item to its index in "items"
		for(S item : itemSet) {
		    unique.push_back(item);
		    itemIndices.insert(std::make_pair(item, idx));
		    ++idx;
		}

		if(items.size() > 2) {
			for(int i = 0; i < items.size() - 2; ++i) {
				auto prefix = std::make_pair(itemIndices[items[i]], 
					                         itemIndices[items[i + 1]]);

				int const& suffix = itemIndices[items[i + 2]];

				table[prefix][suffix]++;
			}
		}
	}

	vector<S> generate(int count) {
		auto it = table.begin();

		std::advance(it, rand() % table.size());

		return generate(count, it->first);
	}

	void print() {
		for(auto& pair : table) {
			std::cout << unique[pair.first.first] << ' ' << unique[pair.first.second];

			std::cout << " : [";

			for(auto const& suffix : pair.second)
				std::cout << unique[suffix.first] << ':' << unique[suffix.second] << ", ";

			std::cout << ']' << std::endl;
		}
	}

private:
	vector<S> generate(int count, pair<int, int> prefixIdxs) { 
		vector<S> generated;

		if(table.empty()) 
			return generated;
			
		for(int i = 0; i < count; ++i) {
			// Choose a random suffix for the pair prefix and add it to generator
			int suffix = choose(table[prefixIdxs]);
			generated.push_back(unique[suffix]);

			// Set prefix to a pair consisting of the second part of the last 
			// prefix pair and the value just added to the output vector
			prefixIdxs = std::make_pair(prefixIdxs.second, suffix);
		}

		return generated; 
	}

	int choose(map<int, int> const& items) {
		bool chosen = false;
		int  result = 0;
		int  total  = 0;
		int  rnd    = 0;

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

	vector<S>                          unique;
	unordered_map<S, int>              itemIndices;
	map<pair<int, int>, map<int, int>> table;
};

#endif