#ifndef GENERATOR_H
#define GENERATOR_H

#include <map>
#include <utility>
#include <vector>
#include <queue>

using std::map;
using std::vector;
using std::pair;
using std::priority_queue;

template<typename S>
class Generator {
public:
	Generator() { }
	void init(vector<S> items) { }

	vector<S> generate(int count) { return vector<S>(); }

protected:
	map<pair<S, S>, priority_queue<pair<S, int>>> build(vector<S>) {
		return map<pair<S, S>, priority_queue<pair<S, int>>>();
	}

private:
	map<pair<S, S>, priority_queue<pair<S, int>>> table;

};

#endif